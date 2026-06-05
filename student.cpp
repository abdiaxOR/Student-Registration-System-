#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

void Student::input() {
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cin.ignore(); // clear input buffer

    cout << "Enter Name: ";
    cin.getline(name, 50);

    cout << "Enter Course: ";
    cin.getline(course, 50);

    cout << "Enter Year: ";
    cin >> year;
    cin.ignore();
}

void Student::display() const {
    cout << "Roll No: " << rollNo << endl;
    cout << "Name: " << name << endl;
    cout << "Course: " << course << endl;
    cout << "Year: " << year << endl;
    cout << "----------------------" << endl;
}
