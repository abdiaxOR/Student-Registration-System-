#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Student.h"
#include <string>
using namespace std;

class Registration {
private:
    string filename;

public:
    Registration(const string& fname);
    void addStudent();
    void viewAllStudents();
    void searchStudent(int rollNo);
    void deleteStudent(int rollNo);
    void updateStudent(int rollNo);
};

#endif
