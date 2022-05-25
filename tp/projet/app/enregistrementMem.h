/* Classe Singleton */

#ifndef ENREGISTMEM_H
#define ENREGISTMEM_H

#include <memoire_lib.h>

class EnregistrementMem {
public:
    static EnregistrementMem* GetInstance();

    void enregistrerMouvement();
    void reproduireMouvement();
    void finEnregistrement();

    bool estFinLecture();

private:
    EnregistrementMem();
    static EnregistrementMem enregistrementMem_;
    
    uint16_t adresse_;
    
    bool estFinLecture_;

    Memoire mem_;
};
#endif