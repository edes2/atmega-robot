/*
Programme qui utilise différentes classes et une libraire afin de réaliser un parcours complet.
Le robot suit un parcours specifique, il doit suivre un mur grace a son capteur IR, suivre une lumiere avec 
ses photoresistances et finalement pouvoir reproduire le parcours fait en l enregistrant en memoire externe.
*/

#define F_CPU 8000000
#define ECART_MILIEU 0 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <led_lib.h>
#include <can_lib.h>
#include <interrupts_lib.h>
#include <util/delay.h>

#include <debug.h>
#include <stdio.h>
#include <stdlib.h>

#include "driver.h"
#include "capteurIR.h"
#include "suiveurMur.h"
#include "suiveurLumiere.h"
#include "interpreteurLumiere.h"
#include "enregistrementMem.h"
#include "tools.h"
#include "states.h"

#define RISING_EDGE 3
#define FALLING_EDGE 2
#define DEBOUNCE_DELAY 30
#define BUTTON_D2 4
#define BUTTON_D3 8

// Volatile pour les interruptions/minuteries.
volatile uint8_t gBoutonBlanc = 0;
volatile uint8_t gBoutonInterrupt = 0;
volatile uint8_t gMinuterieExpiree = 0;

ISR (TIMER0_COMPA_vect) 
{
    gMinuterieExpiree = 1;
}

ISR(INT0_vect) // Bouton Interrupt
{
    _delay_ms(DEBOUNCE_DELAY);

    if (((PIND & BUTTON_D2) == BUTTON_D2))
    {
        gBoutonInterrupt = 1;
    }
    EIFR |= (1 << INTF0);
}

ISR(INT1_vect) // Bouton blanc
{
    _delay_ms(DEBOUNCE_DELAY);
    if (((PIND & BUTTON_D3) != BUTTON_D3))
    {
        gBoutonBlanc = 1;
    }
    EIFR |= (1 << INTF1);
}


int main()
{
    Interrupts gestionnaireInterrupts;
    gestionnaireInterrupts.initINT0(RISING_EDGE);
    gestionnaireInterrupts.initINT1(FALLING_EDGE);

    Driver robot;
    LED led(&DDRA, &PORTA, DDA6, DDA7);
    can can;
    CapteurIR capteurIR(&can, PA0);
    SuiveurMur suiveurMur(&capteurIR, &robot);
    InterpreteurLumiere photo1(&can, PA2), photo2(&can, PA3);

    int calibration = (photo1.lectureIntensite() + photo2.lectureIntensite()) / 2;
    SuiveurLumiere capteursPhoto(&robot, calibration+20, ECART_MILIEU+5, ECART_MILIEU-15, ECART_MILIEU+20, ECART_MILIEU-25);
    
    EnregistrementMem* enregistreur = EnregistrementMem::GetInstance();

    Etats etatPresent = Etats::init;

    uint8_t lecture1, lecture2;

    bool ecrireMem = false;
    bool lireMem = false;

    uint8_t temps = 255; // Environ 32ms pour la minuterie
    
    while (true)
    {
        if (ecrireMem==true && gMinuterieExpiree==1)
        {
            enregistreur->enregistrerMouvement();
            gMinuterieExpiree=0;
        }

        if (gMinuterieExpiree == 1 && lireMem==true)
        {
            enregistreur->reproduireMouvement();
            gMinuterieExpiree=0;
        }
        
        switch (etatPresent)
        {
        case Etats::init:
        {
            DEBUG_PRINT("Init \n");
            if (gBoutonInterrupt)
            {
                gBoutonInterrupt = 0;
                etatPresent = Etats::debutParcours;
                ecrireMem = true;
                gMinuterieExpiree=0;
                gestionnaireInterrupts.partirMinuterie0(temps);
            }
            else if (gBoutonBlanc) 
            {
                gBoutonBlanc = 0;
                etatPresent = Etats::debutReprise;
                DEBUG_PRINT("Debut Reprise \n");
                gMinuterieExpiree=0;
                gestionnaireInterrupts.partirMinuterie0(temps);
            }
            break;
        }
        case Etats::debutParcours:
        {
            DEBUG_PRINT("Debut Parcours \n");
            for (int i = 0; i <= 3 * 5; i++)
            {
                led.Vert();
                _delay_ms(100);
                led.Off();
                _delay_ms(100);
            }
            etatPresent = Etats::modeSuivreMur;
            robot.avancer(0.8);
            break;
        }
        case Etats::debutReprise:
        {
            DEBUG_PRINT("Debut Reprise \n");
            for (int i = 0; i <= 3 * 5; i++)
            {
                led.Rouge();
                _delay_ms(100);
                led.Off();
                _delay_ms(100);
            }

            robot.stop();
            ecrireMem=false;
            lireMem = true;
            etatPresent = Etats::modeExecutionEnregistrement;
            break;
        }

        case Etats::modeExecutionEnregistrement:
        {
            DEBUG_PRINT("Debut enregistrement\n");
            if (enregistreur->estFinLecture())
            {
                etatPresent = Etats::finFinal;
                lireMem=false;
            }
            break;
        }

        case Etats::toutDroit:
        {
            DEBUG_PRINT("Tout droit");
            DEBUG_PRINT("\n");
            _delay_ms(800);
            if (5 < capteurIR.mesurerDistance() < DISTANCE_MAX)
            {
                etatPresent = Etats::modeSuivreMur;
            }
            break;
        }

        case Etats::modeSuivreMur:
        {
            DEBUG_PRINT("Suivre Mur");
            suiveurMur.suivreMur();
            if (capteurIR.mesurerDistance() > DISTANCE_MAX)
            {
                robot.stop();
                etatPresent = Etats::attente;
            }
            break;
        }

        case Etats::attente:
        {
            DEBUG_PRINT("Attente \n");
            lecture1 = photo1.lectureIntensite();
            lecture2 = photo2.lectureIntensite();
            int diffIntensite = lecture1 - lecture2;

            if (estLumiereForte(lecture1, lecture2,capteursPhoto.getPuissanceMin()))
            {
                etatPresent = Etats::modeSuivreLumiere;
            }
            else if (gBoutonInterrupt)
            {
                gBoutonInterrupt = 0;
                etatPresent = Etats::finParcours;
                led.Rouge();
                if (ecrireMem)
                {
                    ecrireMem = false;
                    enregistreur->finEnregistrement();

                }
            }
            else if (gBoutonBlanc)
            {
                gBoutonBlanc = 0;
                if (ecrireMem)
                {
                    ecrireMem = false;
                    enregistreur->finEnregistrement();
                }
                etatPresent = Etats::modeVirage;
            }
            break;
        }
        case Etats::modeVirage:
        { 
            DEBUG_PRINT("Mode Virage \n");
            _delay_ms(1000);
            led.Ambre();
            robot.avancer(0.6);
            _delay_ms(1500);
            robot.pivoterADroite(0.53);
            _delay_ms(600);
            robot.avancer(0.6);
            _delay_ms(3000);
            robot.pivoterADroite(0.53);
            _delay_ms(500);
            robot.avancer(0.6);
            _delay_ms(500);

            while(capteurIR.mesurerDistance() > DISTANCE_MAX){
                robot.virage(0.7, 0.4);
            }
            _delay_ms(500);
            etatPresent = Etats::modeSuivreMur;
            break;
        }
        case Etats::finParcours:
        {
            DEBUG_PRINT("Fin Parcours \n");
            robot.stop();
            etatPresent = Etats::finFinal;
            break;
        }

        case Etats::finFinal:
        {
            DEBUG_PRINT("Fin Final \n");
            robot.stop();
            led.Vert();
            break;
        }

        case Etats::modeSuivreLumiere:
        {
            DEBUG_PRINT("Suivre Lumiere \n");
            lecture1 = photo1.lectureIntensite();
            lecture2 = photo2.lectureIntensite();
            if(estLumiereForte(lecture1, lecture2, calibration)){
                capteursPhoto.suivreLumiere(lecture1, lecture2);
            }
            else{
                robot.stop();
            }
            if (5 < capteurIR.mesurerDistance() < DISTANCE_MAX)
            {
                etatPresent = Etats::modeSuivreMur;
            }
            break;
        }
        }
        
    }
    
    return 0;
}