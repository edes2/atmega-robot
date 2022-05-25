#pragma once
#include <avr/io.h>
class LED {
public:
    LED(volatile uint8_t* port, volatile uint8_t* pin, int pin1, int pin2);

    void Rouge();
    void Vert();
    void Off();
private:
    volatile uint8_t* port_;
    volatile uint8_t* pin_;
    int pin1_;
    int pin2_;
};