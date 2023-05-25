//
// Created by Iulia Salau on 24.05.2023.
//

#ifndef CHATGPT_SIMULAREPOO_COMPOSITION_H
#define CHATGPT_SIMULAREPOO_COMPOSITION_H
#include <iostream>
struct Composition {
    std::string artist;
    std::string title;
    std::string category;
    int votes;

    Composition() : votes(0) {}
};

#endif //CHATGPT_SIMULAREPOO_COMPOSITION_H
