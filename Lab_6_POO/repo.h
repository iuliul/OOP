#include <queue>
#include "entitate.h"

class Repo{
private:
    queue<Entitate> e;
public:
    Repo();
    ~Repo();
    int get_size();
    void adauga(const Entitate& enti);
    //void set_e();
    bool operator==(Repo& r);
    void afis_repo();
    void meniu();
    Entitate maxim();
    Repo cadr1();
    Repo secv();
};

