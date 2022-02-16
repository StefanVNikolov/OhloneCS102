// Stefan Nikolov
// This program calculates the Amount in Savings
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    // Initializing the variables
    double interestRate, timesCompounded, principal, interest, savingsAmount;

    // Displaying the Loan holder
    cout << "Stefan Nikolov's Loan" << endl;

    // Entering the input information
    cout << "Please enter the following:" << endl;
    cout << "Interest Rate (in %)    ";
    cin >> interestRate;

    cout << "Times Compounded:         ";
    cin >> timesCompounded;

    cout << "Principal:         $ ";
    cin >> principal;

    // Calculating the result
    savingsAmount = principal*pow((1+((interestRate/100)/timesCompounded)),timesCompounded);
    interest = savingsAmount - principal;

    // Displaying the final result
    cout << endl;
    cout << "Interest:          $   "<<setprecision(4)<<interest << endl;
    cout << "Amount in Savings: $ "<<setprecision(6)<<savingsAmount << endl;

    cin.ignore();
    cin.get();
    return 0;
}
