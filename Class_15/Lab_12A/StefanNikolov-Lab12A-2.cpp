// This program uses a structure variable to read a record from a file.
#include<iostream>

#include<fstream>

#include <iomanip>

using namespace std;
// Array sizes
const int NAME_SIZE = 51,
    CITY_SIZE = 51;
// Declare a structure for the record.
struct Info {
    char name[NAME_SIZE];
    int quarter;
    double quarterlySales;
    char city[CITY_SIZE];
};
int main() {
    Info division; // To hold info about a person
    fstream divisions; // File stream object
    // Open a file for input in binary mode.
    divisions.open("divisions.dat", ios:: in | ios::binary);
    // Test for errors.
    if (!divisions) {
        cout << "Error opening file. Program aborting.\n";
        return 0;
    }
    cout << "Here are the divisions in the file: \n\n";
    // Read the first record from the file.
    divisions.read(reinterpret_cast < char * > ( & division), sizeof(division));
    // While not at the end of the file,
    // display the records.
    while (!divisions.eof()) {
        // Display the record.
        cout << "Division Name: ";
        cout << division.name << endl;
        cout << "Quarter: ";
        cout << division.quarter << endl;
        cout << "Quarterly Sales: ";
        cout << "$" << fixed << setprecision(2);
        cout << double(division.quarterlySales) << endl;
        cout << "Devision City: ";
        cout << division.city << endl;
        // Wait for the user to press the Enter key.
        cout << "\nPress the Enter key to see the next record.\n";
        cin.get();
        // Read the next record from the file.
        divisions.read(reinterpret_cast < char * > ( & division), sizeof(division));
    }
    // Close the file.
    cout << "That's all the data in the file!\n";
    divisions.close();
    return 0;
}
