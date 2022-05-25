#include "interrupts_lib.h"
#include <avr/interrupt.h>


Interrupts::Interrupts() {};

void Interrupts::partirMinuterie0(uint8_t duree)
{
    cli();
    // mode CTC du timer 1 avec horloge divisée par 1024
    // interruption après la durée spécifiée
    // Timer/Counter1
    TCNT0 = 0 ;
    OCR0A = duree;

    TCCR0A |= _BV(WGM01);

    TCCR0B |= _BV(CS02) | _BV(CS00);

    TIMSK0 |= _BV(OCIE0A) ;
    sei();
};

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

void Interrupts::initINT1(uint8_t edgeType)
{
    cli();
    DDRD &= ~_BV(DDD3);

    EIMSK |= (1 << INT1);

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

void Interrupts::initINT2(uint8_t edgeType)
{
    cli();
    DDRB &= ~_BV(DDB2);

    EIMSK |= (1 << INT2);

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

