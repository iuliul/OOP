//
// Created by Iulia Salau on 04.05.2023.
//

#include "repository.h"
#include "repository.h"

void Repository::addStudent(Student student) {
    students.push_back(student);
}

void Repository::deleteStudent(int studentID) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->getStudentID() == studentID) {
            students.erase(it);
            break;
        }
    }
}

Student* Repository::findStudent(int studentID) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->getStudentID() == studentID) {
            return &(*it);
        }
    }
    return nullptr;
}

std::vector<Student> Repository::getAllStudents() {
    return students;
}