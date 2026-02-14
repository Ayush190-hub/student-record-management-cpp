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

void searchStudent() {
    if (students.size() == 0) {
        cout << "No Students available to search..!!" << endl;
        return;
    } else {
        int roll;
        cout << "Enter Roll no. to search: ";
        cin >> roll;

        bool found = false;

        for (int i=0; i<students.size(); i++) {
            if (students[i].roll == roll) {
                cout << "Student Found..!!" << endl;
                cout << "Roll: " << students[i].roll << endl;
                cout << "Name: " << students[i].name << endl;
                cout << "Age: " << students[i].age << endl;
                cout << "Marks: " << students[i].marks << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with Roll" << roll << "not found" << endl;
        }
    }
}

void deleteStudent() {
    if (students.size() == 0) {
        cout << "No Student to display..!!" << endl;
        return;
    } else {
        int roll;
        cout << "Enter roll no to detele" << endl;
        cin >> roll;

        bool deleted = false;

        for (int i=0; i<students.size(); i++){
            if (students[i].roll == roll) {
                students.erase(students.begin() + i);
                cout << "Student deleted successfully..!!" << endl;
                deleted = true;
                break;
            }
        }
        if (!deleted) {
            cout << "Student with roll no: " << roll << "Not found" << endl;
        }
    }
}

void updateStudent() {
    if (students.size() == 0) {
        cout << "No Student is available for update" << endl;
        return;
    } else {
        int roll;
        cout << "Enter roll no to update";
        cin >> roll;

        bool updated = false;

        for (int i=0; i<students.size(); i++) {
            if (students[i].roll == roll) {
                cout <<"\nUpdating student record\n";

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, students[i].name);

                cout <<"Enter age: ";
                cin >> students[i].age;

                cout <<"Enter marks: ";
                cin >> students[i].marks;

                updated = true;
                cout << "Student updated successfully" << endl;
                break;
            }
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
        cout << "4. Delete Student\n";
        cout << "5. Update Student data";
        cout << "6. Exit the program\n";

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
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                updateStudent();
                break;

            case 6:
                cout << "Exit the program\n";

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

