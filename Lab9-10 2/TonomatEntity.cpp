#include "TonomatEntity.h"
void TonomatEntity:: adaugaProdus(int cod, string nume, double pret) {
    Produs produs(cod, nume, pret);
    repository.addItem(produs);
}

vector<Produs> TonomatEntity:: toateProdusele() {
    return repository.getAll();
}

