#include <avr/io.h>
#include "pwm_lib.h"

PWM::PWM()
{
    DDRD |= _BV(DDD4) | _BV(DDD5);                        //D4 et D5 sont les ports pour minuterie
    TCCR1A |= _BV(0) | _BV(4) | _BV(5) | _BV(6) | _BV(7); //PWM, Phase Correct, 8-bit
                                                          //Set OCnA/OCnB on Compare Match when upcounting. 
                                                          //Clear OCnA/OCnB on Compare Match
                                                          //when downcounting.
    TCCR1B |= _BV(1) | _BV(3) 
    TCCR1C = 0;

    ajustementD4(0.0);
    ajustementD5(0.0);
}

void PWM::ajustementD4(double pourcentage)
{
    uint8_t switchIteration = (1-pourcentage)*255;
    //  Output Compare Register1 A
    OCR1B = switchIteration;
}
void PWM::ajustementD5(double pourcentage)
{
    uint8_t switchIteration = (1-pourcentage)*255;
    // Output Compare Register1 B
    OCR1A = switchIteration;
}