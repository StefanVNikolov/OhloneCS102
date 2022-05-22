// Stefan Vladimirov Nikolov
// This program stores, in an array, the hours worked by
// employees who all make the same hourly wage.
#include <iostream>

#include <iomanip>

using namespace std;
int main() {
    const int NUM_EMPLOYEES = 5; // Number of employees
    int hours[NUM_EMPLOYEES]; // Array to hold hours
    double payrate; // Hourly pay rate
    double grossPay; // To hold the gross pay
    // Input the hours worked.
    cout << "Enter the hours worked by ";
    cout << NUM_EMPLOYEES << " employees who all\n";
    cout << "earn the same hourly rate.\n";

    int employeeCount = 1;
    for (int & val: hours) {
        cout << "Employee #" << employeeCount << ": ";
        cin >> val;
        employeeCount++;
    }
    employeeCount = 1;

    // Input the hourly rate for all employees.
    cout << "Enter the hourly pay rate for all the employees: ";
    cin >> payrate;
    // Display each employee's gross pay.
    cout << "Here is the gross pay for each employee:\n";
    cout << fixed << showpoint << setprecision(2);
    for (int val: hours) {
        grossPay = val * payrate;
        cout << "Employee #" << employeeCount;
        cout << ": $" << grossPay << endl;
        employeeCount++;
    }
    cin.ignore();
    cin.get();
    return 0;
}
