#include "student.h"

Student::Student() {}

Student::Student(char* firstName, char* lastName, int studentID) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->studentID = studentID;
}

char* Student::getFirstName() {
//    return firstName;
}

void Student::setFirstName(char* firstName) {
    this->firstName = firstName;
}

char* Student::getLastName() {
//    return lastName;
}

void Student::setLastName(char* lastName) {
    this->lastName = lastName;
}

int Student::getStudentID() {
    return studentID;
}

void Student::setStudentID(int studentID) {
    this->studentID = studentID;
}
