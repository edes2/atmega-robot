#include <avr/io.h>
#include <avr/interrupt.h>
#include "interrupts_lib.h"

//0 low level, 1 any edge, 2 falling edge, 3 rising edge
//UTILISE LA PIN D2, MAIS PEUT ETRE CONFIGURE SUR D3 AUSSI
Interrupts::Interrupts() {};
void Interrupts::initINT0(uint8_t edgeType)
{
    cli();
    DDRD &= ~_BV(DDD2);

    EIMSK |= (1 << INT0);

    // ISC01 et ISC00 sont les bits a configurer dans EICRA

    if (edgeType == 0)
    {
        EICRA &= ~_BV(ISC00);
        EICRA &= ~_BV(ISC01);
    }
    else if (edgeType == 1)
    {
        EICRA |= _BV(ISC00);
    }
    else if (edgeType == 2)
    {
        EICRA |= _BV(ISC01);
    }
    else if (edgeType == 3)
    {
        EICRA |= _BV(ISC01) | _BV(ISC00);
    }

    sei();
};

//0 low level, 1 any edge, 2 falling edge, 3 rising edge,
//UTILISE LA PIN D3, MAIS PEUT ETRE CONFIGUREE SUR D2 AUSSI
void Interrupts::initINT1(uint8_t edgeType)
{
    cli();
    DDRD &= ~_BV(DDD3);

    EIMSK |= (1 << INT1);

    // ISC11 et ISC10 sont les bits a configurer dans EICRA

    if (edgeType == 0)
    {
        EICRA &= ~_BV(ISC10);
        EICRA &= ~_BV(ISC11);
    }
    else if (edgeType == 1)
    {
        EICRA |= _BV(ISC10);
    }
    else if (edgeType == 2)
    {
        EICRA |= _BV(ISC11);
    }
    else if (edgeType == 3)
    {
        EICRA |= _BV(ISC11) | _BV(ISC10);
    }

    sei();
};

//0 low level, 1 any edge, 2 falling edge, 3 rising edge,
//UTILISE LA PIN B3
void Interrupts::initINT2(uint8_t edgeType)
{
    cli();
    DDRB &= ~_BV(DDB2);

    EIMSK |= (1 << INT2);

    // ISC21 et ISC20 sont les bits a configurer dans EICRA

    if (edgeType == 0)
    {
        EICRA &= ~_BV(ISC20);
        EICRA &= ~_BV(ISC21);
    }
    else if (edgeType == 1)
    {
        EICRA |= _BV(ISC20);
    }
    else if (edgeType == 2)
    {
        EICRA |= _BV(ISC21);
    }
    else if (edgeType == 3)
    {
        EICRA |= _BV(ISC21) | _BV(ISC20);
    }

    sei();
};

