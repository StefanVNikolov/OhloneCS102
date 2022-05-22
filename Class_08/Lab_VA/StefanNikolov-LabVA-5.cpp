// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

long getSumFromFile(string fileName)
{
    ifstream inputFile;
    int number;
    long sum;

    // Open the file.
    inputFile.open(fileName);


    // Read the numbers from the file and
    // display them.
    while (inputFile >> number)
    {
        sum += number;
    }
    // Close the file.
    inputFile.close();
    return sum;
}
int main()
{
    long sumFromFile_1 = getSumFromFile("randnums1.txt");
    cout << "randnums1.txt has 1000 entities with sum " << sumFromFile_1 << endl;

    long sumFromFile_2 = getSumFromFile("randnums2.txt");
    cout << "randnums1.txt has 1000 entities with sum " << sumFromFile_2 << endl;

    double average1 = double(sumFromFile_1) / 1000.00;
    cout << "The average value for both files is " << average1 << endl;

    double average2 = double(sumFromFile_2) / 1000.00;
    cout << "The average value for both files is " << average2 << endl;


    cin.ignore();
    cin.get();

    return 0;
}

