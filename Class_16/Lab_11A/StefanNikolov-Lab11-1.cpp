// This program demonstrates an enumerated data type.
#include <iostream>

#include <iomanip>

using namespace std;
void Clear();
enum Month {
    JANUARY,
    FEBRURAY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER

};
// Function prototype
void displayMonthName(Month);
int main() {
    double total = 0.00;
    double average = 0.00;

    double maxRain = 0.00;
    Month maxRainMonth;

    double minRain = 0.00;
    Month minRainMonth;


    const int NUM_MONTHS = 12; // The number of months
    double rain[NUM_MONTHS]; // To hold rain amount for each monts
    Month rainMonth; // Loop counter
    // Get the rain for each day.
    for (rainMonth = JANUARY; rainMonth <= DECEMBER; rainMonth = static_cast < Month > (rainMonth + 1)) {
        cout << "Enter the rain for day ";
        displayMonthName(rainMonth);
        cout << ": ";
        cin >> rain[rainMonth];
    }
    Clear();
    // Calculate the total rain.
    int firstMonth = 1;
    for (rainMonth = JANUARY; rainMonth <= DECEMBER; rainMonth = static_cast < Month > (rainMonth + 1))
    {
        if(firstMonth == 1)
        {
            minRain = rain[rainMonth];
            maxRain = rain[rainMonth];
        }
        firstMonth = 0;

        total += rain[rainMonth];
        if(maxRain < rain[rainMonth])
        {
            maxRain = rain[rainMonth];
            maxRainMonth = rainMonth;
        }
        if(minRain > rain[rainMonth])
        {
            minRain = rain[rainMonth];
            minRainMonth = rainMonth;
        }

    }
    average = total / NUM_MONTHS;

    // Display rain information for Oakland CA
    cout << "\tOakland California Rainfall Data\n\n";
    cout << "Total Rainfall: " << fixed << setprecision(2) << total << endl;
    cout << "Overall Average Monthly Rainfall: " << fixed << setprecision(2) << average << endl << endl;

    cout << "The maximum yearly rainfall amount of [" << fixed << setprecision(2) << maxRain;
    cout << "] appeared in ";
    displayMonthName(maxRainMonth);
    cout << endl;

    cout << "The minimum yearly rainfall amount of [" << fixed << setprecision(2) << minRain;
    cout << "] appeared in ";
    displayMonthName(minRainMonth);
    cout << endl;

    cin.ignore();
    cin.get();

    return 0;
}
//**********************************************************
// Definition of the displayDayName function *
// This function accepts an argument of the Day type and *
// displays the corresponding name of the day. *
//**********************************************************
void displayMonthName(Month m) {
    switch (m) {
    case JANUARY:
        cout << "January";
        break;
    case FEBRURAY:
        cout << "February";
        break;
    case MARCH:
        cout << "March";
        break;
    case APRIL:
        cout << "April";
        break;
    case MAY:
        cout << "May";
        break;
    case JUNE:
        cout << "June";
        break;
    case JULY:
        cout << "July";
        break;
    case AUGUST:
        cout << "August";
        break;
    case SEPTEMBER:
        cout << "September";
        break;
    case OCTOBER:
        cout << "October";
        break;
    case NOVEMBER:
        cout << "November";
        break;
    case DECEMBER:
        cout << "December";
        break;
    }
}
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}
