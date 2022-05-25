
#include "suiveurMur.h"

SuiveurMur::SuiveurMur(CapteurIR* capteurIR, Driver* chauffeur)  : capteurIR_(capteurIR), chauffeur_(chauffeur)
{}


double SuiveurMur::calculerRoueGauche()
{

    double roueGauche;
    uint8_t distanceMur;
    distanceMur = capteurIR_->mesurerDistance();

    double tauxVariationGauche = ((VITESSE_ROUE_MAX - VITESSE_ROUE_BASE) / (DISTANCE_MAX - DISTANCE_IDEALE));
    double ordonneeOrigineGauche = VITESSE_ROUE_MAX - DISTANCE_MAX*tauxVariationGauche;

    if (DISTANCE_MIN < distanceMur && distanceMur < DISTANCE_IDEALE)
    {
        roueGauche = VITESSE_ROUE_BASE;
    }
    else if (DISTANCE_IDEALE <= distanceMur && distanceMur < DISTANCE_MAX)
    {
        roueGauche = (tauxVariationGauche * distanceMur) + ordonneeOrigineGauche;
    }
    else if(distanceMur > DISTANCE_MAX){
        roueGauche = 0.0;
    }
    else
    {
        roueGauche = VITESSE_ROUE_MAX;
    }

    return roueGauche;
}

double SuiveurMur::calculerRoueDroite()
{
    double roueDroite;
    uint8_t distanceMur;
    distanceMur = capteurIR_->mesurerDistance();
    double tauxVariationDroite = ((VITESSE_ROUE_BASE - VITESSE_ROUE_MAX) / (DISTANCE_IDEALE - DISTANCE_MIN));
    double ordonneeOrigineDroite = VITESSE_ROUE_MAX - DISTANCE_MIN * tauxVariationDroite;

    if (DISTANCE_MIN < distanceMur && distanceMur < DISTANCE_IDEALE)
    {
        roueDroite = (tauxVariationDroite * distanceMur) + ordonneeOrigineDroite;
    }
    else if (DISTANCE_IDEALE <= distanceMur && distanceMur < DISTANCE_MAX)
    {
        roueDroite = VITESSE_ROUE_BASE;
    }
    else if(distanceMur > DISTANCE_MAX){
        roueDroite = 0.0;
    }
    else
    {
        roueDroite = VITESSE_ROUE_BASE;
    }

    return roueDroite;
}

void SuiveurMur::suivreMur()
{
    chauffeur_->virage(calculerRoueGauche(), calculerRoueDroite());
}