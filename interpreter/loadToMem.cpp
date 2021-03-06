/* Ce fichier permet load des octets dans la memoire */
#define F_CPU 8000000

#include <memoire_lib.h>
#include <comms_lib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <led_lib.h>

int main() {
    // Les deux premiers octets représentent la longueur 
    // totale du fichier binaire (en octets).
    commUART uart;
    Memoire24CXXX mem;
    LED led(&DDRA, &PORTA, DDA0, DDA1);
    led.Rouge();
    uint8_t donnees[255];
    donnees[0] = uart.receptionUART();
    donnees[1] = uart.receptionUART();
    uint16_t longueur = (donnees[0] << 8) | donnees[1];

    for (uint8_t i = 2; i < longueur; i++) {
        donnees[i] = uart.receptionUART();
    }

    for (uint16_t i = 0; i < longueur; i++) {
        mem.ecriture(i, donnees[i]);
        _delay_ms(5);
    }
    
    led.Vert();
    _delay_ms(500);

    return 0;
}