#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;

    cout << "Enter roll no: ";
    cin >> s.roll;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter age: ";
    cin >> s.age;

    cout << "Enter marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "Student added successfully..!!" << endl;
}

void displayStudents() {
    if (students.size() == 0) {
        cout << "No Students Found..!" << endl;
        return;
    } else {
        cout << "--- Student Records ---" << endl;
        for (int i=0; i<students.size(); i++) {
            cout << "Roll no: " << students[i].roll << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Marks: " << students[i].marks << endl;
            cout << "----------------------" << endl;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n----- Student Record Management System -----\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                cout << "Search feature coming soon...\n";
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

