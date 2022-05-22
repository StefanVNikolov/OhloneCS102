// Stefan Nikolov
#include <iostream>
using namespace std;
int main()
{
    // Enter input
    int number;
    cout << "Enter a number and I will tell you its divisors: ";
    cin >> number;

    while(number < 2){
        cout << "Must be 2 or greater, re-enter: ";
        cin >> number;

    }
    cout << "The divisors of " << number << " are" << endl;

    for (int i = 1; i <= number / 2; i++) {
        if(number%i==0){
            cout << i << endl;
        }
    }
    cout << number << endl;


    cin.ignore();
    cin.get();
    return 0;
}
