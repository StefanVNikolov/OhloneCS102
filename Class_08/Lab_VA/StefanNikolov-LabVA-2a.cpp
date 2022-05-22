// This program writes user input to a file.
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream outputFile; // File stream object
    int numberOfPlanets; // Number of days of sales
    string planet; // Sales amount for a day
    // Get the number of days.
    cout << "How many planets do you want to enter: ";
    cin >> numberOfPlanets;
    // Open a file named Planets.txt.
    outputFile.open("Planets.txt");
    // Get the sales for each day and write it to the file.
    for (int count = 1; count <= numberOfPlanets; count++)
    {
        // Get the sales for a day.
        cout << "Enter a planet name "
        << count << ": ";
        cin >> planet;
        // Write the sales to the file.
        outputFile << planet << endl;
    }
    // Close the file.
    outputFile.close();
    cout << "Data written to Planets.txt\n";
    return 0;
}

