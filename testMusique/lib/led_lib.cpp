#include <avr/io.h>
#include "led_lib.h"

LED::LED(volatile uint8_t* port, volatile uint8_t* pin, int pin1, int pin2) : port_(port),
pin_(pin), pin1_(pin1), pin2_(pin2)
{
    *port |= _BV(pin1_) | _BV(pin2_);
};

void LED::Rouge()
{
    *pin_ &= ~_BV(pin1_);
    *pin_ |= _BV(pin2_);
};

void LED::Vert()
{
    *pin_ |= _BV(pin1_);
    *pin_ &= ~_BV(pin2_);
};

void LED::Off()
{
    *pin_ &= ~_BV(pin1_) & ~_BV(pin2_);
}