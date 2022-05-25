#ifndef COMMS_H
#define COMMS_H

#include <avr/io.h>

class commUART
{
public:
    commUART();

    void transmissionUART(uint8_t donnee);
    uint8_t receptionUART(void);
};
#endif