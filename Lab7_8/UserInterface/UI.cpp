
#include "Service.h"
#include "UI.h"
#include <iostream>
#include <cstring>

UI::UI(Service& service) : service(service)
{

}

UI::~UI()
{
}

void UI::readProcedure(int& day, int& moneySpent, char*& type){
    std::cout << "Enter the day of the expense: ";
    std::cin >> day;
    std::cout << std::endl;
    std::cout << "Enter the amount you spent: ";
    std::cin >> moneySpent;
    std::cout << std::endl;
    std::cout << "Enter the type of expense: ";
    std::cin >> type;
    std::cout << std::endl;
}

void UI::addExpenseUI() {
    int day, moneySpent;
    char* type = new char[25];
    readProcedure(day, moneySpent, type);
    this->service.createElem(day, moneySpent, type);
    delete[] type;
}

void UI::showExpenseUI() {
    std::cout << "What expense do you want to check? " << std::endl;
    int expenseID;
    std::cin >> expenseID;
    Expense neededExpense = this->service.readElem(expenseID);
    std::cout << neededExpense << std::endl;
}

void UI::showAllExpensesUI(){
    std::cout << "These are all your expenses: " << std::endl;
    int noExpenses = service.noElements();
    Expense* expenses = service.readAllElems();
    for (int i = 0; i < noExpenses; i++)
        cout << i <<". " << expenses[i] << std::endl;
}

void UI::updateExpenseUI() {
    int day, moneySpent, id;
    char* type = new char[25];
    showAllExpensesUI();
    std::cout << "Which of the expenses you want to change? ";
    std::cin >> id;
    readProcedure(day, moneySpent, type);
    this->service.updateElem(id, day, moneySpent, type);
    delete[] type;
}

void UI::deleteExpenseUI(){
    int id;
    showAllExpensesUI();
    std::cout << "Which of the expenses you want to delete? ";
    std::cin >> id;
    this->service.deleteElem(id);

}

void UI::showSumExpenseTypeUI(){
    char* type = new char[25];
    cout << "Enter the type of expenses you want to see the sum of: ";
    cin>>type;
    int sum = this->service.sumByType(type);
    cout << endl << "The sum you requested is: " << sum << endl;
    delete[] type;
}

void UI::filterExpenseByTypeUI(){
    char* type = new char[25];
    cout << "Enter the type of expense you want the filter to be based on: ";
    cin>>type;
    this->service.filterByType(type);
    delete[] type;
}

void UI::showExpenseByType(){
    char* type = new char[25];
    cout << "Enter the type of expenses you want to see: ";
    cin>>type;
    auto* neededExpenses = new Expense[this->service.noElements()];
    int noExpenses = this->service.expenseByType(type, neededExpenses);
    for(int i = 0; i < noExpenses; i++)
        cout << i <<". " << neededExpenses[i] << std::endl;
    delete[] neededExpenses;
    delete[] type;
}



void UI::showMenu(){
    std::cout << std::endl;
    std::cout << "1.Add expense" << std::endl;
    std::cout << "2.Show expense" << std::endl;
    std::cout << "3.Show all expenses" << std::endl;
    std::cout << "4.Update expense" << std::endl;
    std::cout << "5.Delete expense" << std::endl;
    std::cout << "6.Sum of specific expense" << std::endl;
    std::cout << "7.Show expenses by type" << std::endl;
    std::cout << "8.Filter expenses by type" << std::endl;
//    std::cout << "9." << std::endl;
//    std::cout << "10." << std::endl;
    std::cout << "m. Show menu" << std::endl;
    std::cout << "x. Exit" << std::endl;
}


void UI::console(char& option){
    this->showMenu();
    std::cout << "Choose your option: ";
    std::cin >> option;
    std::cout << std::endl;
}

void UI::runMenu() {
    bool run = true;
    while(run)
    {
        char option;
        console(option);
        switch (option){

            case '1':
            {
                addExpenseUI();
                break;
            }

            case '2':
            {
                showExpenseUI();
                break;
            }
            case '3':
            {
                showAllExpensesUI();
                break;
            }
            case '4':
            {
                updateExpenseUI();
                break;
            }
            case '5':
            {
                deleteExpenseUI();
                break;
            }
            case '6':
            {
                showSumExpenseTypeUI();
                break;
            }
            case '7':
            {
                showExpenseByType();
                break;
            }
            case '8':
            {
                filterExpenseByTypeUI();
                break;
            }

            case 'x':
            {
                run = false;
                break;
            }

            case 'm':
            {
                showMenu();
                break;
            }

            default:
                std::cout << "Invalid option. Try again!";
                std::cout << std::endl;
        }
    }


}