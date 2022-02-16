// Stefan Nikolov
// This program converts seconds to minutes and seconds.
#include <iostream>
using namespace std;
int main()
{
    // The total seconds come from the input.
    int totalSeconds, totalSecondsToDisplay;
    cout << "Enter the total number of seconds: ";
    cin >> totalSeconds;
    totalSecondsToDisplay = totalSeconds;
    // Variables for minutes and seconds
    int minutes, seconds, hours;
    // Get the number of hours.
    hours = totalSeconds / 3600;
    totalSeconds = totalSeconds % (3600);

    // Get the number of minutes.
    minutes = totalSeconds/60;
    // Get the remaining seconds.
    seconds = totalSeconds % 60;
    // Display the results.
    cout << totalSecondsToDisplay << " is equivalent to:\n";
    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;
    cout << "Seconds: " << seconds << endl;
    cin.get();
    return 0;
}
