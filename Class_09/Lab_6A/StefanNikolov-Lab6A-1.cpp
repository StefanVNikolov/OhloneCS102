#include <iostream>
using namespace std;
bool checkIfPrime(int number){
    if(number%2==0){
        cout << number << " is not a prime" << endl;
        cout << number << " is divisible by 2" << endl;
        return false;
    }
    for(int currentNumber = 3 ; currentNumber <= (number/2); currentNumber+=2){
        if(number%currentNumber==0){
            cout << number << " is not a prime" << endl;
            cout << number << " is divisible by " << currentNumber << endl;
            return false;
        }
    }
    cout << number << " is a prime" << endl;
    return true;
}
int main()
{
    int number;
    cout << "Enter a number and I will tell you if it is a prime: ";
    cin >> number;
    checkIfPrime(number);

    cin.ignore();
    cin.get();
    return 0;
}


