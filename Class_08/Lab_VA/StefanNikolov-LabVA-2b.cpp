// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream inputFile;
    string filename;
    string planet;
    // Get the filename from the user.
    cout << "Enter the filename: ";
    cin >> filename;
    // Open the file.
    inputFile.open(filename);

    // If the file successfully opened, process it.
    if (inputFile)
    {
        // Read the numbers from the file and
        // display them.
        while (inputFile >> planet)
        {
            cout << planet << endl;
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
