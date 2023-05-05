

#ifndef LAB7_8_SERVICE_H
#define LAB7_8_SERVICE_H

#include "Repository.h"

class Service{
private:
    Repository& Repo;
public:
    Service(Repository &repo);
    Service(Repository givenRepo, Repository &repo);
    Service(const Repository &repo, Repository &repo1);
    ~Service();

    void resize(Repository& repo);

    void createElem(int, int, char*);
    int noElements();
    int sumByType(char* type);
    Expense readElem(int);
    Expense* readAllElems();
    int expenseByType(char* type, Expense*& neededExpenses);
    void filterByType(char* type);
    void updateElem(int, int, int, char*);
    void deleteElem(int);

};


#endif //LAB7_8_SERVICE_H
