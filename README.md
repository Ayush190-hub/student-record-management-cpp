
**Student Record Management System (C++)**

A **menu-driven C++ application** to manage student records efficiently using **STL containers, file handling, and clean program structure**.


## Problem Statement

Managing student data manually becomes inefficient as the number of records grows.
This project provides a **simple, structured, and reliable system** to store, search, update, and delete student records using C++.

The application also ensures that data is **persisted across program runs** using file handling.

---

## Why This Project?
I built this project to:

* Strengthen my **C++ fundamentals**
* Learn **STL containers** in real-world usage
* Understand **data structure selection** (`vector` vs `unordered_map`)
* Practice **file handling** for persistent storage
* Improve **code structuring, validation, and debugging skills**
* Gain experience with **Git & GitHub workflow**

## Features
* Add new student records
* Display all students
* Search student by roll number
* Update student details
* Delete student records
* Automatic save & load using file handling
* Input validation (duplicate roll, invalid data handling)

## TECH STACK

* **Language:** C++
* **STL Containers:**

  * `unordered_map` (fast lookup by roll number)
  * `vector` (earlier version, later optimized)
* **File Handling:** `ifstream`, `ofstream`
* **Other Concepts:**
  * `struct`
  * functions
  * loops & conditionals
  * defensive programming
* **Version Control:** Git & GitHub

## HOW TO RUN

1. Clone the repository:

   git clone <https://github.com/Ayush190-hub/student-record-management-cpp.git>

2. Navigate to the `src` directory

3. Compile the program:

   g++ main.cpp -o main
   
4. Run the executable:

   ./main

> Student data will be automatically loaded from `students.txt` if it exists.

---

## SAMPLE USAGE
----- Student Record Management System -----
1. Add Student
2. Display Students
3. Search Student
4. Delete Student
5. Update Student
6. Exit
Enter your choice:

Example:

Enter roll no: 101
Enter name: Aayuu
Enter age: 20
Enter marks: 88.5
Student added successfully!

## TIME & SPACE COMPLEXITY

* **Add / Search / Update / Delete:**

  * Average Time: **O(1)** using `unordered_map`
* **Display All Students:**

  * Time: **O(n)**
* **Space Complexity:**

  * **O(n)** for storing student records

---

## FUTURE IMPROVEMENTS

* File encryption for data security
* Sorting options (by marks, name, roll)
* Export data to CSV format
* Object-Oriented refactoring (classes)
* Unit testing & error recovery
* GUI-based interface

---

## PROJECT STATUS
**Completed (Core + Optimized Version)**
This project is fully functional and stable. Further changes would be enhancements, not fixes.
