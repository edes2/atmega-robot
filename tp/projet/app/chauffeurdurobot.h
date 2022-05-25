#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H
#include <pwm_lib.h>
#include <avr/io.h>

class ChauffeurDuRobot {
public:
    ChauffeurDuRobot();

    void avancer(double pourcentage);

    void reculer(double poucentage);

    void pivoterAGauche(double pourcentage);

    void pivoterADroite(double pourcentage);

    void virage(double pourcentageGauche, double pourcentageDroite); 

    void stop();
private:
    PWM pwm_;

};
#endif