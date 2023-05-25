#ifndef LAB9_10_TONOMATSERVICE_H
#define LAB9_10_TONOMATSERVICE_H
#include "Produs.h"
#include "Repo.h"

class TonomatService {
private:
    TonomatRepository& repository;
    vector<double> moneziDisponibile;

public:
    TonomatService(TonomatRepository& repository);
    void afiseazaMonezDisponibile();
    void achizitioneazaProdus(int codProdus, double suma);
    void adaugaProdus(int cod, string nume, double pret);
    void stergeProdus(int cod);
    void actualizeazaProdus(int cod, string nume, double pret);
    Produs gasesteProdus(int cod);
    vector<Produs> toateProdusele();
    void adaugaBani(int valoare, int cantitate);
    vector<Produs> filtreazaProduseDupaNume(string nume);
};


#endif //LAB9_10_TONOMATSERVICE_H
