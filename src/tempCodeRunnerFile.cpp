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

vector<Student> students;

int main() {
    int choice;

    cout << "Student Record Management System" << endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Display Students"<<endl;
    cout<<"3. Search Student"<<endl;
    cout<<"4. Exit"<<endl;

    cout<<"Enter your choice: "<<endl;
    cin>> choice;

    if (choice == 1) {
        addStudent();
    }

    return 0;
}
