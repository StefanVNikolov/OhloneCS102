// This program demonstrates a function that uses a
// pointer to a structure variable as a parameter.
#include <iostream>

#include <string>

#include <iomanip>

#include <stdio.h>

#include <string.h>

using namespace std;

const int ARRAY_SIZE = 20;
struct Student {
    char name[ARRAY_SIZE]; // Student's name
    int idNum; // Student ID number
    double creditHours; // Credit hours enrolled
    double gpa; // Current GPA
};
void getData(Student * ); // Function prototype
int main() {
    Student freshman;
    // Get the student data.
    cout << "Enter the following student data:\n";
    getData( & freshman); // Pass the address of freshman.
    cout << "\nHere is the student data you entered:\n";
    // Now display the data stored in freshman
    cout << setprecision(3);
    cout << "Name: " << freshman.name << endl;
    cout << "ID Number: " << freshman.idNum << endl;
    cout << "Credit Hours: " << freshman.creditHours << endl;
    cout << "GPA: " << freshman.gpa << endl;
    return 0;
}
//*******************************************************
// Definition of function getData. Uses a pointer to a *
// Student structure variable. The user enters student *
// information, which is stored in the variable. *
//*******************************************************
void getData(Student * s) {
    cout << "Student name: ";
    cin.getline(s -> name, ARRAY_SIZE);
    cout << "Student ID Number: ";
    cin >> s -> idNum;
    cout << "Credit Hours Enrolled: ";
    cin >> s -> creditHours;
    cout << "Current GPA: ";
    cin >> s -> gpa;
}
