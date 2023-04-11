#include <iostream>

using namespace std;

#include "subalg.h"
#include "repo.h"

int main()
{
    teste();
    Repo r(10);
    Entitate e1(1,1,1),e2(2,1,1),e3(3,3,3);
    r.adauga(e1);
    r.adauga(e1);
    r.adauga(e2);
    r.adauga(e3);
    r.adauga(e3);
    r.adauga(e3);
    r.meniu();
    return 0;
}
