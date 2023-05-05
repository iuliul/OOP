
#include <cstring>
#include "Expense.h"
#include <iostream>
using namespace std;

Expense::Expense() {
    this->day=0;
    this->moneySpent = 0;
    this->type = nullptr;
}

Expense::Expense(int day, int moneySpent, char* type) {
    this->setDay(day);
    this->setMoneySpent(moneySpent);
    this->type = nullptr;
    this->setType(type);
}

Expense::Expense(const Expense &expense) {
    this->day = expense.day;
    this->moneySpent = expense.moneySpent;
    this->type = new char[strlen(expense.type) + 1];
    strcpy(this->type, expense.type);
}

Expense::~Expense() {
    if (this->type != nullptr){
        delete[] this->type;
        this->type = nullptr;
    }
}

int Expense::getDay() const {
    return this->day;
}

int Expense::getMoneySpent() const {
    return this->moneySpent;
}

char * Expense::getType() const {
    return this->type;
}

void Expense::setDay(int givenDay) {
    this->day = givenDay;
}

void Expense::setMoneySpent(int givenMoneySpent) {
    this->moneySpent = givenMoneySpent;
}

void Expense::setType(char *givenType) {
//    if(this->type != nullptr){
//        delete[] this->type;
//        this->type = nullptr;
//    }

    this->type = new char[strlen(givenType) + 1];
    strcpy(this->type, givenType);
}


Expense& Expense::operator=(const Expense &expense){
    this->setDay(expense.day);
    this->setMoneySpent(expense.moneySpent);
    this->type = nullptr;
    this->setType(expense.getType());
    return *this;
}

bool Expense::operator==(const Expense &expense){
    if(this->day == expense.day)
        if(this->moneySpent == expense.moneySpent)
            if(strcmp(this->type, expense.type) == 0)
                return true;
    return false;
}

ostream& operator<<(ostream& os, Expense& expense){
    os << "Your expense is on the day: " << expense.getDay() << std::endl <<
    "You spent: " << expense.getMoneySpent() << std::endl <<
    "Your type of expense is: " << expense.getType();
    return os;
}