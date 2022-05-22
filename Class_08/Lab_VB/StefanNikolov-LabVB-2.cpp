#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream inputFile;
    string filename = "results.txt";

    float frequency;
    string color;

    // Open the file.
    inputFile.open(filename);

    // If the file successfully opened, process it.
    if (inputFile)
    {
        // Read the numbers from the file and
        // display them.
        inputFile >> color;
        while (!inputFile.eof())
        {
            inputFile >> frequency;
            cout << "The frequency of " << color << " is " << frequency << "[tHz]" <<endl;
            inputFile >> color;
        }
        // Close the file.
        inputFile.close();

    }
    else
    {
        // Display an error message.
        cout << "Error opening the file.\n";
    }
    return 0;
}

