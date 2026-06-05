#include <iostream>
#include "Student.h"
#include "Registration.h"
using namespace std;

int main() {
    Registration reg("students.dat");

    int choice;
    do {
        cout << "\n===== Student Registration System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        int roll;
        switch (choice) {
            case 1: reg.addStudent(); break;
            case 2: reg.viewAllStudents(); break;
            case 3:
                cout << "Enter Roll No: "; cin >> roll; cin.ignore();
                reg.searchStudent(roll); break;
            case 4:
                cout << "Enter Roll No: "; cin >> roll; cin.ignore();
                reg.deleteStudent(roll); break;
            case 5:
                cout << "Enter Roll No: "; cin >> roll; cin.ignore();
                reg.updateStudent(roll); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
