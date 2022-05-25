#ifndef INTERPRETEURLUMIERE_H
#define INTERPRETEURLUMIERE_H

#include <can_lib.h>
#include <avr/io.h>

class InterpreteurLumiere
{
public:
    InterpreteurLumiere(can* can, uint8_t pinPhotorecep);
    uint8_t lectureIntensite();
    uint8_t differenceIntensite(uint8_t intensitePhotorecep1, uint8_t intensitePhotorecep2);
private:
    can* conversion_; 
    uint8_t positionPhotoRecep_;
};

#endif