#include "Service.h"
#include <iostream>
#include <cstring>

using namespace std;
Service::Service(Repository &repo) : Repo(repo) {
    this->Repo.setCurrentSize(0);
    this->Repo.setMaxSize(4);
}

Service::Service(Repository givenRepo, Repository &repo) : Repo(repo) {
    this->Repo.setCurrentSize(givenRepo.getCurrentSize());
    this->Repo.setMaxSize(givenRepo.getMaxSize());
}

Service::Service(const Repository &repo, Repository &repo1) : Repo(repo1) {
}

Service::~Service() {

}

void Service::createElem(int givenDay, int givenMoneySpent, char* givenType) {
    if (this->Repo.getCurrentSize() == this->Repo.getMaxSize())
        resize(this->Repo);
    Expense newExpense(givenDay, givenMoneySpent, givenType);
    Repo.addExpense(newExpense);
}
Expense Service::readElem(int id) {
    return this->Repo.getExpense(id);
}

Expense* Service::readAllElems() {
    return this->Repo.getRepo();
}

void Service::updateElem(int id, int newDay, int newMoneySpent, char* newType) {
    Expense updatedExpense = Expense(newDay, newMoneySpent, newType);
    Expense* Expenses = readAllElems();
    Expenses[id] = updatedExpense;
    this->Repo.setRepo(Expenses);
}

void Service::deleteElem(int id) {
    Expense* Expenses = this->Repo.getRepo();
    int size = this->noElements() - 1;
    for(int i = id; i < size; i++)
        Expenses[i] = Expenses[i + 1];
    this->Repo.setRepo(Expenses);
    this->Repo.setCurrentSize(size);

}

int Service::noElements(){
    return this->Repo.getCurrentSize();
}

void Service::resize(Repository& repo) {
    int newSize = repo.getMaxSize() * 2;
    auto* newArr = new Expense[newSize];
    Expense* expenses = repo.getRepo();
    for (int i = 0; i < repo.getMaxSize(); i ++)
        newArr[i] = expenses[i];

    repo.setMaxSize(newSize);
    if (expenses != nullptr)
    {
        delete[] expenses;
        expenses = nullptr;
    }
    repo.setRepo(newArr);
}

int Service::sumByType(char* type){
    Expense* allExpenses = readAllElems();
    int sum = 0;
    for(int i = 0; i < noElements(); i++)
        if (strcmp(allExpenses[i].getType(), type) == 0)
            sum += allExpenses[i].getMoneySpent();
    return sum;
}

int Service::expenseByType(char* type, Expense*& neededExpenses){
    Expense* allExpenses = readAllElems();
    int k = 0;
    for(int i = 0; i < noElements(); i++)
        if(strcmp(allExpenses[i].getType(), type) == 0)
            neededExpenses[k++] = allExpenses[i];
    return k;
}

void Service::filterByType(char* type){
    auto* filteredExpenses = new Expense[noElements()];
    Expense* allExpenses = readAllElems();
    int k = 0;
    for(int i = 0; i < noElements(); i++)
        if(strcmp(allExpenses[i].getType(), type) == 0)
            filteredExpenses[k++] = allExpenses[i];
    this->Repo.setRepo(filteredExpenses);
    this->Repo.setCurrentSize(k);
}

