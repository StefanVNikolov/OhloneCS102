// This program lets the user enter a number. The
// dollarFormat function formats the number as
// a dollar amount.
#include <iostream>

#include <string>

#include <cmath>

using namespace std;
// Function prototype
string dollarFormat(int);
int main() {
    int input;
    // Get the dollar amount from the user.
    cout << "Enter a dollar amount in the form nnnnn.nn : ";
    cin >> input;
    cout << dollarFormat(input) << endl;
    cin.ignore();
    cin.get();
    return 0;
}
//************************************************************
// Definition of the dollarFormat function. This function *
// accepts a string reference object, which is assumed to *
// to hold a number with a decimal point. The function *
// formats the number as a dollar amount with commas and *
// a $ symbol. *
//************************************************************
string dollarFormat(int amount) {
    bool negative = false;
    if(amount < 0)
    {
        amount *= -1;
        negative = true;
    }
    string currency = to_string(amount);
    for (int x = log10(amount) - 2; x > 0; x -= 3)
            currency.insert(x, ",");
    if(negative)
        currency.insert(0, "-");
    return currency;
}
