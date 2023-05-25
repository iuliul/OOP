#include "Repo.h"
#include <algorithm>
#include "Moneda.h"
#include "TonException.h"
#include "TonValidator.h"
void TonomatRepository:: addItem(Produs produs) {
    produse.push_back(produs);
}

vector<Produs> TonomatRepository::  getAll() {
    return produse;
}

void TonomatRepository::adaugaProdus(const Produs& produs) {
    if (!TonValidator::validaProdus(produs)) {
        throw TonException("Datele produsului nu sunt valide!");
    }
    for (const auto& p : produse) {
        if (p.cod == produs.cod) {
            throw TonException("Produsul cu codul " + std::to_string(produs.cod) + " exista deja!");
        }
    }
    produse.push_back(produs);
}

void TonomatRepository::stergeProdus(int cod) {
    auto it = std::find_if(produse.begin(), produse.end(), [cod](const Produs& p) {
        return p.cod == cod;
    });

    if (it == produse.end()) {
        throw TonException("Produsul cu codul " + std::to_string(cod) + " nu exista!");
    }

    produse.erase(it);
}


void TonomatRepository::actualizeazaProdus(int cod, string nume, double pret) {
    for (auto it = produse.begin(); it != produse.end(); ++it) {
        if (it->cod == cod) {
            it->nume = nume;
            it->pret = pret;
            break;
        }
    }
}

//Produs TonomatRepository::gasesteProdus(int cod) {
//    for (auto it = produse.begin(); it != produse.end(); ++it) {
//        if (it->cod == cod) {
//            return *it;
//        }
//    }
//    return Produs(-1, "", -1);
//}

Produs TonomatRepository::gasesteProdus(int cod) {
    auto it = std::find_if(produse.begin(), produse.end(), [cod](const Produs& p) {
        return p.cod == cod;
    });

    if (it == produse.end()) {
        throw TonException("Produsul cu codul " + std::to_string(cod) + " nu a fost gasit!");
    }

    return *it;
}


vector<Moneda> TonomatRepository::getMonezi() const {
    return moneziDisponibile;
}

void TonomatRepository::adaugaMoneda(const Moneda& m) {
    moneziDisponibile.push_back(m);
}

vector<Produs> TonomatRepository::filteazaProduseDupaNume(string nume) {
    vector<Produs> produseFiltrate;
    for (auto it = produse.begin(); it != produse.end(); ++it) {
        if (it->nume == nume) {
            produseFiltrate.push_back(*it);
        }
    }
    return produseFiltrate;
}
