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

    if(grade=='A' || grade=='a')
        cout << A_message;
    else if(grade=='B' || grade=='b')
        cout << B_message;
    else if(grade=='C' || grade=='c')
        cout << C_message;
    else if(grade=='D' || grade=='d' || grade=='F' || grade=='f')
        cout << D_F_messege;
    else{
        cout << "Invalid input!";
    }


    cin.ignore();
    cin.get();
    return(0);

}
