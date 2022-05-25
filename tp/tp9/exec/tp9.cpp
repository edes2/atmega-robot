
#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <led_lib.h>
#include <pwm_lib.h>
#include <can_lib.h>
#include <interrupts_lib.h>
#include <memoire_lib.h>
#include <comms_lib.h>
#include <string.h>
#include <debug.h>
#include <util/delay.h>

#include <../lib/chauffeurdurobot.cpp>
#include <../lib/joueurPiezo.cpp>
#include <../lib/interpreteurinstruction.cpp>

// 2 INCLUDES A FAIRE POUR DEBUG_PRINT UN INT
#include <stdio.h>
#include <stdlib.h> 

int main(){
    
    JoueurPiezo musique;
    //InterpreteurInstructions interpreteur;
    //interpreteur.associerCode();
<<<<<<< HEAD
    musique.jjouerCantina();
=======
    ChauffeurDuRobot robot;
    robot.tournerADroite(0.5);
    musique.jouerMusiqueDrDRE();
>>>>>>> fdf5e8eb587f37735ad916abd55f018d9b874d71
    musique.silence();
    /*DDRB=0xFF;
    while(true){
        PORTB = 0x08;
        _delay_ms(4);
        PORTB=0x00;
        _delay_ms(4);
    }
    */
}
