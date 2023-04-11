#include <iostream>

using namespace std;

#include "teste.h"
#include "repo.h"

int main()
{
    teste();
    Repo r,r1;
    Entitate e1(1,1,1),e2(2,1,1),e3(3,3,3),e4(-3,3,3);
    r.adauga(e1);
    r.adauga(e1);
    r.adauga(e2);
    r.adauga(e3);
    r.adauga(e3);
    r.adauga(e3);
    r.adauga(e4);
    r.meniu();
    return 0;
}
