// This program uses a structure variable to store a record to a file.
#include<iostream>

#include<fstream>

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
    char again; // To hold Y or N
    // Open a file for binary output.
    fstream divisions("divisions.dat", ios::out | ios::binary);
    do {
        // Get data about a person.
        cout << "Enter the following data about a " << "division: \n ";
        cout << "Division Name: ";
        cin.getline(division.name, NAME_SIZE);
        cout << "Quarter: ";
        cin >> division.quarter;
        cin.ignore(); // Skip over the remaining newline.
        cout << "Quarterly Sales: ";
        cin >> division.quarterlySales;
        cin.ignore(); // Skip over the remaining newline.
        cout << "Division city: ";
        cin.getline(division.city, CITY_SIZE);
        divisions.write(reinterpret_cast < char * > ( & division), sizeof(division));
        cout << "Do you want to enter another record? ";
        cin >> again;
        cin.ignore(); // Skip over the remaining newline.
    } while (again == 'Y' || again == 'y');
    // Close the file.
    divisions.close();
    return 0;
}
