// This program uses the strstr function to search an array of char.
#include <iostream>

#include <cstring> // For strstr

using namespace std;
int main() {
    // Constants for array lengths
    const int NUM_PRODS = 11; // Number of products
    const int LENGTH = 27; // String length
    // Array of products
    char products[NUM_PRODS][LENGTH] = {
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
    char lookUp[LENGTH]; // To hold user's input
    char * strPtr = nullptr; // To point to the found product
    int index; // Loop counter
    bool found; // Found flag
    bool generalFound = false;
    // Prompt the usr for a product number.
    cout << "\tProduct Database\n\n";
    cout << "Enter a product number to search for: ";
    cin.getline(lookUp, LENGTH);
    // Search the array for a matching substring
    for (index = 0; index < NUM_PRODS; index++) {
        strPtr = strstr(products[index], lookUp);
        if (strPtr != nullptr)
        {
            cout << products[index] << endl;
            generalFound = true;
        }
    }
    if(generalFound == false)
        cout << "No matching product was found.\n";
    return 0;
}
