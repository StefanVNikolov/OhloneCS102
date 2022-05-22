#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool checkIfPrime(int number){
    if(number%2==0){
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
    int numberOfPrimeNumbers = 0;
    for(int i = 100001; i <= 1000000 ; i+=2){
        if(checkIfPrime(i)){
           numberOfPrimeNumbers++;
        }
    }
    cout << "There are " << numberOfPrimeNumbers << endl;
}


