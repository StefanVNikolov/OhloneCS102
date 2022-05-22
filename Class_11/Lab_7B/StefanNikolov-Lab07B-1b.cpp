// Stefan Vladimirov Nikolov
// This program demonstrates the range-based for loop.
#include <iostream>

#include <string>

using namespace std;
int main() {
    string planets[] = {
        "Mercury",
        "Venus",
        "Earth",
        "Mars",
        "Jupiter",
        "Saturn",
        "Uranus",
        "Neptune",
        "Pluto (a dwarf planet)"
    };
    // Get the length of the array
    int arrayLength = sizeof(planets) / sizeof(planets[0]);
    cout << "Here are the planets:\n";
    // Display the values in the array.
    for (int currentValue = 0; currentValue < arrayLength; currentValue++) {
        cout << planets[currentValue] << endl;
    }
    cin.get();
    return 0;
}
