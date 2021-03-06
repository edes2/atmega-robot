#include "joueurPiezo.h"

JoueurPiezo::JoueurPiezo()
{

    DDRB |= _BV(DDB3) | _BV(DDB2);

    TCNT0 = 0;
    TCCR0A |= _BV(WGM01); // CTC,
    TCCR0B |= _BV(CS02);

}

void JoueurPiezo::jouerNote(uint8_t note)
{
    TCCR0A |= _BV(COM0A0); // toggle OC0A on compare match

    double periode = tableauNotes_[note - 43];

    DEBUG_PRINT(("jouerNote: \n"));
    itoa(periode * 1000, buffer_, 10);
    DEBUG_PRINT(buffer_);
    DEBUG_PRINT(("\n"));

    uint8_t dureeConvertie = ((periode * 255) / 8.16)/2;

    itoa(dureeConvertie, buffer_, 10);
    DEBUG_PRINT(buffer_);

    OCR0A = dureeConvertie;
}

void JoueurPiezo::silence()
{
    TCCR0A &= ~_BV(COM0A0);
    
}

void JoueurPiezo::jouerMega(){
    // Megalovania : 62 62 74 69 68 67 65 62 65 67
    //               60 60 74 69 68 67 65 62 65 67
    //               59 59 74 69 68 67 65 62 65 67
    //               58 58 74 69 68 67 65 62 65 67
    // 120 bpm : ronde : 2000ms, blanche : 1000ms, 
    // noire : 500ms, croche : 250, double-croche : 125

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

    silence();
}


void JoueurPiezo::jouerMusique(){
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

    silence();
}
/// FUR ELISE
void JoueurPiezo::jouerFurElise(){

    jouerNote(76);
     _delay_ms(500);

    jouerNote(75);
     _delay_ms(500);   

    jouerNote(76);
     _delay_ms(500);

    jouerNote(75);
     _delay_ms(500); 

    jouerNote(76);
     _delay_ms(500);

    //jouerNote(83);
    // _delay_ms(500);

    jouerNote(74);
     _delay_ms(500);

    jouerNote(72);
     _delay_ms(500);

    jouerNote(81);
     _delay_ms(500);   

    jouerNote(72);
     _delay_ms(250);

    jouerNote(76);
     _delay_ms(500);

    jouerNote(81);
     _delay_ms(500);


}
/// STREETS OF CAIRO
void JoueurPiezo::jouerStreetsCairo(){

    jouerNote(76);
     _delay_ms(283);

    jouerNote(77);
     _delay_ms(283);   

    jouerNote(79);
     _delay_ms(566);

    jouerNote(77);
     _delay_ms(283); 

    jouerNote(77);
     _delay_ms(283);

    jouerNote(76);
     _delay_ms(566);

    jouerNote(76);
     _delay_ms(283);

    jouerNote(77);
     _delay_ms(283);   

    jouerNote(79);
     _delay_ms(283);

    jouerNote(83);
     _delay_ms(283);

    jouerNote(77);
     _delay_ms(283);   

    jouerNote(79);
     _delay_ms(283);

    jouerNote(76);
     _delay_ms(566);

    jouerNote(76);
     _delay_ms(283);

    jouerNote(77);
     _delay_ms(283);   

    jouerNote(79);
     _delay_ms(566);

    jouerNote(77);
     _delay_ms(566);

     jouerNote(76);
     _delay_ms(566);

    jouerNote(76);
     _delay_ms(283);

    jouerNote(77);
     _delay_ms(283);   

    jouerNote(79);
     _delay_ms(283);

    jouerNote(83);
     _delay_ms(283);

    jouerNote(77);
     _delay_ms(283);   

    jouerNote(79);
     _delay_ms(283);

    jouerNote(76);
     _delay_ms(566);


}
// nokia ringtone
void JoueurPiezo::jouerNokia(){
    jouerNote(76);
     _delay_ms(168);

    jouerNote(74);
     _delay_ms(168);   

    jouerNote(78);
     _delay_ms(335);

    jouerNote(80);
     _delay_ms(335); 

    jouerNote(73);
     _delay_ms(168);

    jouerNote(83);
     _delay_ms(168);

    jouerNote(74);
     _delay_ms(335);

    jouerNote(76);
     _delay_ms(335);

    jouerNote(83);
     _delay_ms(168);   

    jouerNote(81);
     _delay_ms(168);

    jouerNote(80);
     _delay_ms(335);

    jouerNote(75);
     _delay_ms(335);

    jouerNote(81);
     _delay_ms(670);

}
// cantina
void JoueurPiezo::jouerCantina(){

    jouerNote(71);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);
    
    jouerNote(71);
    _delay_ms(134);
  
    silence();
    _delay_ms(134);

    jouerNote(70);
    _delay_ms(134);
    
    jouerNote(71);
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);
    
    jouerNote(70);
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);
    
    jouerNote(69);
    _delay_ms(134);
  
    silence();
    _delay_ms(134);

    jouerNote(68);
    _delay_ms(134);

    jouerNote(69);
    _delay_ms(134);
    
    jouerNote(67);
    _delay_ms(134);

    jouerNote(67);
    _delay_ms(268);

    jouerNote(64);
    _delay_ms(536);

    jouerNote(71);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);
    
    jouerNote(71);
    _delay_ms(134);
  
    silence();
    _delay_ms(134);

    jouerNote(70);
    _delay_ms(134);
    
    jouerNote(71);
    _delay_ms(134);

    jouerNote(69);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(69);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(68);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(69);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(74);
    _delay_ms(134);

    jouerNote(72);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);
    
    jouerNote(71);
    _delay_ms(134);


    jouerNote(69);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);
    
    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);

    silence();
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(70);
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(134);

    jouerNote(74);
    _delay_ms(134);

    jouerNote(74);
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(268);

    jouerNote(69);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);
    
    jouerNote(67);
    _delay_ms(134);


    jouerNote(64);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(64);
    _delay_ms(134);
    
    silence();
    _delay_ms(167);

    jouerNote(67);
    _delay_ms(268);

    silence();
    _delay_ms(268);

    jouerNote(71);
    _delay_ms(536);

    jouerNote(74);
    _delay_ms(536);

    jouerNote(76);
    _delay_ms(536);
    
    jouerNote(71);
    _delay_ms(536);
    
    jouerNote(78);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);

    jouerNote(76);
    _delay_ms(134);
    
    silence();
    _delay_ms(134);
    
    jouerNote(70);
    _delay_ms(134);
    
    jouerNote(70);
    _delay_ms(134);

    jouerNote(71);
    _delay_ms(268);

    jouerNote(67);
    _delay_ms(268);

    silence();
    _delay_ms(134);
    
    silence();
    _delay_ms(134);



}

void JoueurPiezo::jouerDrDRE(){

    //60 bpm : noire : 1000ms, croche : 500 ms, double croche : 250ms, triolet : 333ms

    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet
    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet
    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet
    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet
    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet
    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet
    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet
    jouerNote(55);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(60);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    jouerNote(63);
    _delay_ms(300);
    silence();
    _delay_ms(33);

    //triolet legato ---------------------------
    jouerNote(56);
    _delay_ms(333);

    jouerNote(60);
    _delay_ms(333);
   

    jouerNote(63);
    _delay_ms(333);

     //triolet
    jouerNote(56);
    _delay_ms(333);

    jouerNote(60);
    _delay_ms(333);
   

    jouerNote(63);
    _delay_ms(333);

     //triolet
    jouerNote(56);
    _delay_ms(333);

    jouerNote(60);
    _delay_ms(333);
   

    jouerNote(65);
    _delay_ms(333);
     //triolet
    jouerNote(56);
    _delay_ms(333);

    jouerNote(60);
    _delay_ms(333);
   
    jouerNote(65);
    _delay_ms(333);

     //triolet -----------------------------------------
    jouerNote(56);
    _delay_ms(333);

    jouerNote(59);
    _delay_ms(333);
   
    jouerNote(65);
    _delay_ms(333);

//triolet
    jouerNote(56);
    _delay_ms(333);

    jouerNote(59);
    _delay_ms(333);
   
    jouerNote(64);
    _delay_ms(333);

//triolet
    jouerNote(56);
    _delay_ms(333);

    jouerNote(59);
    _delay_ms(333);
   
    jouerNote(62);
    _delay_ms(333);


//triolet
    jouerNote(43);
    _delay_ms(333);

    jouerNote(47);
    _delay_ms(333);

   
    jouerNote(62);
    _delay_ms(333);



//triolet -----------------------------------------
    jouerNote(57);
    _delay_ms(333);

    jouerNote(60);
    _delay_ms(333);

   
    jouerNote(64);
    _delay_ms(333);

//triolet


    jouerNote(60);
    _delay_ms(333);

   
    jouerNote(64);
    _delay_ms(333);

    jouerNote(69);
    _delay_ms(333);

//triolet 

    jouerNote(64);
    _delay_ms(333);
   
    jouerNote(69);
    _delay_ms(333);

    jouerNote(72);
    _delay_ms(333);

//triolet 
   
    jouerNote(69);
    _delay_ms(333);

    jouerNote(72);
    _delay_ms(333);

    jouerNote(76);
    _delay_ms(333);

//triolet ---------------------------------

    jouerNote(72);
    _delay_ms(333);

    jouerNote(76);
    _delay_ms(333);

    jouerNote(81);
    _delay_ms(333);

//triolet 

    jouerNote(72);
    _delay_ms(250);

    jouerNote(76);
    _delay_ms(250);

    jouerNote(81);
    _delay_ms(250);

//triolet 

    jouerNote(72);
    _delay_ms(250);

    jouerNote(76);
    _delay_ms(250);

    jouerNote(81);
    _delay_ms(250);

//triolet 

    jouerNote(72);
    _delay_ms(200);

    jouerNote(76);
    _delay_ms(200);

    jouerNote(81);
    _delay_ms(200);

    //triolet ----------------------------------------

    jouerNote(72);
    _delay_ms(166);

    jouerNote(76);
    _delay_ms(166);

    jouerNote(81);
    _delay_ms(166);

    //triolet

    jouerNote(72);
    _delay_ms(166);

    jouerNote(76);
    _delay_ms(166);

    jouerNote(81);
    _delay_ms(166);

    //triolet

    jouerNote(72);
    _delay_ms(133);

    jouerNote(76);
    _delay_ms(133);

    jouerNote(81);
    _delay_ms(133);

    //triolet

    jouerNote(72);
    _delay_ms(133);

    jouerNote(76);
    _delay_ms(133);

    jouerNote(81);
    _delay_ms(133);

    //triolet ---------------------------------------

    jouerNote(72);
    _delay_ms(111);

    jouerNote(76);
    _delay_ms(111);

    jouerNote(81);
    _delay_ms(111);

     //triolet 

    jouerNote(72);
    _delay_ms(111);

    jouerNote(76);
    _delay_ms(111);

    jouerNote(81);
    _delay_ms(111);

    //triolet 

    jouerNote(72);
    _delay_ms(95);

    jouerNote(76);
    _delay_ms(95);

    jouerNote(81);
    _delay_ms(95);

    //triolet 

    jouerNote(72);
    _delay_ms(95);

    jouerNote(76);
    _delay_ms(95);

    jouerNote(81);
    _delay_ms(95);

    //triolet ---------------------------------

    jouerNote(72);
    _delay_ms(83);

    jouerNote(76);
    _delay_ms(83);

    jouerNote(81);
    _delay_ms(83);

//triolet 

    jouerNote(72);
    _delay_ms(71);

    jouerNote(76);
    _delay_ms(71);

    jouerNote(81);
    _delay_ms(71);

    //triolet 

    jouerNote(72);
    _delay_ms(71);

    jouerNote(76);
    _delay_ms(71);

    jouerNote(81);
    _delay_ms(71);

    //triolet 

    jouerNote(72);
    _delay_ms(71);

    jouerNote(76);
    _delay_ms(71);

    jouerNote(81);
    _delay_ms(71);

    //triolet -----------------------------

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

        //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

        //triolet -----------------------------

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

        //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet -----------------------------

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

    //triolet -----------------------------------

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

        //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

        //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

        //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

     //triolet -----------------------------

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

        //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

        //triolet -----------------------------

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

        //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(72);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet -----------------------------

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(81);
    _delay_ms(273);

    //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

    //triolet -----------------------------------

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

        //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

        //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);

        //triolet 

    jouerNote(71);
    _delay_ms(30);

    jouerNote(76);
    _delay_ms(30);

    jouerNote(79);
    _delay_ms(273);
   
 }