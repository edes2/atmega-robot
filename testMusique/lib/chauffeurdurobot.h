#pragma once
#include<pwm_lib.h>
#include <avr/io.h>

class ChauffeurDuRobot {
    public:
        ChauffeurDuRobot();

        //avancer prend le pourcentage entre 0 et 1
        void avancer(double pourcentage);

        //prend le pourcentage entre 0 et 1
        void reculer(double poucentage);

        //effectue un virage a gauche
        void tournerAGauche(double pourcentage); // virage a 90 : mettre 0.53 et delai de 1 sec

        //effectue un virage a droite
        void tournerADroite(double pourcentage); // virage a 90 : mettre 0.53 et delai de 1 sec

        void stop();
    private:
    PWM pwm;

};