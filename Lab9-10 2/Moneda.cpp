#include "Moneda.h"
Moneda::Moneda(int valoare, int cantitate) {
    this->valoare = valoare;
    this->cantitate = cantitate;
}

int Moneda::getValoare() const {
    return valoare;
}

int Moneda::getCantitate() const {
    return cantitate;
}

void Moneda::setValoare(int valoare) {
    this->valoare = valoare;
}

void Moneda::setCantitate(int cantitate) {
    this->cantitate = cantitate;
}


