// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void readFromFile(string fileName)
{
    ifstream inputFile;
    int number;

    // Open the file.
    inputFile.open(fileName);

    // If the file successfully opened, process it.
    if (inputFile)
    {
        // Read the numbers from the file and
        // display them.
        while (inputFile >> number)
        {
            cout << number << endl;
        }
        // Close the file.
        inputFile.close();
    }
    else
    {
        // Display an error message.
        cout << "Error opening the file.\n";
    }
}
int main()
{
    readFromFile("randnums1.txt");
    readFromFile("randnums2.txt");

    cin.ignore();
    cin.get();

    return 0;
}
