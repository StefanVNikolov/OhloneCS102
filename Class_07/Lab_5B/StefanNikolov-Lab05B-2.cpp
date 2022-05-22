// Stefan Nikolov
#include <iostream>
using namespace std;
int main()
{
    // Enter input
    int number;
    int sum;
    cout << "Enter a positive integer: ";
    cin >> number;

    while(number < 2){
        cout << "Must be 2 or greater, re-enter: ";
        cin >> number;

    }
    cout << "The sum of the integers from 1 to " << number << " is ";

    for (int i = 1; i <= number; i++) {
        sum += i;
    }
    cout << sum << endl;


    cin.ignore();
    cin.get();
    return 0;
}
