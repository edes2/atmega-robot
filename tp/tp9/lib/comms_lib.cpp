#include "comms_lib.h"

commUART::commUART() {
    // 2400 bauds. Nous vous donnons la valeur des deux
    // premiers registres pour vous éviter des complications.

    UBRR0H = 0;
    UBRR0L = 0xCF;

    // permettre la réception et la transmission par le UART0
    UCSR0A = 0;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0); // pris de la doc code example

    // Format des trames: 8 bits, 1 stop bits, sans parité
    // Bit 5 = 0, Bit 4 = 0, Bit 3 = 0, Bit 2 = 1, Bit 1 = 1,
    UCSR0C = 6;
}

void commUART::transmissionUART(uint8_t donnee){
    while (!(UCSR0A & (1 << UDRE0))) // pris d'un code example
        ;

    UDR0 = donnee;
}

uint8_t commUART::receptionUART(void) 
{
    while (!(UCSR0A & (1 << RXC0))) // pris d'un code example
        ;

    return UDR0;
}



