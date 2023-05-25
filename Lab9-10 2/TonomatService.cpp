#include <memory>
#include <algorithm>
#include "TonomatRepositoryFile.h"
#include "TonomatService.h"
#include "Produs.h"
#include "Repo.h"
#include "Moneda.h"
#include "TonException.h"
#include "TonValidator.h"

TonomatService:: TonomatService(TonomatRepository& repository) : repository(repository) {
        moneziDisponibile = { 0.5, 1, 5, 10, 50, 100 };
}

void TonomatService:: achizitioneazaProdus(int codProdus, double suma) {
    Produs produs = repository.gasesteProdus(codProdus);
    if (produs.cod == -1) {
        cout << "Produsul nu exista" << endl;
        return;
    }
    if (suma < produs.pret) {
        cout << "Suma introdusa este prea mica" << endl;
        return;
    }
    double rest = suma - produs.pret;
    cout << "Restul dumneavoastra este: " << rest << " lei" << endl;
    if (rest > 0) {
        cout << "Restul va fi dat in monezi de valori corespunzatoare:" << endl;
        for (double m : moneziDisponibile) {
            while (rest >= m && find(moneziDisponibile.begin(), moneziDisponibile.end(), m) != moneziDisponibile.end()) {
                cout << m << " ";
                rest -= m;
            }
        }
        cout << endl;
    }
    stergeProdus(codProdus);
}

void TonomatService::afiseazaMonezDisponibile() {
    cout << "Monezi disponibile:" << endl;
    vector<Moneda> moneziDisponibile = repository.getMonezi();
    cout << "Numarul de monede disponibile: " << moneziDisponibile.size() << endl;

    for (const auto& m : moneziDisponibile) {
        cout << m.getValoare() << " lei: " << m.getCantitate() << endl;
    }
}


void TonomatService::adaugaProdus(int cod, string nume, double pret) {
    Produs produs(cod, nume, pret);
    if (!TonValidator::validaProdus(produs)) {
        throw TonException("Datele produsului nu sunt valide!");
    }
    try {
        repository.adaugaProdus(produs);
        cout << "Produsul a fost adaugat cu succes." << endl;
    } catch (const TonException& ex) {
        cout << "Eroare: " << ex.what() << endl;
    }

}

void TonomatService::stergeProdus(int cod) {
    try {
        repository.stergeProdus(cod);
        cout << "Produsul a fost sters cu succes." << endl;
    } catch (const TonException& ex) {
        cout << "Eroare: " << ex.what() << endl;
    }

}

void TonomatService::actualizeazaProdus(int cod, string nume, double pret) {
    repository.actualizeazaProdus(cod, nume, pret);
}

Produs TonomatService::gasesteProdus(int cod) {
    try {
        Produs produs = repository.gasesteProdus(cod);
        // Folosim produsul găsit
    } catch (const TonException& ex) {
        cout << "Eroare: " << ex.what() << endl;
    }

}

vector<Produs> TonomatService::toateProdusele() {
    return repository.getAll();
}

void TonomatService::adaugaBani(int valoare, int cantitate) {
    Moneda m(valoare, cantitate);
    repository.adaugaMoneda(m);
}

vector<Produs> TonomatService::filtreazaProduseDupaNume(string nume) {
    return repository.filteazaProduseDupaNume(nume);
}