#include "suiveurLumiere.h"

SuiveurLumiere::SuiveurLumiere(Driver* chauffeur, int puissanceMinAvancer, int ecartMinTournerGauche, int ecartMinTournerDroit, int ecartMinPivotGauche,
                               int ecartMinPivotDroit) : 
                               chauffeur_(chauffeur), 
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
    }
    else if ((valeur - valeurMin) > (0.5 * (valeurMax-valeurMin)))
    {
        pourcentagePwm = 0.70;//0.85;
    }
    else if ((valeur - valeurMin) > (0.3 * (valeurMax-valeurMin)))
    {
        pourcentagePwm = 0.60;
    }
    else
    {
        pourcentagePwm = 0.5;
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
        chauffeur_->avancer(regulerVitesse(puissanceMinAvancer_, AVANCER_MAX, lectureGauche));
        break;
    }
    case ACTIONS::PIVOT_GAUCHE:
    {
        chauffeur_->pivoterAGauche(INTENSITE_PIVOT);
        break;
    }
    case ACTIONS::VIRAGE_GAUCHE:
    {
        chauffeur_->virage(INTENSITE_ROUE_SUPPORT_VIRAGE, regulerVitesse(ecartMinTournerGauche_, ecartMinPivotGauche_, diffIntensite));
        break;
    }
    case ACTIONS::PIVOT_DROITE:
    {
        chauffeur_->pivoterADroite(INTENSITE_PIVOT);
        break;
    }
    case ACTIONS::VIRAGE_DROITE:
    {
        chauffeur_->virage(regulerVitesse(abs(ecartMinTournerDroit_), abs(ecartMinPivotDroit_), abs(diffIntensite)), INTENSITE_ROUE_SUPPORT_VIRAGE);
        break;
    }
    }
}

int SuiveurLumiere::getPuissanceMin()
{
    return puissanceMinAvancer_;
}