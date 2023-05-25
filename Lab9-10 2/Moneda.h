#ifndef LAB9_10_MONEDA_H
#define LAB9_10_MONEDA_H


class Moneda {
private:
    int valoare;
    int cantitate;
public:
    Moneda(int valoare, int cantitate);
    int getValoare() const;
    int getCantitate() const;
    void setValoare(int valoare);
    void setCantitate(int cantitate);

};



#endif //LAB9_10_MONEDA_H
