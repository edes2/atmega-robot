#include "enregistrementMem.h"


EnregistrementMem EnregistrementMem::enregistrementMem_;

EnregistrementMem::EnregistrementMem() : adresse_(0x0000) 
{
}

EnregistrementMem* EnregistrementMem::GetInstance()
{
    return &enregistrementMem_;
}

void EnregistrementMem::enregistrerMouvement()
{
    uint8_t directionGauche = 0;
    uint8_t directionDroite = 0;
    uint8_t valeurGauche = OCR1B;
    uint8_t valeurDroite = OCR1A;

    if (((PIND & _BV(PD6)) == _BV(PD6)))
    {
        directionGauche = 1;
    }
    if(((PIND & _BV(PD7)) == _BV(PD7)))
    {
        directionDroite = 1;
    }

    mem_.ecriture(adresse_, directionGauche);
    adresse_++;
    mem_.ecriture(adresse_, directionDroite);
    adresse_++;

    mem_.ecriture(adresse_, valeurGauche);
    adresse_++;
    mem_.ecriture(adresse_, valeurDroite);
    adresse_++;
}

void EnregistrementMem::reproduireMouvement()
{
    uint8_t directionGauche = 0;
    uint8_t directionDroite = 0;
    uint8_t valeurGauche;
    uint8_t valeurDroite;
    
    mem_.lecture(adresse_, &directionGauche);
    adresse_++;
    mem_.lecture(adresse_, &directionDroite);
    adresse_++;

    if(directionGauche == 0xFF)
    {
        estFinLecture_ = true;
    }
    else
    {
        estFinLecture_ = false;
        mem_.lecture(adresse_, &valeurGauche);
        adresse_++;
        mem_.lecture(adresse_, &valeurDroite);
        adresse_++;

        _delay_ms(125); // "Hack"
        
        if(directionGauche){
            PORTD |= _BV(PA6);
        }
        else{
            PORTD &= ~_BV(PA6);
        }
        if(directionDroite){
            PORTD |= _BV(PA7);
        }
        else{
            PORTD &= ~_BV(PA7);
        }

        OCR1B = valeurGauche;
        OCR1A = valeurDroite;
    }
}

bool EnregistrementMem::estFinLecture()
{
    return estFinLecture_;
}

void EnregistrementMem::finEnregistrement()
{
    mem_.ecriture(adresse_, 0xFF);
    adresse_++;
    mem_.ecriture(adresse_, 0xFF);
    adresse_++;

    adresse_ = 0x0000;
}