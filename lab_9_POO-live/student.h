#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    char* firstName;
    char* lastName;
    int studentID;

public:
    char* getLastName();
    char* getFirstName();
    int getStudentID();
    Student();
    Student(char* firstName, char* lastName, int studentID);
    void setFirstName(char* firstName);
    void setLastName(char* lastName);
    void setStudentID(int studentID);
};

#endif