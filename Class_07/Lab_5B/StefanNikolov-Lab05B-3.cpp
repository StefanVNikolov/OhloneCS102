// Stefan Nikolov
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // Enter input
    double initialDeposit, interestRate;
    double interest;
    int years;

    cout << "What is the inital deposit? ";
    cin >> initialDeposit;

    while(initialDeposit <= 0){
        cout << "Must be greater than 0. Re-enter: ";
        cin >> initialDeposit;

    }

    cout << "Annual interest rate (as percent)? ";
    cin >> interestRate;

    while(interestRate <= 0){
        cout << "Invalid, must be greater than 0. Re-enter: ";
        cin >> interestRate;

    }

    cout << "Number of years on deposit? ";
    cin >> years;

    while(interestRate <= 0){
        cout << "Invalid, must be greater than 0. Re-enter: ";
        cin >> years;

    }

    cout << "Let's see how your money grows!\n";
    cout << "Year Balance\n";
    cout << setprecision(2) << fixed;
    interest = initialDeposit;

    for (int i = 1; i <= years; i++) {
            interest = interest + interest*(interestRate/100);
        cout << i << "    " <<interest<< endl;
    }
    cout << "Total interest earned is $ " << interest-initialDeposit<<endl;


    cin.ignore();
    cin.get();
    return 0;
}
