
#include "debug.h"
#include "comms_lib.h"

//commUART uart; // Doit etre declare a l exterieur de la fonction.
void transmission(char* x) {
    int i = 0;
    while (x[i]!=0){
        //uart.transmissionUART(x[i]);
        while (!(UCSR0A & (1 << UDRE0))) // pris d'un exemple
            ;
        UDR0 = x[i];
        i++;
    }
}
