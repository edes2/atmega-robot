#ifndef CAPTEUR_IR
#define CAPTEUR_IR

#include <can_lib.h>
#include <avr/io.h>

class CapteurIR
{
public:
    CapteurIR(can* can, uint8_t pinUtilisee);
    uint8_t mesurerDistance();
    ~CapteurIR() = default;
    uint8_t lecture();
private:
    double convertirLecture(uint8_t lecture);
    can* canCapteur_;
    uint8_t pinCapteur_;
};

#endif