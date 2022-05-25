#define F_CPU 8000000 //F_CPU doit etre avant include sinon bug

#include <memoire_lib.h>
#include <comms_lib.h>
#include <avr/io.h>
#include <debug.h>
#include <util/delay.h>
#include <debug.h>
// 2 INCLUDES A FAIRE POUR DEBUG_PRINT UN INT
#include <stdio.h>
#include <stdlib.h>

int main() {
    Memoire24CXXX mem;
    uint8_t donnee;
    uint16_t adresse=0x0000;
    uint16_t longueur;
    char buffer[50]; // buffer pour debug print des int.

    while(true) {
        mem.lecture(adresse, &donnee);
        _delay_ms(5);

        if (donnee==0x01) {
            break;
        }
        adresse+=2; // On cherche slm l'isntruction dbt (il faut commencer à un adresse pair)
    }

    adresse-=2; // La longueur se trouve deux instructions avant.

    uint8_t longueurH;
    uint8_t longueurL;
    mem.lecture(adresse, &longueurH);
    adresse++;
    _delay_ms(5);
    mem.lecture(adresse, &longueurL);
    adresse++;
    _delay_ms(5);
    longueur = (longueurH << 8) | longueurL;

    
    itoa(longueur, buffer, 16);
    DEBUG_PRINT(("Longueur (en hex): "));
    DEBUG_PRINT((buffer));
    DEBUG_PRINT(("\n"));

    

    // On a la longueur, commencer a tt print.
    DEBUG_PRINT(("Begin\n"));
    //_delay_ms(5);
    for (int i=adresse;i<longueur;i++) {
        mem.lecture(i, &donnee);
        _delay_ms(5);
        //char buffer[50];
        itoa(donnee, buffer, 16);
        //_delay_ms(5);
        DEBUG_PRINT((buffer));
        //_delay_ms(10); // Qd on met le délai à 5 print marche pas??
        DEBUG_PRINT(("\n"));
        //_delay_ms(5);
    }
    DEBUG_PRINT(("End\n"));
}