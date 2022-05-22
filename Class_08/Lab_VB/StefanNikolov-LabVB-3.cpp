// DisplayLightWavelength.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    //reading from a file
    //create file objects
    ifstream infile;
    ofstream outputFile; // File stream object
    //need two variables to receive the data
    string name;
    double salary;
    float percentIncrease;

    double newSalary;

    //associate them with a file
    string infileName;
    string outfileName;

    cout << "Enter the name of the input data file: ";
    cin >> infileName;

    cout << "Enter the name of the output data file: ";
    cin >> outfileName;
    infile.open(infileName);
    outputFile.open(outfileName);

    //make sure the file exists
    if (!infile.is_open()) //file not found
        cout << "File not found" << endl;
    else
    {
        while (infile >> name)
        {
            infile >> salary;
            infile >> percentIncrease;

            newSalary = salary + salary*(percentIncrease/100);

            //print what we just read
            cout << name << " has a new salary of " << newSalary << "$ \n";
            outputFile << name << " " << newSalary << endl;
        }
        infile.close();
        outputFile.close();
    }
    return 0;
}

