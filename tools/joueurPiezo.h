/* 
This class contains a collection of small songs to play on a piezo buzzer
using a pwm with one of the timers from the atmega324
*/

#ifndef MUSIC_H
#define MUSIC_H

#include <avr/io.h>
#include <debug.h>
#include<stdlib.h>
#include <util/delay.h> 

class JoueurPiezo
{
public:
    JoueurPiezo(); // Init timer/pwm with our current wiring

    void jouerMega();
    void jouerMusique();
    void jouerFurElise();
    void jouerStreetsCairo();
    void jouerNokia();
    void jouerCantina();
    void jouerMusiqueDrDRE();
    

private:
    double tableauNotes_[39] = {10.2 ,9.63,
        9.09, 8.58, 8.10, 7.64, 7.22, 6.81, 6.43, 6.07, 5.73, 5.41, 5.10,
        4.82, 4.55, 4.29, 4.06, 3.82, 3.61, 6.41, 3.21, 3.03, 2.85, 2.70,
        2.55, 2.41, 2.24, 2.15, 2.02, 1.91, 1.80, 1.70, 1.61, 1.52, 1.43,
        1.35, 1.24, 1.20, 1.14
    };

    void jouerNote(uint8_t note);
    void silence();
    
    char buffer_[50];

    //62 : D4, 74 : D5, 69: A4, 68: G4#, 67: G4, 65: F4, 60: C4, 59: B3, 58: A#3 
    //Megalovania : 62 62 74 69 68 67 65 62 65 67
    //              60 60 74 69 68 67 65 62 65 67
    //              59 59 74 69 68 67 65 62 65 67
    //              58 58 74 69 68 67 65 62 65 67


 };

 #endif