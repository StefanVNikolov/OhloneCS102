// DisplayLightWavelength.cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

double convertToFrequency(int waveLength){
    double frequency;
    const double lightSpeed = 299792.46;
    frequency = lightSpeed/double(waveLength);
    return frequency;
}
int main()
{
    //reading from a file
    //create file objects
    ifstream infile;
    ofstream outputFile; // File stream object
    //need two variables to receive the data
    int lambda;
    string color;

    //associate them with a file
    infile.open("myfile.txt");
    outputFile.open("results.txt");

    //make sure the file exists
    if (!infile.is_open()) //file not found
        cout << "File not found" << endl;
    else
    {
        //read first value
        infile >> lambda;
        while (!infile.eof())
        {
            double frequency = convertToFrequency(lambda);
            //read the rest of the line
            infile >> color;
            //print what we just read
            cout << "The wavelength of " << color << " is "
            << lambda << " nanometers" << " and has frequency of " << frequency << "[THz]\n";
            outputFile << color << " " << frequency << endl;
            //read the beginning of the next data record
            infile >> lambda;
        }
        infile.close();
        outputFile.close();
    }
    return 0;
}
