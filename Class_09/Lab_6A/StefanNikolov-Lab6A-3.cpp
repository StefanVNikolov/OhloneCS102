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
    return true;
}
int main()
{
    int length = 200000;
    int primeCounter = 0;
    for(int i = 2; i <= length ; i++){
        if(checkIfPrime(i)){
           primeCounter++;
        }
    }
    cout << "There are " << primeCounter << " primes below " << length << endl;
    cin.ignore();
    cin.get();
    return 0;
}


