
#ifndef LAB7_8_EXPENSE_H
#define LAB7_8_EXPENSE_H
#include <iostream>
using namespace std;
class Expense {
private:
    int day;
    int moneySpent;
    char* type;
public:
    //constructs + destructor
    Expense();
    Expense(int, int, char*);
    Expense(const Expense& expense);
    ~Expense();
    // getters + setters
    int getDay() const;
    int getMoneySpent() const;
    char * getType() const;
    void setDay(int);
    void setMoneySpent(int);
    void setType(char*);

    Expense& operator=(const Expense &expense);
    bool operator==(const Expense &expense);

    friend ostream& operator<<(ostream& os, Expense& expense);
};


#endif //LAB7_8_EXPENSE_H
