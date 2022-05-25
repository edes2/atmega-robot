#ifndef LED_H
#define LED_H
#include <avr/io.h>

class LED {
public:
    LED(volatile uint8_t* port, volatile uint8_t* pin, int pin1, int pin2);
    // Permet de rentrer directement le port sur laquelle la led/del est branchee.

    void Rouge();
    void Vert();
    void Off();
    void Ambre();
private:
    volatile uint8_t* port_;
    volatile uint8_t* pin_;
    int pin1_;
    int pin2_;
};

#endif