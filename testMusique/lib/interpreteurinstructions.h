#pragma once
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <led_lib.h>
#include <pwm_lib.h>
#include <can_lib.h>
#include <interrupts_lib.h>
#include <memoire_lib.h>
#include<comms_lib.h>
#include<string.h>
#include<debug.h>
#include<chauffeurdurobot.h>
#include<joueurPiezo.h>

#ifndef F_CPU
    #define F_CPU 8000000UL
#endif  

class InterpreteurInstructions
{
    public:
        InterpreteurInstructions(){};
        void associerCode();
    
    private:
        uint8_t commandes = 0x00;
        uint8_t operande = 0x00;

};