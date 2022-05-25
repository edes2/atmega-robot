#include "chauffeurdurobot.h"

ChauffeurDuRobot::ChauffeurDuRobot()
{
    DDRD |= _BV(DDD7) | _BV(DDD6);
}

void ChauffeurDuRobot::avancer(double pourcentage){
    PORTD &= ~_BV(PA6) & ~_BV(PA7);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::reculer(double pourcentage){
    PORTD |= _BV(PA6) | _BV(PA7);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::pivoterAGauche(double pourcentage){
    PORTD |= _BV(PA6);
    PORTD &= ~_BV(PA7);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::pivoterADroite(double pourcentage){
    PORTD |= _BV(PA7);
    PORTD &= ~_BV(PA6);
    pwm_.ajustementD4(pourcentage);
    pwm_.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::stop(){
    pwm_.ajustementD4(0.0);
    pwm_.ajustementD5(0.0);
}

void ChauffeurDuRobot::virage(double pourcentageG, double pourcentageD){
    PORTD &= ~_BV(PA6) & ~_BV(PA7);
    pwm_.ajustementD4(pourcentageG);
    pwm_.ajustementD5(pourcentageD);
}




