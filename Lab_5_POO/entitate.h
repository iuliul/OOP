#include <iostream>

using namespace std;

#include "punct.h"

class Entitate{
private:
    Punct centru;
    double raza;
public:
    Entitate();
    Entitate(int ab, int o, int r);
    Entitate(const Entitate &c);
    ~Entitate();
    double get_raza();
    void set_raza(double r);
    Punct get_centru();
    void set_centru(Punct& p);
    double lungime();
    double arie();
    Entitate& operator=(const Entitate& e);
    bool operator==(const Entitate& e);
    bool operator>(const Entitate& e);
    friend ostream& operator<<(ostream& os,const Entitate& e);
};

