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

    string name;
    double salary;

    infile.open("salaryincrease.txt");

    //make sure the file exists
    if (!infile.is_open()) //file not found
        cout << "File not found" << endl;
    else
    {
        cout << "Salary increase report:\n";
        cout << "|Employee|      |New Salary|\n";
        cout << fixed << setprecision(2);
        while (infile >> name)
        {
            infile >> salary;

            //print what we just read
            int nameLength = name.length();
            cout << name << string(17-nameLength, ' ') << "$" << salary << "\n";
        }
        infile.close();
    }
    return 0;
}
