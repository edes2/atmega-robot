#ifndef F_CPU
    #define F_CPU 8000000UL
#endif  
#include "debug.h"
#include <util/delay.h>
#include "comms_lib.h"



commUART uart; // Qd on le déclare à l'intérieur bug.
void transmission(char* x) { // Prend un char[] en entrée
               // On peut convertir en char avec itoa
    for(uint8_t i = 0; i < strlen(x); i++)    
    {             
        uart.transmissionUART(x[i]);
    }
    //_delay_ms(10);
}