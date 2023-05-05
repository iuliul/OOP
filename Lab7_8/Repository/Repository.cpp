#include "Repository.h"
#include <iostream>
using namespace std;
Repository::Repository() {
    this->noExpenses = 0;
    this->maxNoExpenses = 4;
    this->Repo = new Expense[4];
}

Repository::Repository(Expense *Repo, int size, int maxSize) {
    this->noExpenses = size;
    this->maxNoExpenses = maxSize;
    this->Repo = new Expense[size];
    for(int i = 0; i < size; i++)
        this->Repo[i] = Repo[i];
}

Repository::Repository(const Repository &repo) {
    this->noExpenses = repo.getCurrentSize();
    this->maxNoExpenses = repo.getMaxSize();
    this->Repo = new Expense[repo.getCurrentSize()];
    for(int i = 0; i < repo.getCurrentSize(); i++)
        this->Repo[i] = Repo[i];
}

Repository::~Repository(){
    if (this->Repo != nullptr)
    {
        delete[] this->Repo;
        this->Repo = nullptr;
    }
}

void Repository::addExpense(Expense &expense) {
    this->Repo[this->noExpenses++] = expense;
}

int Repository::getCurrentSize() const {
    return this->noExpenses;
}
Expense Repository::getExpense(int position){
    return this->getRepo()[position];
}

Expense* Repository::getRepo() {
    return this->Repo;
}

void Repository::setCurrentSize(int size) {
    this->noExpenses = size;
}

void Repository::setRepo(Expense *repo) {
    this->Repo = repo;
}

int Repository::getMaxSize() const {
    return this->maxNoExpenses;
}

void Repository::setMaxSize(int size) {
    this->maxNoExpenses = size;
}

Repository& Repository::operator=(const Repository &repo) {
    this->setRepo(repo.Repo);
    this->setCurrentSize(repo.getCurrentSize());
    this->setMaxSize(repo.getMaxSize());
    return *this;
}

