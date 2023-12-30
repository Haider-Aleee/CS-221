#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    int age;
    string address;
};


void printStudentsWithAge14(Student students[], int size)  // Function to print the names of all students with age 14
{
    cout << "Students with age 14:" << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].age == 14) {
            cout << students[i].name << endl;
        }
    }
}

// Function to print the names of students with even roll numbers
void printStudentsWithEvenRollNo(Student students[], int size) {
    cout << "Students with even roll numbers:" << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].rollNo % 2 == 0) {
            cout << students[i].name << endl;
        }
    }
}

// Function to display details of a student by roll number
void displayStudentDetailsByRollNo(Student students[], int size, int rollNo) {
    for (int i = 0; i < size; i++) {
        if (students[i].rollNo == rollNo) {
            cout << "Student Details for Roll No. " << rollNo << ":" << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Address: " << students[i].address << endl;
            return; // Exit the function once the student is found
        }
    }
    // If the student with the given roll number is not found
    cout << "Student with Roll No. " << rollNo << " not found." << endl;
}

int main() {
    const int maxSize = 20; // Maximum number of students
    Student students[maxSize];

   
    students[0] = {101, "Alice", 14, "123 Main St"};
    students[1] = {102, "Bob", 13, "456 Elm St"};

    int choice;
    cout << "1 - Print names of students with age 14" << endl;
    cout << "2 - Print names of students with even roll numbers" << endl;
    cout << "3 - Display student details by roll number" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            printStudentsWithAge14(students, maxSize);
            break;
        case 2:
            printStudentsWithEvenRollNo(students, maxSize);
            break;
        case 3:
            int rollNoToFind;
            cout << "Enter the roll number to find: ";
            cin >> rollNoToFind;
            displayStudentDetailsByRollNo(students, maxSize, rollNoToFind);
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
