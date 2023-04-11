#include <iostream>
#include <assert.h>
using namespace std;

#include "repo.h"

void test1(){
    Repo r(4);
    Entitate e1(1,1,1),e2(2,1,1),e3(3,3,3);
    r.adauga(e1);
    r.adauga(e3);
    Entitate e;
    e=r.maxim();
    assert(e==e3);
}

void test2(){
    Repo r(10);
    Entitate e1(1,1,1),e2(2,1,1),e3(3,3,3);
    r.adauga(e1);
    r.adauga(e2);
    Repo r1(10);
    r1.adauga(e1);
    r1.adauga(e2);
    assert(r.cadr1()==r1);
}

void test3(){
    Repo r(10),r1(10);
    Entitate e1(1,1,1),e2(2,1,1),e3(3,3,3);
    r.adauga(e1);
    r.adauga(e1);
    r.adauga(e2);
    r.adauga(e3);
    r.adauga(e3);
    r.adauga(e3);
    r1.adauga(e3);
    r1.adauga(e3);
    r1.adauga(e3);
    assert(r.secv()==r1);
}

void teste(){
    test1();
    test2();
    test3();
}
