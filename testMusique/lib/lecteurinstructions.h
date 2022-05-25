#pragma once
#include <memoire_lib.h>
#include <led_lib.h>


lecteurInstructions::lecteurInstructions() {
    enum commandes {
    DBT = 0x01;  //Debut
    ATT = 0x02;  //Attendre
    DAL = 0x44;  //Allumer la DEL bicolore
    DET = 0x45;  //Eteindre la DEL bicolore
    MON = 0x18;  //Allumer la matrice de DEL
    MOF = 0x19;  //Eteindre la matrice de DEL
    MAR1 = 0x60; //Arreter les moteurs
    MAR2 = 0x61; //Arreter les moteurs
    MAV = 0x62;  //Avancer
    MRE = 0x63;  //Reculer
    TRD = 0x64;  //Tourner a droite
    TRG = 0x65;  //Tourner a gauche
    DBC = 0xC0;  //Debut de boucle
    FBC = 0xC1;  //Fin de boucle
    FIN = 0xFF;  //Fin
    };
}

void lecteurInstructions::lectureMemoirePuisTraduction() {

    Memoire24CXXX x;  // Mémoire externe  
    LED led(&DDRA, &PORTA, DDA0, DDA1); //LED  

    // variables
    uint16_t lectureAct = 0x00;
    uint16_t tailleFichier;
    uint8_t commandes;
    uint8_t operande;
    
    // regarder la taille du fichier
    x.lecture(lectureAct, &commandes);
    lectureAct++;
    tailleFichier = commandes;

    // lecture de la commande
    x.lecture(lectureAct, &commandes);
    lectureAct++;

    // 8 bits du début -> MSB
    tailleFichier = (tailleFichier << 8) + commandes;

    // Vérification de la lecture (comme indiqué sur le site web)
    led.Rouge();
    _delay_ms(1000);
    DEBUG_PRINT("Comme sur des roulettes\n");
    led.Off();

    //Traduire binaire sur le fichier en commande

    while (lectureAct < fileSize) {
    // Lecture commandes + operande
        x.lecture(lectureAct, &commandes);
        lectureAct++;

        x.lecture(lectureAct, &operande);
        lectureAct++;


        bool debut = false
        if (commandes == DBT) {
            debut = true
            DEBUG_PRINT("C'est parti mon kiki \n");
        }


        if (debut) {
            switch (commandes) {
                case ATT:
                    DEBUG_PRINT("Rien ne se passe\n");
                break;

                case DAL:
                    DEBUG_PRINT("VERT !\n");
                    led.Vert();
                break;


                // ON continue comme ca pour chaque commande, je le ferais quand vous aurez validé le squelette de mon code

            }

        }

    }
}







