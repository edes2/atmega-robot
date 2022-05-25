#include "tools.h"

bool estLumiereForte(uint8_t lectureG, uint8_t lectureD, int avancerMin)
{
    if (((lectureG + lectureD) / 2) > avancerMin){
        return true;
    }
    return false;
}