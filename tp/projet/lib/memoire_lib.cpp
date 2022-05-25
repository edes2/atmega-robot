#include "memoire_lib.h"
#include <util/delay.h>

Memoire::Memoire() {}

uint8_t Memoire::lecture(const uint16_t adresse, uint8_t *donnee) 
{
    valeur_ = mem.lecture(adresse, donnee);
    _delay_ms(DELAYTIME);
    return valeur_;
}

uint8_t Memoire::lecture(const uint16_t adresse, uint8_t *donnee,
                   const uint8_t longueur)
{
    valeur_ = mem.lecture(adresse, donnee,
                   longueur);
    _delay_ms(DELAYTIME);
    return valeur_;
}

uint8_t Memoire::ecriture(const uint16_t adresse, const uint8_t donnee)
{
    valeur_ = mem.ecriture(adresse, donnee);
    _delay_ms(DELAYTIME);
    return valeur_;
}

uint8_t Memoire::ecriture(const uint16_t adresse, uint8_t *donnee,
                    const uint8_t longueur)
{
    valeur_ = mem.ecriture(adresse, donnee,
                    longueur);
    _delay_ms(DELAYTIME);
    return valeur_;
}
                    