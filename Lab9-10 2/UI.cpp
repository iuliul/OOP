#include "UI.h"
#include "Repo.h"
#include "TonomatRepositoryFile.h"
TonomatUI::TonomatUI(TonomatService& service) : service(service) {}

void TonomatUI::meniuPrincipal() {
    while (true) {
        cout << endl;
        cout << "1. Adauga produs" << endl;
        cout << "2. Sterge produs" << endl;
        cout << "3. Actualizeaza produs" << endl;
        cout << "4. Gaseste produs" << endl;
        cout << "5. Afisare produsele" << endl;
        cout << "6. Achizitionare produs" << endl;
        cout << "9. Filtreaza produs" << endl;
        cout << "0. Iesire" << endl;
        cout << endl;
        int optiune;
        cin >> optiune;
        if (optiune == 0) {
            break;
        }
        switch (optiune) {
            case 1:
                adaugaProdus();
                break;
            case 2:
                stergeProdus();
                break;
            case 3:
                actualizeazaProdus();
                break;
            case 4:
                gasesteProdus();
                break;
            case 5:
                toateProdusele();
                break;
            case 6:
                achizitioneazaProdus();
                break;
            case 7:
                service.afiseazaMonezDisponibile();
                break;
            case 8:
                int valoare, cantitate;
                cout << "Introduceti valoarea monedei: ";
                cin >> valoare;
                cout << "Introduceti cantitatea monedei: ";
                cin >> cantitate;
                service.adaugaBani(valoare, cantitate);
                break;
            case 9:
                cautaProduseDupaNume();
                break;
            default:
                cout << "Optiune invalida" << endl;
                break;
        }
    }
}

void TonomatUI::cautaProduseDupaNume() {
    vector<Produs> produseFiltrate = service.filtreazaProduseDupaNume("Cola");
    for (auto it = produseFiltrate.begin(); it != produseFiltrate.end(); ++it) {
        cout << "Cod: " << it->cod << ", Nume: " << it->nume << ", Pret: " << it->pret << endl;
    }
}

void TonomatUI::adaugaProdus() {
    cout << "\nIntroduceti codul produsului: ";
    int cod;
    cin >> cod;
    cout << "Introduceti numele produsului: ";
    string nume;
    cin >> nume;
    cout << "Introduceti pretul produsului: ";
    double pret;
    cin >> pret;
    service.adaugaProdus(cod, nume, pret);
}

void TonomatUI::stergeProdus() {
    cout << "\nIntroduceti codul produsului de sters: ";
    int cod;
    cin >> cod;
    service.stergeProdus(cod);
}

void TonomatUI::actualizeazaProdus() {
    cout << "\nIntroduceti codul produsului de actualizat: ";
    int cod;
    cin >> cod;
    cout << "Introduceti noul nume al produsului: ";
    string nume;
    cin >> nume;
    cout << "Introduceti noul pret al produsului: ";
    double pret;
    cin >> pret;
    service.actualizeazaProdus(cod, nume, pret);
}

void TonomatUI::gasesteProdus() {
    cout << "\nIntroduceti codul produsului cautat: ";
    int cod;
    cin >> cod;
    Produs produs = service.gasesteProdus(cod);
    if (produs.cod == -1) {
        cout << "Produsul nu exista" << endl;
    } else {
        cout << "Cod: " << produs.cod << endl;
        cout << "Nume: " << produs.nume << endl;
        cout << "Pret: " << produs.pret << endl;
    }
}

void TonomatUI::toateProdusele() {
    vector<Produs> produse = service.toateProdusele();
    for (Produs& produs : produse) {
        cout << "Cod: " << produs.cod << endl;
        cout << "Nume: " << produs.nume << endl;
        cout << "Pret: " << produs.pret << endl;
        cout << endl;
    }
}

// pr 6
void TonomatUI::achizitioneazaProdus() {
    int codProdus;
    double suma;
    cout << "\nIntroduceti codul produsului: ";
    cin >> codProdus;
    cout << "Introduceti suma de bani: ";
    cin >> suma;
    service.achizitioneazaProdus(codProdus, suma);
}