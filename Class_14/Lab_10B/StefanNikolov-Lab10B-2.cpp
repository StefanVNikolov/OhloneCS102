// This program converts a c-string array to a c++ string arrays
#include <iostream>

#include <cstring> // For str

using namespace std;

// Constants for array lengths
const int NUM_PRODS = 11; // Number of products
int LENGTH = 0; // String length

int findMaxLength(string[NUM_PRODS]);
char* convertToCharArray(string);
char** convertToCharArrays(string[NUM_PRODS]);


int main() {
    cout << "\tStefan Nikolov's C++ String Array to C-String converter\n\n";
    // Array of products
    string stringArray[NUM_PRODS]  = {
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
    LENGTH = findMaxLength(stringArray) + 1;

    cout << "This is the C++ String Array\n";
    cout << "__________________________\n";
    for(int current_string = 0; current_string < NUM_PRODS; current_string++)
    {
        cout << stringArray[current_string] << endl;
    }
    cout << endl;

    convertToCharArrays(stringArray);


    cin.ignore();
    cin.get();

    return 0;
}
int findMaxLength(string stringArray[NUM_PRODS])
{
    int maxLength = 0;
    for(int currentString = 0; currentString < NUM_PRODS; currentString++)
    {
        int currentLength = stringArray[currentString].size();
        if(currentLength > maxLength)
            maxLength = currentLength;
    }
    cout << "The Max length in the string array is : " << maxLength << endl << endl;
    return maxLength;
}

char* convertToCharArray(string toConvert)
{
    char* char_array = new char[LENGTH];

    // copying the contents of the
    // string to char array
    strcpy(char_array, toConvert.c_str());

    return char_array;
}
char** convertToCharArrays(string stringArray[NUM_PRODS])
{
    cout << "This is the C-String Array\n";
    cout << "__________________________\n";

    char** charArrays = new char*[NUM_PRODS];
    for(int currentString = 0; currentString < NUM_PRODS; currentString++)
    {
        charArrays[currentString] = new char[LENGTH];
        for(int currentChar = 0; currentChar < LENGTH; currentChar++)
        {
            charArrays[currentString][currentChar] = stringArray[currentString][currentChar];
        }
        cout << charArrays[currentString] << endl;
    }

    return charArrays;
}
