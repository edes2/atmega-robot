/* 
Cette classe est un wrapper autour de la classe mem24CXXX qui gere la memoire, 
elle permet une meilleure/plus simple utilisation de la memoire 
*/

#ifndef MEMOIRE_H
#define MEMOIRE_H

#include "mem24CXXX_lib.h"

#define DELAYTIME 5

class Memoire {
public:
    Memoire();
    uint8_t lecture(const uint16_t adresse, uint8_t *donnee);

    uint8_t lecture(const uint16_t adresse, uint8_t *donnee,
                   const uint8_t longueur);

    uint8_t ecriture(const uint16_t adresse, const uint8_t donnee);

    uint8_t ecriture(const uint16_t adresse, uint8_t *donnee,
                    const uint8_t longueur);
private:
    Memoire24CXXX mem;
    uint8_t valeur_;
};

#endif