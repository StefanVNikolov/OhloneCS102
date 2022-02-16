// Calculate Gross Pay
#include <iostream>
using namespace std;

int main(){

cout << "+--------------------------------------------------------+" << endl;
cout << "| 1.My name is: Stefan Vladimirov Nikolov                |"<< endl;  // Stefan Vladimirov Nikolov
cout <<"| 2.The Lab02 was done on: Thursday 26.01.2022           |"<< endl;   // Thursday 26.01.2022
cout <<"| 3.I downloaded the software to my DELL laptop at home. |"<< endl;   //DELL laptop
cout <<"| 4.I am using Codeblocks 20.03.                         |"<< endl;   // Codeblocks 20.03.
cout << "+--------------------------------------------------------+" << endl;

    double hours_Worked, pay_Rate, gross_Pay;

    // Getting hours of work input information
    cout << "How many hours did you work? ";
    cin >> hours_Worked;

    // Getting the pay rate input information
    cout << "How much do you get paid per hour? ";
    cin >> pay_Rate;

    // Calculate the pay.
    gross_Pay = hours_Worked * pay_Rate;

    // Display the pay.
    cout << "You have earned $" << gross_Pay << endl;
    cin.ignore();
    cin.get();
    return 0;
}
