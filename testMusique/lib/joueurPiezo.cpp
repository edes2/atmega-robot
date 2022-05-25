#include "joueurPiezo.h"

JoueurPiezo::JoueurPiezo()
{ // Utilise le port PB3 donc B4 sur le robot et le timer 0

    //timer ctc + initialisation d'un port pour le signal
    DDRB |= _BV(DDB3) | _BV(DDB2);

    TCNT0 = 0;
    TCCR0A |= _BV(WGM01); //mode CTC,
    //TCCR0A |= _BV(6) | _BV(1); //mode CTC, toggle OC0A on compare match
    TCCR0B |= _BV(CS02);
    //TCCR0B |= _BV(2);

    // prescaler = 256, donc 0.032 ms/iteration, 8.16ms max.
    //DEBUG_PRINT("Joueur Piezo a ete construit");
}

void JoueurPiezo::jouerNote(uint8_t note)
{
    TCCR0A |= _BV(COM0A0); // toggle OC0A on compare match
    //TCCR0A |= _BV(6);
    double periode = tableauNotes_[note - 45];

    char buffer[30];
    DEBUG_PRINT(("jouerNote: \n"));
    itoa(periode*1000, buffer, 10);
    DEBUG_PRINT(buffer);
    DEBUG_PRINT(("\n"));
    // convertit la periode en une valeur sur 255
    uint8_t dureeConvertie = ((periode * 255) / 8.16)/2;

    char buffer2[30];
    itoa(dureeConvertie, buffer2, 10);
    DEBUG_PRINT(buffer2);

    OCR0A = dureeConvertie;
}

void JoueurPiezo::silence()
{
    TCCR0A &= ~_BV(COM0A0);
    
}

void JoueurPiezo::jouerMegalovania(){
    //Megalovania : 62 62 74 69 68 67 65 62 65 67
    //              60 60 74 69 68 67 65 62 65 67
    //              59 59 74 69 68 67 65 62 65 67
    //              58 58 74 69 68 67 65 62 65 67
    // 120 bpm : ronde : 2000ms, blanche : 1000ms, 
    //noire : 500ms, croche : 250, double-croche : 125

    jouerNote(62);
    _delay_ms(100);

    silence();
    _delay_ms(25);
    

    jouerNote(62);
    _delay_ms(125);
    

    jouerNote(74); //staccato
    _delay_ms(250);

    jouerNote(69); //staccato
    _delay_ms(250);

    silence();
    _delay_ms(125);

    jouerNote(68);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(250);

    jouerNote(62);
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);

    //

    jouerNote(60);
    _delay_ms(100);

    silence();
    _delay_ms(25);
    

    jouerNote(60);
    _delay_ms(125);
    

    jouerNote(74); //staccato
    _delay_ms(250);

    jouerNote(69); //staccato
    _delay_ms(250);

    silence();
    _delay_ms(125);

    jouerNote(68);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(250);

    jouerNote(62);
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);

    //

    jouerNote(59);
    _delay_ms(100);

    silence();
    _delay_ms(25);
    

    jouerNote(59);
    _delay_ms(125);
    

    jouerNote(74); //staccato
    _delay_ms(250);

    jouerNote(69); //staccato
    _delay_ms(250);

    silence();
    _delay_ms(125);

    jouerNote(68);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(250);

    jouerNote(62);
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);

    //

    jouerNote(58);
    _delay_ms(100);

    silence();
    _delay_ms(25);
    

    jouerNote(58);
    _delay_ms(125);
    

    jouerNote(74); //staccato
    _delay_ms(250);

    jouerNote(69); //staccato
    _delay_ms(250);

    silence();
    _delay_ms(125);

    jouerNote(68);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);

    silence();
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(250);

    jouerNote(62);
    _delay_ms(125);

    jouerNote(65);
    _delay_ms(125);

    jouerNote(67);
    _delay_ms(125);


}

void JoueurPiezo::jouerNokia(){
    //Nokia : 76 74 66 68 | 73 71 62 64 | 71 69 61 64
    //        69 silence 
    // 180 bpm : ronde : 1332ms, blanche : 666ms, 
    //noire : 333ms, croche : 167, double-croche : 86

    jouerNote(76);
    _delay_ms(140);
    silence();
    _delay_ms(27);
    

    jouerNote(74);
    _delay_ms(140);
     silence();
    _delay_ms(27);

    jouerNote(66);
    _delay_ms(310);
    silence();
    _delay_ms(23);
    
    jouerNote(68);
    _delay_ms(310);
    silence();
    _delay_ms(23);
    
// --------------------------------------------------------------------------------------------------------
    jouerNote(73);
    _delay_ms(140);
     silence();
    _delay_ms(27);

    jouerNote(71);
    _delay_ms(140);
    silence();
    _delay_ms(27);
    

    jouerNote(62);
    _delay_ms(310);
     silence();
    _delay_ms(23);

    jouerNote(64);
    _delay_ms(310);
    silence();
    _delay_ms(23);
    
    
// --------------------------------------------------------------------------------------------------------

    jouerNote(71);
    _delay_ms(140);
    silence();
    _delay_ms(27);
    

    jouerNote(69);
    _delay_ms(140);
     silence();
    _delay_ms(27);

    jouerNote(61);
    _delay_ms(310);
    silence();
    _delay_ms(23);
    
    jouerNote(64);
    _delay_ms(310);
    silence();
    _delay_ms(23);

    jouerNote(69);
    _delay_ms(666);
    silence();
    _delay_ms(333);
}


