// This program displays the days in a given
// month of a year (leap year).
#include <iostream>
using namespace std;

int main()
{
    // Initializing holding variables
    // Input
    int month;       // month (1-12)
    int year;        // year  (leap-non leap)

    // Additional
    string monthInWords;    // month (in words)
    int daysInMonth;        // days (28-31)

    // Taking input from the console
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;

    // Checking if the year is leap
    // If it is divisible by 100 and 400
    // If it is not divisible by 100 but it is by 4
    bool commonLeapCheck = (year % 4 == 0);
    bool centuryLeapCheck = (year % 100 == 0) && (year % 400 == 0);


    // Verbalizing the month
    switch(month)
        {
            case 1:
                monthInWords = "January";
                break;
            case 2:
                monthInWords = "February";
                break;
            case 3:
                monthInWords = "March";
                break;
            case 4:
                monthInWords = "April";
                break;
            case 5:
                monthInWords = "May";
                break;
            case 6:
                monthInWords = "June";
                break;
            case 7:
                monthInWords = "July";
                break;
            case 8:
                monthInWords = "August";
                break;
            case 9:
                monthInWords = "September";
                break;
            case 10:
                monthInWords = "October";
                break;
            case 11:
                monthInWords = "November";
                break;
            case 12:
                monthInWords = "December";
                break;
            default:
                cout << "Invalid input!\n";
                return 1;
        }

    // Determining count of day
    switch(month)
        {
            case 2: // February has 28 or 29 days depending on the year
                if(commonLeapCheck || centuryLeapCheck)
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
                break;

            default: // If the month is even and smaller than 8 or odd and bigger than 7 [days = 30]
                     // In any other case [days = 31]
                   if(((month % 2 == 0) && (month < 8)) || ((month % 2 != 0) && (month > 7)))
                       daysInMonth = 30;
                   else
                       daysInMonth = 31;
                   break;
        }

    // Displaying the answer
    cout << "\nStefan Nikolov's Days of Month Calculator says:\n";
    cout << monthInWords << ", " << year << ", " << "has " << daysInMonth << " days.\n";


    cin.ignore();
    cin.get();
    return(0);
}
