#include <iostream>

using namespace std;

#include "repo.h"

Repo::Repo()
{

}

Repo::~Repo()
{
    while(!(e.empty())) e.pop();
}

void Repo::adauga(const Entitate& enti)
{
    this->e.push(enti);
}

int Repo::get_size()
{
    return (int) this->e.size();
}

void Repo::afis_repo(){
    int i=get_size();
    while(i>0){
        Entitate enti=e.front();
        cout<<enti;
        e.pop();
        adauga(enti);
        i--;
    }
    //cout<<"cercul de pe pozitia "<<i<<" are raza "<<this->e[i].get_raza()<<endl;
}

bool Repo::operator==(Repo& r){
    int l1=get_size();
    int l2=r.get_size();
    if (l1!=l2) return false;
    while(l1>0){
        Entitate e1=e.front();
        Entitate e2=r.e.front();
        e.pop();
        r.e.pop();
        e.push(e1);
        r.e.push(e2);
        l1--;
        if (!(e1 == e2)) return false;

    }

    return true;
}


Entitate Repo::maxim()
{
    int l1=get_size();
    Entitate em;
    while(l1>0){
        Entitate ec=e.front();
        if(ec > em) em = ec;
        e.pop();
        e.push(ec);
        l1--;
    }

    return em;
}


Repo Repo::cadr1()
{
    int l1=get_size();
    Repo r1;
    Entitate em(0,0,0);
    while(l1>0){
        Entitate ec=e.front();
        if(ec > em) r1.adauga(ec);
        e.pop();
        e.push(ec);
        l1--;
    }

    return r1;
}


Repo Repo::secv(){
    Entitate e1,e2;
    int l=get_size();
    Repo r1;
    int in=0,fl=0,imax=0,fmax=0;
    e1=this->e.front();
    this->e.pop();
    this->e.push(e1);
    for(int i=1; i < l ; i++){
        e2=this->e.front();
        this->e.pop();
        this->e.push(e2);
        if(e1 == e2) fl=i;
        else{
            if(fl-in > fmax-imax)
                fmax=fl,imax=in;
            in=i;
            fl=i;
        }
        e1=e2;
    }
    if(fl-in > fmax-imax)
        fmax=fl,imax=in;
    for(int i=0; i < imax ; i++){
        Entitate enti=e.front();
        e.pop();
        e.push(enti);
    }
    for(int i=imax; i <=fmax ; i++){
        Entitate enti=e.front();
        r1.adauga(enti);
        e.pop();
        e.push(enti);
    }
    for(int i=fmax+1; i < l ; i++){
        Entitate enti=e.front();
        e.pop();
        e.push(enti);
    }
    return r1;
}

void print_meniu()
{
    cout<<"1. ADAUGARE CERC\n";
    cout<<"2. AFISARE CERCURI\n";
    cout<<"3. CEL MAI MARE CERC\n";
    cout<<"4. CERCURILE DIN CADRAUL I\n";
    cout<<"5. CEA MAI MARE SECVENTA DE CERCURI EGALE\n";
    cout<<"0. IESIRE\n";
}

void Repo::meniu()
{
    int ok=1,op,r;
    while(ok==1)
    {
        print_meniu();
        cout<<"Dati optiunea: ";
        cin>>op;
        if(op==1)
        {
            cout<<"Dati coordonatele centrului cercului: ";
            int a,o;
            cin>>a>>o;
            cout<<"Dati raza cercului: ";
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
        else cout<<"Optiune gresita\n";
    }
}


