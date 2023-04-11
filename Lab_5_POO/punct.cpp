#include <iostream>

using namespace std;

#include "punct.h"

Punct::Punct(){
    this -> ab = 0;
    this -> o = 0;
}

Punct::Punct(int a, int o){
    this -> ab = a;
    this -> o = o;
}

Punct::Punct(Punct& p){
    this -> ab = p.ab;
    this -> o = p.o;
}

Punct::~Punct(){
    this -> ab = 0;
    this -> o = 0;
}

int Punct::get_ab(){
    return this -> ab;
}

int Punct::get_or(){
    return this -> o;
}

bool Punct::operator==(const Punct& p){
    if(ab==p.ab && o==p.o) return true;
    return false;
}

bool Punct::operator>(const Punct& p){
    if(ab>=p.ab && o>=p.o) return true;
    return false;
}

Punct& Punct::operator=(const Punct &p){
    this -> ab = p.ab;
    this -> o = p.o;
    return *this;
}

ostream& operator<<(ostream& os, Punct& p){
    //os<<"coordonatele punctului sunt: \n";
    os<<"coordonata x: "<<p.ab <<"\n";
    os<<"coordonata y: "<<p.o <<"\n";
    return os;
}

void Punct::set_ab(int a){
    this -> ab = a;
}

void Punct::set_or(int o){
    this -> o = o;
}