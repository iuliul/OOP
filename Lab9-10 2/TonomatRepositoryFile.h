#ifndef LAB9_10_TONOMATREPOSITORYFILE_H
#define LAB9_10_TONOMATREPOSITORYFILE_H


#pragma once

#include "Produs.h"
#include "Repo.h"
#include <fstream>
using namespace std;

class TonomatRepositoryFile : public TonomatRepository {
private:
    string fisier;

    void incarcaFisier() {
        ifstream fin(fisier);
        double pret;
        int cod;
        string nume;
        while (fin >> cod >> nume >> pret) {
            Produs produs(cod, nume, pret);
            produse.push_back(produs);
        }
        fin.close();
    }

    void salveazaFisier() {
        std::ofstream fout(fisier);
        for (auto& produs : produse) {
            fout << produs.cod << " " << produs.nume << " " << produs.pret << "\n";
        }
        fout.close();
    }

public:

    TonomatRepositoryFile(string fisier);

    void adaugaProdus(const Produs& produs);

    void stergeProdus(int cod);

    void actualizeazaProdus(int cod, string nume, double pret);
};



#endif //LAB9_10_TONOMATREPOSITORYFILE_H
