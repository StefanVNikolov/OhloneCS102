// This program uses the modulus operator to determine
// if a number is odd or even. If the number is evenly divisible
// by 2, it is an even number. A remainder indicates it is odd.
#include <iostream>
using namespace std;
int main()
{
    int number;
    cout << "Enter an integer and I will tell you if it is odd or even. \n";
    cin >> number;
    cout << number <<(number % 2 == 0 ? " is even.\n" : " is odd.\n")<<endl;

    cin.ignore();
    cin.get();
    return(0);
}
