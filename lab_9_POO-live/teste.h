#ifndef LAB9_10POO_TESTE_H
#define LAB9_10POO_TESTE_H


#define TESTE_H

#include "repository.h"

class Teste {
public:
    static void runAllTests();
    static void testAddStudent(Repository& repo);
    static void testDeleteStudent(Repository& repo);
    static void testFindStudent(Repository& repo);
    static void testGetAllStudents(Repository& repo);
};


#endif //LAB9_10POO_TESTE_H
