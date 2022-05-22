// This program raises the user's number to the powers of 0 through 10.
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int value, currentPower;
    char choice;
    cout << "Enter a number: ";
    cin >> value;
    cout << "This program will raise " << value;
    cout << " to the powers of 0 through 10.\n";

    while((choice != 'Q' && choice != 'q') && currentPower <= 10){
        cout << value << " raised to the power of ";
        cout << currentPower << " is " << pow(value, currentPower);
        cout << "\nEnter Q to quit or any other key to continue. ";
        cin >> choice;
        currentPower++;
    }
    return 0;
}
