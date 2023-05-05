//
// Created by fabia on 4/18/2022.
//

#ifndef LAB7_8_UI_H
#define LAB7_8_UI_H


#include "Service.h"

class UI {
private:
    Service& service;
public:
    UI(Service& service);
    ~UI();

    void addExpenseUI();
    void showExpenseUI();
    void showAllExpensesUI();
    void updateExpenseUI();
    void deleteExpenseUI();
    void showSumExpenseTypeUI();
    void showExpenseByType();
    void filterExpenseByTypeUI();
    void readProcedure(int& day, int& moneySpent, char*& type);
    void showMenu();
    void console(char&);
    void runMenu();
};


#endif //LAB7_8_UI_H
