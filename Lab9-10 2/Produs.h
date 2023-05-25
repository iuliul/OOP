#ifndef LAB9_10_PRODUS_H
#define LAB9_10_PRODUS_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produs {
public:
    int cod;
    string nume;
    double pret;

    Produs(int cod, string nume, double pret);
};


#endif //LAB9_10_PRODUS_H
