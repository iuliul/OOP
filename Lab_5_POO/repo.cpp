#include <iostream>

using namespace std;

#include "repo.h"

Repo::Repo(int c)
{
    cap=c;
    nre=0;
    e=new Entitate[cap];
}

Repo::~Repo()
{
    nre=0;
    if(e!=NULL) delete[] e;
    e=NULL;
}

void Repo::adauga(Entitate enti)
{
    //if(nre==cap) resize();
    e[nre] = enti;
    nre++;
}

int Repo::get_size()
{
    return this->nre;
}

Entitate Repo::get_all()
{
    return *e;
}

void Repo::afis_repo()
{
    for(int i=0; i<nre; i++)
        cout<<e[i];
    //cout<<"cercul de pe pozitia "<<i<<" are raza "<<this->e[i].get_raza()<<endl;
}

bool Repo::operator==(const Repo& r){
    if (this->nre!=r.nre) return false;
    for(int i=0; i < this->nre ; i++)
        if (!(this->e[i] == r.e[i])) return false;
    return true;
}

Entitate Repo::maxim()
{
    Entitate em;
    for(int i=0; i < this->nre ; i++)
        if(this->e[i] > em) em = this->e[i];
    return em;
}

Repo Repo::cadr1()
{
    Repo r1(cap);
    Entitate em(0,0,0);
    for(int i=0; i < this->nre ; i++)
        if(this->e[i] > em) r1.adauga(e[i]);
    return r1;
}

Repo Repo::secv()
{
    Repo r1(cap);
    int in=0,fl=0,imax=0,fmax=0;
    for(int i=0; i < this->nre-1 ; i++)
        if(this->e[i] == this->e[i+1]) fl=i+1;
        else{
            if(fl-in > fmax-imax)
                fmax=fl,imax=in;
            in=i+1;
            fl=i+1;
        }
    if(fl-in > fmax-imax)
        fmax=fl,imax=in;
    for(int i=imax; i <= fmax ; i++)
        r1.adauga(e[i]);
    return r1;
}

void print_meniu()
{
    cout<<"1. adaugare cerc\n";
    cout<<"2. afisare cercuri\n";
    cout<<"3. cel mai mare cerc\n";
    cout<<"4. cercurile din cadranul I\n";
    cout<<"5. cea mai mare secventa de cercuri egale\n";
    cout<<"0. iesire\n";
}

void Repo::meniu()
{
    int ok=1,op,r;
    while(ok==1)
    {
        print_meniu();
        cout<<"dati optiunea: ";
        cin>>op;
        if(op==1)
        {
            cout<<"dati coordonatele centrului cercului: ";
            int a,o;
            cin>>a>>o;
            cout<<"dati raza cercului: ";
            cin>>r;
            Entitate c(a,o,r);
            adauga(c);
        }
        else if(op==2)
            afis_repo();
        else if(op==3)
            cout<<maxim()<<endl;
        else if(op==4)
            cadr1().afis_repo();
        else if(op==5)
            secv().afis_repo();
        else if(op==0)
            ok=0;
        else cout<<"optiune gresita\n";
    }
}
