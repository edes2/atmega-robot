#pragma once
#include <avr/io.h>
#include <debug.h>
#include<stdlib.h>
#include <util/delay.h> 
#define DEBUG

class JoueurPiezo
{
    public:
    JoueurPiezo();

    void jouerNote(uint8_t note);
    void jouerMegalovania();
    void jouerNokia();
    void silence();

    private:
    double tableauNotes_[37] = {
        9.09, 8.58, 8.10, 7.64, 7.22, 6.81, 6.43, 6.07, 5.73, 5.41, 5.10,
        4.82, 4.55, 4.29, 4.06, 3.82, 3.61, 6.41, 3.21, 3.03, 2.85, 2.70,
        2.55, 2.41, 2.24, 2.15, 2.02, 1.91, 1.80, 1.70, 1.61, 1.52, 1.43,
        1.35, 1.28, 1.20, 1.14
    };
    //62 : D4, 74 : D5, 69: A4, 68: G4#, 67: G4, 65: F4, 60: C4, 59: B3, 58: A#3 
    //Megalovania : 62 62 74 69 68 67 65 62 65 67
    //              60 60 74 69 68 67 65 62 65 67
    //              59 59 74 69 68 67 65 62 65 67
    //              58 58 74 69 68 67 65 62 65 67


 };