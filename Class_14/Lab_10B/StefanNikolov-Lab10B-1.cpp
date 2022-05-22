// This program converts a c-string array to a c++ string arrays
#include <iostream>

#include <cstring> // For str

#include <typeinfo>

using namespace std;

// Constants for array lengths
const int NUM_PRODS = 11; // Number of products
const int LENGTH = 27; // String length

string convertToString(char[]);
string* convertToStringArray(char [NUM_PRODS][LENGTH]);


int main() {
    cout << "\tStefan Nikolov's C-String to C++ String Array converter\n\n";
    // Array of products
    char charArray[NUM_PRODS][LENGTH] = {
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Alejandra Cruz, 555-1223",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783"};

    string* stringArray = new string[NUM_PRODS];
    stringArray = convertToStringArray(charArray);

    cout << "This is the C-String Array\n";
    cout << "__________________________\n";
    for(int current_string = 0; current_string < NUM_PRODS; current_string++)
    {
        cout << charArray[current_string] << endl;
    }
    cout << endl;

    cout << "This is the C++ String Array\n";
    cout << "__________________________\n";
    for(int current_string = 0; current_string < NUM_PRODS; current_string++)
    {
        cout << stringArray[current_string] << endl;
    }
    delete[] stringArray;
    cin.ignore();
    cin.get();

    return 0;
}
string convertToString(char c_string[])
{
    string to_String = string(c_string);
    return to_String;
}
string* convertToStringArray(char c_stringArray[NUM_PRODS][LENGTH])
{
    string* stringArray = new string[NUM_PRODS];
    for(int currentC_string = 0; currentC_string < NUM_PRODS; currentC_string++)
    {
        stringArray[currentC_string] = convertToString(c_stringArray[currentC_string]);
    }
    return stringArray;
}
