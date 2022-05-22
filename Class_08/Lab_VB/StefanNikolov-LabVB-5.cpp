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

    infile.open("salaryincrease2.txt");

    //make sure the file exists
    if (!infile.is_open()) //file not found
        cout << "File not found" << endl;
    else
    {
        cout << "Salary increase report:\n";
        cout << "|Employee|        |New Salary|\n";
        cout << fixed << setprecision(2);

        getline(infile, name,'#');
        while (!infile.eof())
        {
            infile >> salary;
            infile.ignore();

            //print what we just read
            int nameLength = name.length();
            cout << name << string(19-nameLength, ' ') << "$" <<salary << "\n";
            getline(infile, name,'#');
        }
        infile.close();
    }
    return 0;
}

