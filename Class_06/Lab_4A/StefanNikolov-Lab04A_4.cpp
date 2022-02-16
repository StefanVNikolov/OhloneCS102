// This test scoring testing program does not accept test scores
// that are less than 0 or greater than 100.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Enter your grade: ";
    // Taking the letter grade input
    char grade;
    cin.get(grade);

    // Messages for different grades
    string A_message = "Excellent\n",
           B_message = "Above average\n",
           C_message = "Average\n",
           D_F_messege = "Below average\n";


    switch(grade)
    {
        case 'A':
        case 'a':
                 cout << A_message;
                 break;
        case 'B':
        case 'b':
                 cout << B_message;
                 break;
        case 'C':
        case 'c':
                 cout << C_message;
                 break;
        case 'D':
        case 'd':
        case 'F':
        case 'f':
                 cout << D_F_messege;
                 break;
        default:
                cout << "Invalid input!";
                break;
    }


    cin.ignore();
    cin.get();
    return(0);

}
