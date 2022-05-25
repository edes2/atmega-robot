/* Ce fichier permet de print le contenu de la memoire externe */
#define F_CPU 8000000

#include <memoire_lib.h>
#include <comms_lib.h>
#include <avr/io.h>
#include <debug.h>
#include <util/delay.h>
#include <debug.h>

int main() {
    Memoire24CXXX mem;
    uint8_t donnee;
    uint16_t adresse=0x0000;
    uint16_t longueur;
    
    char buffer[50];

    while(true) {
        mem.lecture(adresse, &donnee);
        _delay_ms(5);

        if (donnee==0x01) {
            break;
        }
        adresse+=2; // On cherche seulement le opcode
    }

    adresse-=2; // La longueur se trouve deux instructions avant.

    uint8_t longueurH;
    uint8_t longueurL;
    mem.lecture(adresse, &longueurH);
    adresse++;
    _delay_ms(5);
    mem.lecture(adresse, &longueurL);
    adresse++;
    _delay_ms(5);
    longueur = (longueurH << 8) | longueurL;

    
    itoa(longueur, buffer, 16);
    DEBUG_PRINT(("Longueur (en hex): "));
    DEBUG_PRINT((buffer));
    DEBUG_PRINT(("\n"));

    

    DEBUG_PRINT(("Beginning printing\n"));
    for (int i=adresse;i<longueur;i++) {
        mem.lecture(i, &donnee);
        _delay_ms(5);
        itoa(donnee, buffer, 16);
        DEBUG_PRINT((buffer));
        DEBUG_PRINT(("\n"));
    }
    DEBUG_PRINT(("Finished\n"));
}