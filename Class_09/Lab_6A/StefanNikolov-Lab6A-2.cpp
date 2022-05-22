#include <iostream>
using namespace std;
bool checkIfPrime(int number){
    if(number%2==0 && number!=2){
        return false;
    }
    for(int currentNumber = 3 ; currentNumber <= (number/2); currentNumber+=2){
        if(number%currentNumber==0){
            return false;
        }
    }
    cout << number << " is a prime" << endl;
    return true;
}
int main()
{
    for(int i = 2; i <= 200 ; i++){
       checkIfPrime(i);
    }

    cin.ignore();
    cin.get();
    return 0;
}


