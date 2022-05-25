#include "chauffeurdurobot.h"


ChauffeurDuRobot::ChauffeurDuRobot()
{
    DDRD |= _BV(DDD7) | _BV(DDD6);
}

void ChauffeurDuRobot::avancer(double pourcentage){
    PORTD &= ~_BV(PA6) & ~_BV(PA7);
    pwm.ajustementD4(pourcentage);
    pwm.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::reculer(double pourcentage){
    PORTD |= _BV(PA6) | _BV(PA7);
    pwm.ajustementD4(pourcentage);
    pwm.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::tournerAGauche(double pourcentage){
    PORTD |= _BV(PA6);
    PORTD &= ~_BV(PA7);
    pwm.ajustementD4(pourcentage);
    pwm.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::tournerADroite(double pourcentage){
    PORTD |= _BV(PA7);
    PORTD &= ~_BV(PA6);
    pwm.ajustementD4(pourcentage);
    pwm.ajustementD5(pourcentage);
}

void ChauffeurDuRobot::stop(){
    pwm.ajustementD4(0.0);
    pwm.ajustementD5(0.0);
}





