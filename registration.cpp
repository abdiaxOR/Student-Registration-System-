#include "Registration.h"
#include <fstream>
#include <iostream>
using namespace std;

Registration::Registration(const string& fname) {
    filename = fname;
}

void Registration::addStudent() {
    Student s;
    s.input();

    ofstream fout(filename, ios::binary | ios::app);
    if (!fout) {
        cout << "Error opening file!" << endl;
        return;
    }
    fout.write(reinterpret_cast<char*>(&s), sizeof(Student));
    fout.close();
    cout << "Student added successfully!\n";
}

void Registration::viewAllStudents() {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "No records found!" << endl;
        return;
    }

    Student s;
    while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        s.display();
    }
    fin.close();
}

void Registration::searchStudent(int rollNo) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cout << "No records found!" << endl;
        return;
    }

    Student s;
    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.rollNo == rollNo) {
            cout << "Student found:\n";
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student with Roll No " << rollNo << " not found!\n";

    fin.close();
}

void Registration::deleteStudent(int rollNo) {
    ifstream fin(filename, ios::binary);
    ofstream temp("temp.dat", ios::binary);
    if (!fin || !temp) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    bool found = false;
    while (fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.rollNo == rollNo) {
            found = true;
            continue;
        }
        temp.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }

    fin.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.dat", filename.c_str());

    if (found)
        cout << "Student deleted successfully!\n";
    else
        cout << "Student with Roll No " << rollNo << " not found!\n";
}

void Registration::updateStudent(int rollNo) {
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }

    Student s;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.rollNo == rollNo) {
            cout << "Enter new details:\n";
            s.input();
            file.seekp(-static_cast<int>(sizeof(Student)), ios::cur);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            found = true;
            cout << "Student updated successfully!\n";
            break;
        }
    }

    if (!found)
        cout << "Student with Roll No " << rollNo << " not found!\n";

    file.close();
}
