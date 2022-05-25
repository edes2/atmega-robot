#include "interpreteurLumiere.h"

InterpreteurLumiere::InterpreteurLumiere(can* can, uint8_t pinPhotorecep) : conversion_(can)
{
    DDRA &= ~_BV(pinPhotorecep);
    positionPhotoRecep_ = pinPhotorecep;
}

uint8_t InterpreteurLumiere::lectureIntensite()
{
    return (conversion_->lecture(positionPhotoRecep_) >> 2);
}

uint8_t InterpreteurLumiere::differenceIntensite(uint8_t intensitePhotorecep1, uint8_t intensitePhotorecep2){
    return(intensitePhotorecep1 - intensitePhotorecep2);
}