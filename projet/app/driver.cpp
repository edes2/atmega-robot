#include "driver.h"

Driver::Driver()
{
    DDRD |= _BV(DDD7) | _BV(DDD6);
}

void Driver::avancer(double pourcentage){
    PORTD &= ~_BV(PA6) & ~_BV(PA7);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void Driver::reculer(double pourcentage){
    PORTD |= _BV(PA6) | _BV(PA7);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void Driver::pivoterAGauche(double pourcentage){
    PORTD |= _BV(PA6);
    PORTD &= ~_BV(PA7);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void Driver::pivoterADroite(double pourcentage){
    PORTD |= _BV(PA7);
    PORTD &= ~_BV(PA6);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void Driver::stop(){
    pwm_.ajustementD4(0.0);
    pwm_.ajustementD5(0.0);
}

void Driver::virage(double pourcentageG, double pourcentageD){
    PORTD &= ~_BV(PA6) & ~_BV(PA7);
    pwm_.ajustementD4(pourcentageG);
    pwm_.ajustementD5(pourcentageD);
}




