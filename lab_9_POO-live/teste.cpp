#include "teste.h"
#include <iostream>
#include "teste.h"

void Teste::runAllTests() {
    Repository repo;

    std::cout << "Ruleaza..." << std::endl;

    testAddStudent(repo);
    testDeleteStudent(repo);
    testFindStudent(repo);
    testGetAllStudents(repo);

    std::cout << "Toate bune!" << std::endl;
}

void Teste::testAddStudent(Repository& repo) {
    Student s1("Ion", "Iulia", 12345);
    repo.addStudent(s1);
    Student* result = repo.findStudent(12345);
    if (result == nullptr || result->getStudentID() != s1.getStudentID()) {
        std::cout << "Nu i bine: addStudent" << std::endl;
    }
}

void Teste::testDeleteStudent(Repository& repo) {
    Student s1("Ion", "Iulia", 12345);
    repo.addStudent(s1);
    repo.deleteStudent(12345);
    Student* result = repo.findStudent(12345);
    if (result != nullptr) {
        std::cout << "Nu i bine: deleteStudent" << std::endl;
    }
}

void Teste::testFindStudent(Repository& repo) {
    Student s1("Ion", "Iulia", 12345);
    repo.addStudent(s1);
    Student* result = repo.findStudent(12345);
    if (result == nullptr || result->getStudentID() != s1.getStudentID()) {
        std::cout << "Nu i bine nici asa: findStudent" << std::endl;
    }
}

void Teste::testGetAllStudents(Repository& repo) {
    Student s1("Ion", "Iulia", 12345);
    Student s2("Oana", "Iulia", 67890);
    repo.addStudent(s1);
    repo.addStudent(s2);
    std::vector<Student> result = repo.getAllStudents();
    if (result.size() != 2 || result[0].getStudentID() != s1.getStudentID() || result[1].getStudentID() != s2.getStudentID()) {
        std::cout << "Nu i bine: getAllStudents" << std::endl;
    }
}