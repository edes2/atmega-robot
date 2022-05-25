/* 
Cette classe permet d interpreter le pseudo code se
trouvant dans le dossier progmem (output de ce programme)
*/

#ifndef INTERPRETER_H
#define INTERPRETER_H

#ifndef F_CPU
    #define F_CPU 8000000UL
#endif  

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
#include <driver.h>
#include <joueurPiezo.h>
#include <debug.h>

#include "mnemonic.h"

class InterpreteurInstructions
{
    public:
        InterpreteurInstructions(){};
        void associerCode();
    
    private:
        uint8_t commandes_ = 0x00;
        uint8_t operande_ = 0x00;

};

#endif