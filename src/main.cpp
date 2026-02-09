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

int main() {
    int choice;

    cout << "Student Record Management System" << endl;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Display Students"<<endl;
    cout<<"3. Search Student"<<endl;
    cout<<"4. Exit"<<endl;

    cout<<"Enter your choice: "<<endl;
    cin>> choice;

    cout<< "Project setup successful!" << endl;
 
    return 0;
}
