#include "Tests/Tests.h"
#include "UI.h"
#include "Service.h"
int main(){

    testAll();
    Repository repo;
    Service service(repo);
    UI userInterface = UI(service);
    userInterface.runMenu();

    return 0;
}

