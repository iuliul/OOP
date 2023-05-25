#ifndef LAB9_10_REPO_H
#define LAB9_10_REPO_H
#include "Produs.h"
#include "Moneda.h"

class TonomatRepository {
private:
    vector<Moneda> moneziDisponibile;

protected:
    vector<Produs> produse;
public:
    void addItem(Produs produs);
    vector<Produs> getAll();
    void adaugaProdus(const Produs& produs);
    //void adaugaProdus(Produs produs);
    void stergeProdus(int cod);
    void actualizeazaProdus(int cod, string nume, double pret);
    Produs gasesteProdus(int cod);
    vector<Moneda>getMonezi() const;
    void adaugaMoneda(const Moneda& moneda);
    vector<Produs> getProduse() const {
        return produse;
    }
    vector<Produs> filteazaProduseDupaNume(string nume);
};

#endif //LAB9_10_REPO_H
