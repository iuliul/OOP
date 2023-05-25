#include "Produs.h"
#include "Repo.h"
#include <fstream>
#include "sstream"
using namespace std;
#include "TonomatRepositoryFile.h"
TonomatRepositoryFile::TonomatRepositoryFile(string fisier) : fisier(fisier) {
    incarcaFisier();
}

void TonomatRepositoryFile::adaugaProdus(const Produs& produs)  {
    TonomatRepository::adaugaProdus(produs);
    salveazaFisier();
}

void TonomatRepositoryFile::stergeProdus(int cod)  {
    TonomatRepository::stergeProdus(cod);
    salveazaFisier();
}

void TonomatRepositoryFile::actualizeazaProdus(int cod, std::string nume, double pret)  {
    TonomatRepository::actualizeazaProdus(cod, nume, pret);
    salveazaFisier();
}