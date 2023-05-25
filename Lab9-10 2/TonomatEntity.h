#ifndef LAB9_10_TONOMATENTITY_H
#define LAB9_10_TONOMATENTITY_H
#include "Repo.h"

class TonomatEntity {
private:
    TonomatRepository repository;
public:
    void adaugaProdus(int cod, string nume, double pret);
    vector<Produs> toateProdusele();
};


#endif //LAB9_10_TONOMATENTITY_H
