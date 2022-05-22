// Stefan Vladimirov Nikolov
// This program demonstrates the range-based for loop.
#include <iostream>

using namespace std;
int main() {
    // Define an array of integers.
    int numbers[] = {
        10,
        20,
        30,
        40,
        50
    };
    // Get the length of the array
    int arrayLength = sizeof(numbers) / sizeof(numbers[0]);

    // Display the values in the array.
    for (int currentValue = 0; currentValue < arrayLength; currentValue++) {
        cout << numbers[currentValue] << endl;
    }

    cin.get();
    return 0;
}
