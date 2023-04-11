#include "entitate.h"

class Repo{
private:
    Entitate* e;
    int cap,nre;
    void resize();
public:
    Repo(int c);
    ~Repo();
    int get_size();
    void adauga(Entitate enti);
    Entitate get_all();
    //void set_e();
    bool operator==(const Repo& r);
    void afis_repo();
    void meniu();
    Entitate maxim();
    Repo cadr1();
    Repo secv();
};
