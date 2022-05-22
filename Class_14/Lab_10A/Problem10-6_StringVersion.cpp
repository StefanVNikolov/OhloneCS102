// This program uses the find function to search an array of String.
#include <iostream>

#include <string>

using namespace std;
int main() {
    // Constants for array lengths
    const int NUM_PRODS = 11; // Number of products
    const int LENGTH = 27; // String length
    // Array of products
    string products[NUM_PRODS] = {
        "TV327 31 inch Television",
        "CD257 CD Player",
        "TA677 Answering Machine",
        "CS109 Car Stereo",
        "PC955 Personal Computer"
    };
    string lookUp; // To hold user's input
    int index; // Loop counter
    bool found = false; // Found flag
    const int NOTFOUND = -1;
    cout << "\tContact Database\n\n";
    cout << "Enter a Product Number to search for: ";
    getline(cin, lookUp);
    // Search the array for a matching substring
    for (index = 0; index < NUM_PRODS; index++) {
        if (products[index].find(lookUp, 0) != NOTFOUND) {
            found = true;
            break;
        }
    }
    if (found)
        cout << products[index] << endl;
    else
        cout << lookUp << " not found in table." << endl;
    cin.get();
    return 0;
}
