#include <iostream>

using namespace std;

class Punct{
private:
    int ab;
    int o;
public:
    Punct();
    Punct(int a, int o);
    Punct(Punct& p);
    ~Punct();
    int get_ab();
    int get_or();
    void set_ab(int a);
    void set_or(int o);
    Punct& operator=(const Punct &p);
    bool operator==(const Punct& p);
    bool operator>(const Punct& p);
    friend ostream& operator<<(ostream& os, Punct& p);
};
