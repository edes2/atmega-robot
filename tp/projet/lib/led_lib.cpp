#include "led_lib.h"
#include <util/delay.h>

LED::LED(volatile uint8_t* port, volatile uint8_t* pin, int pin1, int pin2) : port_(port),
pin_(pin), pin1_(pin1), pin2_(pin2)
{
    *port |= _BV(pin1_) | _BV(pin2_);
}

void LED::Rouge()
{
    *pin_ &= ~_BV(pin1_);
    *pin_ |= _BV(pin2_);
}

void LED::Vert()
{
    *pin_ |= _BV(pin1_);
    *pin_ &= ~_BV(pin2_);
}

void LED::Off()
{
    *pin_ &= ~_BV(pin1_) & ~_BV(pin2_);
}

void LED::Ambre()
{
    Rouge();
    _delay_ms(10);
    Vert();
    _delay_ms(10);
    
}



