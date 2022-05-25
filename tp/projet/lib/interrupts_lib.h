#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#include <avr/io.h>

//0 low level, 1 any edge, 2 falling edge, 3 rising edge
class Interrupts
{
public:
    Interrupts();

    // Differentes configurations
    void initINT0(uint8_t edgeType);
    void initINT1(uint8_t edgeType);
    void initINT2(uint8_t edgeType);
    void partirMinuterie0(uint8_t duree); // Timer CTC
};

#endif