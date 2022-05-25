#ifndef SUIVEURLUM_H
#define SUIVEURLUM_H

#define AVANCER_MAX 235
#define INTENSITE_PIVOT 0.6
#define INTENSITE_ROUE_SUPPORT_VIRAGE 0.5

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "interpreteurLumiere.h"
#include "driver.h"

enum class ACTIONS
{
    AVANCER,
    VIRAGE_GAUCHE,
    PIVOT_GAUCHE,
    VIRAGE_DROITE,
    PIVOT_DROITE,
};

class SuiveurLumiere
{
public:
    SuiveurLumiere(Driver* marguerite, int puissanceMinAvancer, int ecartMinTournerGauche, int ecartMinTournerDroit, int ecartMinPivotGauche,
    int ecartMinPivotDroit);
    double regulerVitesse(int valeurMin, int valeurMax, int valeur);
    void suivreLumiere(uint8_t lectureGauche, uint8_t lectureDroite);
    int getPuissanceMin();
private:
    int ecartMinAvancer_, ecartMaxAvancer_, puissanceMinAvancer_, puissanceMaxAvancer_, ecartMinTournerGauche_, ecartMinTournerDroit_, ecartMinPivotGauche_,
    ecartMinPivotDroit_; 
    Driver* chauffeur_; 
    ACTIONS determinerAction(int diffIntensite);
};
#endif