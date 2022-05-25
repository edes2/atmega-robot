#include "capteurIR.h"

CapteurIR::CapteurIR(can* can, uint8_t pinUtilisee) : canCapteur_(can)
{
    DDRA &= ~_BV(pinUtilisee);
    pinCapteur_ = pinUtilisee;
}

uint8_t CapteurIR::lecture()
{
    return canCapteur_->lecture(pinCapteur_) >> 2;
}

double CapteurIR::convertirLecture(uint8_t lecture)
{
    return 26.0/((lecture * 5.0)/255.0);
}

uint8_t CapteurIR::mesurerDistance(){
    return convertirLecture(lecture());
}