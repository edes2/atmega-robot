#include "suiveurLumiere.h"

SuiveurLumiere::SuiveurLumiere(ChauffeurDuRobot* marguerite, int puissanceMinAvancer, int ecartMinTournerGauche, int ecartMinTournerDroit, int ecartMinPivotGauche,
                               int ecartMinPivotDroit) : 
                               marguerite_(marguerite), 
                               puissanceMinAvancer_(puissanceMinAvancer), 
                               ecartMinTournerGauche_(ecartMinTournerGauche),
                               ecartMinTournerDroit_(ecartMinTournerDroit), 
                               ecartMinPivotGauche_(ecartMinPivotGauche), 
                               ecartMinPivotDroit_(ecartMinPivotDroit)
{}

ACTIONS SuiveurLumiere::determinerAction(int diffIntensite)
{
    if (diffIntensite < ecartMinPivotDroit_)
    {
        return ACTIONS::PIVOT_DROITE;
    }
    else if (diffIntensite < ecartMinTournerDroit_)
    {
        return ACTIONS::VIRAGE_DROITE;
    }
    else if (diffIntensite > ecartMinPivotGauche_)
    {
        return ACTIONS::PIVOT_GAUCHE;
    }
    else if (diffIntensite > ecartMinTournerGauche_)
    {
        return ACTIONS::VIRAGE_GAUCHE;
    }
    return ACTIONS::AVANCER;
}

double SuiveurLumiere::regulerVitesse(int valeurMin, int valeurMax, int valeur)
{   
    double pourcentagePwm;
    if ((valeur - valeurMin) > (0.75 * (valeurMax-valeurMin)))
    {
        pourcentagePwm = 1.0;
        DEBUG_PRINT("Full speed ");
    }
    else if ((valeur - valeurMin) > (0.5 * (valeurMax-valeurMin)))
    {
        pourcentagePwm = 0.70;//0.85;
        DEBUG_PRINT("Mid speed ");
    }
    else if ((valeur - valeurMin) > (0.3 * (valeurMax-valeurMin)))
    {
        pourcentagePwm = 0.60;
        DEBUG_PRINT("Low speed ");
    }
    else
    {
        pourcentagePwm = 0.5;
        DEBUG_PRINT("Lowest speed ");
    }
    return pourcentagePwm;
}
void SuiveurLumiere::suivreLumiere(uint8_t lectureGauche, uint8_t lectureDroite)
{
    int diffIntensite = lectureGauche - lectureDroite;
    ACTIONS etatsRobot = determinerAction(diffIntensite);
    switch (etatsRobot)
    {
    case ACTIONS::AVANCER:
    {
        marguerite_->avancer(regulerVitesse(puissanceMinAvancer_, AVANCER_MAX, lectureGauche));
        break;
    }
    case ACTIONS::PIVOT_GAUCHE:
    {
        marguerite_->pivoterAGauche(INTENSITE_PIVOT);
        break;
    }
    case ACTIONS::VIRAGE_GAUCHE:
    {
        marguerite_->virage(INTENSITE_ROUE_SUPPORT_VIRAGE, regulerVitesse(ecartMinTournerGauche_, ecartMinPivotGauche_, diffIntensite));
        break;
    }
    case ACTIONS::PIVOT_DROITE:
    {
        marguerite_->pivoterADroite(INTENSITE_PIVOT);
        break;
    }
    case ACTIONS::VIRAGE_DROITE:
    {
        marguerite_->virage(regulerVitesse(abs(ecartMinTournerDroit_), abs(ecartMinPivotDroit_), abs(diffIntensite)), INTENSITE_ROUE_SUPPORT_VIRAGE);
        break;
    }
    }
}

int SuiveurLumiere::getPuissanceMin()
{
    return puissanceMinAvancer_;
}