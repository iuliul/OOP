#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include "student.h"

class Repository {
private:
    std::vector<Student> students;

public:
    void addStudent(Student student);
    void deleteStudent(int studentID);
    Student* findStudent(int studentID);
    std::vector<Student> getAllStudents();
};

#endif