#include <iostream>
#include "repository.h"
#include "teste.h"

using namespace std;

int main() {
    Repository repo;

    Student s1("Ion", "Iulia", 12345);
    Student s2("Oana", "Iulia", 67890);
    repo.addStudent(s1);
    repo.addStudent(s2);

    cout << "Lista de studenti din repository: " << endl;
    vector<Student> allStudents = repo.getAllStudents();
//    for (const auto& student : allStudents) {
//        cout << student.getLastName() << " " << student.getFirstName() << " (" << student.getStudentID() << ")" << endl;
//    }
//    cout << endl;

    cout << "Introduceti ID-ul studentului pe care doriti sa il cautati: ";
    int id;
    cin >> id;
    Student* foundStudent = repo.findStudent(id);
    if (foundStudent == nullptr) {
        cout << "Nu s-a gasit niciun student cu ID-ul dat" << id << "." << endl;
    }
    else {
//        cout << "Studentul gasit: " << foundStudent->getLastName() << " " << foundStudent->getFirstName() << endl;
    }
    cout << endl;

    cout << "Introduceti ID-ul studentului pe care doriti sa il stergeti: ";
    cin >> id;
    repo.deleteStudent(id);
    allStudents = repo.getAllStudents();
//    cout << "Lista actualizata de studenti din repository: " << endl;
//    for (const auto& student : allStudents) {
//        cout << student.getLastName() << " " << student.getFirstName() << " (" << student.getStudentID() << ")" << endl;
//    }
//    cout << endl;

    Teste::runAllTests();

    return 0;
}