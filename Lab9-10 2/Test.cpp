#include "Test.h"
#include "TonomatEntity.h"
#include "TonomatService.h"
#include "Repo.h"
#include <cassert>

void test(){
    TonomatEntity tonomat;
    tonomat.adaugaProdus(1, "Croissant", 2.50);
    tonomat.adaugaProdus(2, "Ciocolata", 3.00);
    vector<Produs> produse = tonomat.toateProdusele();
}
void testStergeProdus() {
    TonomatRepository repo;
    repo.adaugaProdus({ 1, "Coca Cola", 3.5 });
    repo.adaugaProdus({ 2, "Fanta", 3.0 });
    repo.adaugaProdus({ 3, "Sprite", 3.2 });

    repo.stergeProdus(2);

    assert(repo.getProduse().size() == 2); // verificam daca a fost eliminat un produs
    assert(repo.getProduse()[0].cod == 1); // verificam daca primul produs ramas este cel corect
    assert(repo.getProduse()[1].cod == 3); // verificam daca al doilea produs ramas este cel corect
}

void test_actualizeazaProdus() {
    TonomatRepository repo;
    Produs p1{ 1, "Coca-Cola", 4.5 };
    repo.adaugaProdus(p1);
    assert(repo.getProduse().size() == 1);
    assert(repo.getProduse()[0].cod == 1);
    assert(repo.getProduse()[0].nume == "Coca-Cola");
    assert(repo.getProduse()[0].pret == 4.5);

    repo.actualizeazaProdus(1, "Pepsi", 4.0);
    assert(repo.getProduse().size() == 1);
    assert(repo.getProduse()[0].cod == 1);
    assert(repo.getProduse()[0].nume == "Pepsi");
    assert(repo.getProduse()[0].pret == 4.0);
}
void test_gasesteProdus() {
    TonomatRepository repo;
    Produs p1{ 1, "Coca-Cola", 4.5 };
    Produs p2{ 2, "Pepsi", 4.0 };
    repo.adaugaProdus(p1);
    repo.adaugaProdus(p2);

    assert(repo.gasesteProdus(1).nume == "Coca-Cola");
    assert(repo.gasesteProdus(2).pret == 4.0);
    assert(repo.gasesteProdus(3).cod == -1);
}

void test_filtrareProduseDupaNume() {
    TonomatRepository repo;
    TonomatService service(repo);

    service.adaugaProdus(1, "Coca-Cola", 4.5);
    service.adaugaProdus(2, "Pepsi", 4.0);
    service.adaugaProdus(3, "Fanta", 4.0 );

    vector<Produs> produseFiltrate = service.filtreazaProduseDupaNume("Coca-Cola");
    assert(produseFiltrate.size() == 1);
    assert(produseFiltrate[0].cod == 1);
    assert(produseFiltrate[0].nume == "Coca-Cola");
    assert(produseFiltrate[0].pret == 4.5);

    produseFiltrate = service.filtreazaProduseDupaNume("Pepsi");
    assert(produseFiltrate.size() == 1);
    assert(produseFiltrate[0].cod == 2);
    assert(produseFiltrate[0].nume == "Pepsi");
    assert(produseFiltrate[0].pret == 4.0);

    produseFiltrate = service.filtreazaProduseDupaNume("Sprite");
    assert(produseFiltrate.size() == 0);
}
