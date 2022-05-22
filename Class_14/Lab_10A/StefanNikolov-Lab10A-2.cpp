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
        "Alejandra Cruz, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783"
    };
    string lookUp; // To hold user's input
    int index; // Loop counter
    bool found = false; // Found flag
    bool anyFound = false;
    const int NOTFOUND = -1;
    cout << "\tContact Database\n\n";
    cout << "Enter a Product Number to search for: ";
    getline(cin, lookUp);
    // Search the array for a matching substring
    for (index = 0; index < NUM_PRODS; index++) {
        if (products[index].find(lookUp, 0) != NOTFOUND) {
            found = true;
            anyFound = true;
            if (found) {
                cout << products[index] << endl;
                found = false;
            }
        }
    }
    if (anyFound == false)
        cout << lookUp << " not found in table." << endl;
    cin.get();
    return 0;
}
