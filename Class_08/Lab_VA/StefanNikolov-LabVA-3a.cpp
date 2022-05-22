// Stefan Nikolov
// CS-102 Laboratory 3 Program A
// This program calculates
// plays a word game with the user
#include <iostream>
#include <cstdlib>      // For the rand and srand
#include <ctime>        // For the time function

#include <fstream>
using namespace std;
void generateRandomNumbers(string fileName)
{
    ofstream outputFile; // File stream object
    outputFile.open(fileName);
    // Constants
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 10000;
    const int amount = 1000;

    // Variable
    int randomNumber; // To hold the value of the number

    for(int count = 1; count <= amount; count++){
        // Display three random numbers.
        randomNumber = MIN_VALUE + rand() % MAX_VALUE;
        outputFile << MIN_VALUE + rand() % MAX_VALUE << endl;
    }
    cout << amount << " entities were entered into " << fileName << endl;
    cout << "Data written to " << fileName << endl;
}
int main()
{
    // Get the system time.
    unsigned seed = time(0);
    // Seed the random number generator.
    srand(seed);
    generateRandomNumbers("randnums1.txt");
    generateRandomNumbers("randnums2.txt");
    cin.ignore();
    cin.get();

    return 0;


}   // end main


