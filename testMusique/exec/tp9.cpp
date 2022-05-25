
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
};