#include <iostream>
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
int main()
{
    int length = 200000;
    int primeCounter = 0;
    for(int i = 2; i <= length ; i++){
        if(isPrime(i)){
           primeCounter++;
        }
    }
    cout << "There are " << primeCounter << " primes below " << length << endl;
    cin.ignore();
    cin.get();
    return 0;
}


