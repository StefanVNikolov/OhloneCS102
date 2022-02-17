// This program converts seconds to
// minutes, hours and days depending on
// the number
#include <iostream>
using namespace std;

int main()
{
    // Initializing holding variables
    // Input
    int seconds;
    // Additional
    double days, hours, minutes;

    // Taking input from the console
    cout << "Stefan Nikolov's Time Calculator\n";
    cout << "Enter the Number of Seconds: ";
    cin >> seconds;

    // Displaying the output
    cout << "The time is ";
    if(seconds >= 86400){
        days = double(seconds) / 86400.0;
        cout << days << " days.\n";
    }
    else if(seconds >= 3600){
        hours = double(seconds) / 3600.0;
        cout << hours << " hours.\n";
    }
    else if(seconds >= 60){
        minutes = double(seconds) / 60.0;
        cout << minutes << " minutes.\n";
    }
    else
        cout << seconds << " seconds.\n";

    cin.ignore();
    cin.get();
    return(0);
}
