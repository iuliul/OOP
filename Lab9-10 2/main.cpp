#include <iostream>
#include "Test.h"
#include "TonomatService.h"
#include "TonomatService.h"
#include "TonomatRepositoryFile.h"
#include "UI.h"

int main() {
    test();
    TonomatRepositoryFile repository("produse.txt");

    TonomatService service(repository);
    TonomatUI ui(service);
    ui.meniuPrincipal();

    return 0;
}
