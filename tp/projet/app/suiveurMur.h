#ifndef SUIVEUR_MUR
#define SUIVEUR_MUR

#define PIN_CAPTEUR 0
#define VITESSE_ROUE_BASE 0.4
#define VITESSE_ROUE_MAX 0.8
#define DISTANCE_MIN 0
#define DISTANCE_IDEALE 20
#define DISTANCE_MAX 40
#define DISTANCE_ABERRANTE 80

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <led_lib.h>
#include <debug.h>

#include "chauffeurdurobot.h"
#include "capteurIR.h"

class SuiveurMur
{
public:
    SuiveurMur(CapteurIR* capteurIR, ChauffeurDuRobot* chauffeur);
    void suivreMur();

private:
    double calculerRoueGauche();
    double calculerRoueDroite();
    ChauffeurDuRobot* margueriteMur_;
    CapteurIR* capteurIR_;
};

#endif