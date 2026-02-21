#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
    int roll;
    string name;
    int age;
    float marks;
};

unordered_map<int, Student> studentMap;
const string FILE_NAME = "students.txt";

void saveFile() {
    ofstream fout(FILE_NAME);

    if (!fout) {
        cout << "Error opening file for saving \n";
        return;
    }
    for (const auto &entry : studentMap) {
        const Student &s = entry.second;
        fout << s.roll << "|"
             << s.name << "|"
             << s.age << "|"
             << s.marks << "\n";
    }

    fout.close();
}

void loadFromFile() {
    ifstream fin(FILE_NAME);

    if (!fin) {


        return;
    }

    studentMap.clear();

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        Student s;
        string temp;

        getline(ss, temp, '|');
        s.roll = stoi(temp);

        getline(ss,temp,'|');
        s.name = temp;

        getline(ss, temp, '|');
        s.age = stoi(temp);

        getline(ss, temp, '|');
        s.marks = stof(temp);

        studentMap[s.roll] = s;
    }

    fin.close();
}

// ---------- Utility ----------
bool isEmpty() {
    if (studentMap.empty()) {
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
    cout << "6. Saving Data and Exit\n";
    cout << "Enter your choice: ";
}

// ---------- CRUD ----------
void addStudent() {
    Student s;

    cout << "Enter roll no: ";
    cin >> s.roll;
    clearInput();

    if (studentMap.find(s.roll) != studentMap.end()) {
        cout << "Duplicate roll number not allowed.\n";
        return;
    }

    cout << "Enter name: ";
    getline(cin, s.name);

    cout << "Enter age: ";
    cin >> s.age;

    cout << "Enter marks: ";
    cin >> s.marks;

    studentMap[s.roll] = s;

    cout << "Student added successfully.\n";
}


void displayStudents() {
    if (isEmpty()) return;

    cout << "\n--- Student Records ---\n";

    for (const auto &entry : studentMap) {
        const Student &s = entry.second;

        cout << "Roll: " << s.roll << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Marks: " << s.marks << endl;
        cout << "----------------------\n";
    }
}


void searchStudent() {
    if (isEmpty()) return;

    int roll;
    cout << "Enter roll to search: ";
    cin >> roll;

    auto it = studentMap.find(roll);
    if (it != studentMap.end()) {
        Student s = it->second;
        cout << "\nStudent Found\n";
        cout << "Roll: " << s.roll << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Marks: " << s.marks << endl;
    } else {
        cout << "Student not found.\n";
    }
}

void deleteStudent() {
    if (isEmpty()) return;

    int roll;
    cout << "Enter roll to delete: ";
    cin >> roll;

    if (studentMap.erase(roll)) {
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void updateStudent() {
    if (isEmpty()) return;

    int roll;
    cout << "Enter roll to update: ";
    cin >> roll;
    clearInput();

    auto it = studentMap.find(roll);
    if (it == studentMap.end()) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter new name: ";
    getline(cin, it->second.name);

    cout << "Enter new age: ";
    cin >> it->second.age;

    cout << "Enter new marks: ";
    cin >> it->second.marks;

    cout << "Student updated successfully.\n";
}

// ---------- MAIN ----------
int main() {

    loadFromFile();
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
                saveFile();
                cout << "Data Saved..!! Exiting Program..\n"; 
                break;

            case 7: 
                cout << "Exiting program...\n"; 
                break;

            default: 
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);
                                    
    return 0;
}
 