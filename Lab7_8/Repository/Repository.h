//
// Created by fabia on 4/6/2022.
//

#ifndef LAB7_8_REPOSITORY_H
#define LAB7_8_REPOSITORY_H
#include "Expense.h"

class Repository {
private:
    Expense* Repo;
    int noExpenses;
    int maxNoExpenses;
public:
    Repository();
    Repository(Expense* Repo, int currentSize, int maxSize);
    Repository(const Repository& repo);
    ~Repository();

    void addExpense(Expense& expense);
    int getCurrentSize() const;
    Expense getExpense(int);
    Expense* getRepo();
    int getMaxSize() const;
    void setMaxSize(int size);
    void setCurrentSize(int size);
    void setRepo(Expense* repo);
    Repository& operator=(const Repository &repo);
    void resize(Repository& repo);
};


#endif //LAB7_8_REPOSITORY_H
