#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n)
{
    if (n == 1) // 1 is not a prime
        return false;
    if (n == 2) // 2 is a prime
        return true;
    if (n % 2 == 0) // No other even number is a prime
        return false;
        // Try finding a number that divides evenly into n
    int k = 3; // No need to divide by 2 since n is odd
    while (k * k <= n) // Only need to try divisors up to sqrt(n)
    {
        if (n % k == 0) // n is not a prime since it is divisible by k
            return false;
        k = k + 2; // Try next odd number
    }
    return true; // No divisor found. Therefore, n is a prime
}
int ComputePrimeForEnnead(int digits){
    int primeCounter = 0;
    int startNumber = pow(10,digits-1);
    int finishNumber = pow(10,digits) - 1;

    for(int i = startNumber; i <= finishNumber ; i++){
        if(isPrime(i)){
           primeCounter++;
        }
    }
    return primeCounter;
}
int main()
{
    int numberLength = 0;
    cout << "Enter the length you want to count in: ";
    cin >> numberLength;
    int primes = ComputePrimeForEnnead(numberLength);
    cout << "There are " << primes-1 << " primes in this range." << endl;
    cin.ignore();
    cin.get();
    return 0;
}


