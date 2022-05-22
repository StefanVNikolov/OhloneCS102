// This program uses reference variables as function parameters.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Function prototypes. Both functions use reference variables
// as parameters.
void throwDice(int &,int &);
int main()
{
    int die1, die2;
    throwDice(die1, die2);

    cout << "Die 1 [" << die1 << "]  Die 2 [" << die2 << "]" << endl;
    return 0;
}

void throwDice(int &die1, int &die2)
{
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 6;

    unsigned seed = time(0);
    srand(seed);
    die1 = (rand()% (MAX_VALUE - MIN_VALUE +1)) + MIN_VALUE;
    die2 = (rand()% (MAX_VALUE - MIN_VALUE +1)) + MIN_VALUE;
}

