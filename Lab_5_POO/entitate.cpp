#include <iostream>
#include <cmath>


using namespace std;

#include "entitate.h"

Entitate :: Entitate(){
    this->raza = 0;
}

Entitate::Entitate(int ab, int o, int raza){
    if(raza<0) {
        cout<<"raza cercului trebuie sa fie un nr pozitiv\n";
        this->raza=0;
    }
    else{
        this->centru.set_ab(ab);
        this->centru.set_or(o);
        this->raza = raza;
    }
}

Entitate::Entitate(const Entitate &c){
    this->centru = c.centru;
    this->raza = c.raza;
}

Entitate::~Entitate(){
    this->raza = 0;
}

double Entitate::get_raza(){
    return this->raza;
}

void Entitate::set_raza(double r){
    this->raza = r;
}

Punct Entitate::get_centru(){
    return this->centru;
}

void Entitate::set_centru(Punct& p){
    this->centru.set_ab(p.get_ab());
    this->centru.set_or(p.get_or());
}

Entitate& Entitate::operator=(const Entitate& e){
    this->centru = e.centru;
    this->raza = e.raza;
    return *this;
}

bool Entitate::operator==(const Entitate& e){
    if(this->centru==e.centru && this->raza==e.raza) return true;
    return false;
}

bool Entitate::operator>(const Entitate& e){
    if(this->centru > e.centru && this->raza > e.raza) return true;
    return false;
}

ostream& operator<<(ostream& os,const Entitate& e){
    os<<"cercul are centrul in punctul de coordonate: ";
    Punct p;
    p=e.centru;
    os << p.get_ab()<<" "<<p.get_or()<<"\n";
    os<<"raza cercului este: "<<e.raza<<"\n\n";
    return os;
}

double Entitate::lungime(){
    return 2*M_PI*this->raza;
}

double Entitate::arie(){
    return M_PI*this->raza*this->raza;
}

