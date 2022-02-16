// Stefan Nikolov
// This program converts seconds to minutes and seconds.
#include <iostream>
using namespace std;
int main()
{
    // The total seconds come from the input.
    int totalSeconds;
    cout << "Enter the total number of seconds";
    cin >> totalSeconds;
    // Variables for minutes and seconds
    int minutes, seconds, hours;
    // Get the number of hours.
    hours = totalSeconds / 3600;
    // Get the number of minutes.
    minutes = (totalSeconds - (hours*3600))/60;
    // Get the remaining seconds.
    seconds = totalSeconds % 60;
    // Display the results.
    cout << totalSeconds << " is equivalent to:\n";
    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;
    cout << "Seconds: " << seconds << endl;
    cin.get();
    return 0;
}
