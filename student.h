#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    char name[50];
    char course[50];
    int year;

    void input();
    void display() const;
};

#endif
