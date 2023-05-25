#ifndef LAB9_10_TONVALIDATOR_H
#define LAB9_10_TONVALIDATOR_H

#include "Produs.h"
class TonValidator {
public:
    static bool validaProdus(const Produs& produs) {
        // Verificăm dacă numele și prețul produsului sunt valide
        if (produs.nume.empty() || produs.pret <= 0) {
            return false;
        }
        return true;
    }

};



#endif //LAB9_10_TONVALIDATOR_H
