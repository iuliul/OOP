#include <cassert>
#include <cstring>
#include "Tests.h"
#include "Expense.h"
#include "Repository.h"
#include "Service.h"
using namespace std;
#include <iostream>
Expense testExpense(2, 100, (char*)"factura");
Expense testExpense1(3, 120, (char*)"factura DIGI");
Expense testExpense2(4, 130, (char*)"factura RENEL");
Expense testExpense5(7, 130, (char*)"factura catena");

void testGetDay(){
    assert(testExpense.getDay() == 2);
}
void testGetMoneySpent(){
    assert(testExpense.getMoneySpent() == 100);
}

void testGetType(){
    int cmpResult = strcmp("factura", testExpense.getType());
    assert(cmpResult == 0);
}

//Repo tests
void testGetSize(){
    Repository repo;
    repo.addExpense(testExpense);
    repo.addExpense(testExpense1);
    repo.addExpense(testExpense2);
    assert(repo.getCurrentSize() == 3);
}

void testServiceUpdate(){
    Repository repo;
    Service service(repo);
    service.createElem(2, 100, (char*)"factura");
    service.updateElem(0, 7, 130, (char*)"factura catena");
    assert(service.readElem(0) == testExpense5);
}

void testServiceCreate(){
    Repository repo;
    Service service(repo);
    service.createElem(7, 130, (char*)"factura catena");
//  cout << testExpense5;
    assert(service.readElem(0) == testExpense5);
}

void testServiceDelete(){
    Repository repo;
    Service service(repo);
    service.createElem(7, 130, (char*)"factura catena");
    service.createElem(2, 100, (char*)"factura");
    service.deleteElem(0);
    assert(service.readElem(0) == testExpense);

}

void testSumByTypeService(){
    Repository repo;
    Service service(repo);
    service.createElem(2, 100, (char*)"factura");
    service.createElem(3, 120, (char*)"factura_DIGI");
    service.createElem(4, 150, (char*)"factura");
    service.createElem(6, 140, (char*)"factura_naspa");
    service.createElem(7, 130, (char*)"factura");
    int sum = service.sumByType((char*)"factura");
    assert(sum == 380);
}

void testResize(){
    Repository repo;
    Service service(repo);
    service.createElem(2, 100, (char*)"factura");
    service.createElem(3, 120, (char*)"factura DIGI");
    service.createElem(4, 150, (char*)"factura renel");
    service.createElem(6, 140, (char*)"factura naspa");
    service.createElem(7, 130, (char*)"factura catena");
    assert(service.readElem(4) == testExpense5);
}



//all tests
void testAll(){
    testGetDay();
    testGetMoneySpent();
    testGetType();
    testGetSize();
    testResize();
    testServiceUpdate();
    testServiceCreate();
    testServiceDelete();
    testSumByTypeService();
}