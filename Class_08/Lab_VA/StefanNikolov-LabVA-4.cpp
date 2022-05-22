// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int getMaxFromFile(string fileName)
{
    ifstream inputFile;
    int number;
    int maxNumber = -1;

    // Open the file.
    inputFile.open(fileName);


    // Read the numbers from the file and
    // display them.
    while (inputFile >> number)
    {
        if(maxNumber < number){
            maxNumber = number;
        }
    }
    // Close the file.
    inputFile.close();
    return maxNumber;
}
int getMinFromFile(string fileName)
{
    ifstream inputFile;
    int number;
    int minNumber = 10000;

    // Open the file.
    inputFile.open(fileName);


    // Read the numbers from the file and
    // display them.
    while (inputFile >> number)
    {
        if(minNumber > number){
            minNumber = number;
        }
    }
    // Close the file.
    inputFile.close();
    return minNumber;
}
int main()
{
    int maxFromFile_1 = getMaxFromFile("randnums1.txt");
    cout << "The biggest number in randnums1.txt is " << maxFromFile_1 << endl;
    int minFromFile_1 = getMinFromFile("randnums1.txt");
    cout << "The smallest number in randnums1.txt is " << minFromFile_1 << endl;

    int maxFromFile_2 = getMaxFromFile("randnums2.txt");
    cout << "The biggest number in randnums2.txt is " << maxFromFile_2 << endl;
    int minFromFile_2 = getMinFromFile("randnums2.txt");
    cout << "The smallest number in randnums2.txt is " << minFromFile_2 << endl;

    cin.ignore();
    cin.get();

    return 0;
}
