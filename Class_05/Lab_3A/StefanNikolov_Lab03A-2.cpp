// Stefan Nikolov
// CS-102 Laboratory 3 Program A
// This program calculates
// plays a word game with the user
#include <iostream>
#include <cstdlib>      // For the rand and srand
#include <ctime>        // For the time function
using namespace std;
int main()
{
    // Constants
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 1;

    // Variable
    int coin; // To hold the value of the coin

    // Get the system time
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);

    cout << "Flipping the coin...\n";
    coin = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    if (coin == 1)
        cout << "HEADS" << endl;
    else
        cout << "TAILS" << endl;


    cin.ignore();
    cin.get();

    return 0;


}   // end main

