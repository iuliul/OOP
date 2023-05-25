#ifndef LAB9_10_UI_H
#define LAB9_10_UI_H
#include "TonomatService.h"

class TonomatUI {
private:
    TonomatService& service;

public:
    TonomatUI(TonomatService& service);

    void meniuPrincipal();
    void adaugaProdus();
    void stergeProdus();
    void actualizeazaProdus();
    void gasesteProdus();
    void toateProdusele();
    void achizitioneazaProdus();
    void cautaProduseDupaNume();
};


#endif //LAB9_10_UI_H
