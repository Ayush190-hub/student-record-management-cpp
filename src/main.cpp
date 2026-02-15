#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Student {
    int roll;
    string name;
    int age;
    float marks;
};

vector<Student> studentList;

// ---------- Utility ----------
bool isEmpty() {
    if (studentList.empty()) {
        cout << "No students found.\n";
        return true;
    }
    return false;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------- Menu ----------
void showMenu() {
    cout << "\n----- Student Record Management System -----\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Update Student\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// ---------- CRUD ----------
void addStudent() {
    Student s;

    cout << "Enter roll no: ";
    cin >> s.roll;
    clearInput();

    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter age: ";
    cin >> s.age;

    cout << "Enter marks: ";
    cin >> s.marks;

    studentList.push_back(s);
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (isEmpty()) return;

    cout << "\n--- Student Records ---\n";
    for (size_t i = 0; i < studentList.size(); i++) {
        cout << "Roll: " << studentList[i].roll << endl;
        cout << "Name: " << studentList[i].name << endl;
        cout << "Age: " << studentList[i].age << endl;
        cout << "Marks: " << studentList[i].marks << endl;
        cout << "----------------------\n";
    }
}

void searchStudent() {
    if (isEmpty()) return;

    int roll;
    cout << "Enter roll to search: ";
    cin >> roll;

    bool found = false;
    for (size_t i = 0; i < studentList.size(); i++) {
        if (studentList[i].roll == roll) {
            cout << "\nStudent Found\n";
            cout << "Roll: " << studentList[i].roll << endl;
            cout << "Name: " << studentList[i].name << endl;
            cout << "Age: " << studentList[i].age << endl;
            cout << "Marks: " << studentList[i].marks << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student with roll " << roll << " not found.\n";
}

void deleteStudent() {
    if (isEmpty()) return;

    int roll;
    cout << "Enter roll to delete: ";
    cin >> roll;

    for (size_t i = 0; i < studentList.size(); i++) {
        if (studentList[i].roll == roll) {
            studentList.erase(studentList.begin() + i);
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student with roll " << roll << " not found.\n";
}

void updateStudent() {
    if (isEmpty()) return;

    int roll;
    cout << "Enter roll to update: ";
    cin >> roll;
    clearInput();

    for (size_t i = 0; i < studentList.size(); i++) {
        if (studentList[i].roll == roll) {
            cout << "Enter new name: ";
            getline(cin, studentList[i].name);

            cout << "Enter new age: ";
            cin >> studentList[i].age;

            cout << "Enter new marks: ";
            cin >> studentList[i].marks;

            cout << "Student updated successfully.\n";
            return;
        }
    }

    cout << "Student with roll " << roll << " not found.\n";
}

// ---------- MAIN ----------
int main() {
    int choice;

    do {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

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
                cout << "Exiting program...\n"; 
                break;

            default: 
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
 