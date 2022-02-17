// This program calculates the tuition of a student
// depending on if they are in-state or out-state
#include <iostream>
using namespace std;

int main()
{
    // Holding variables
    char residentialStatus;
    char needRoomAndBoard;

    int inStateTuition = 3000;
    int outOfStateTuition = 4500;
    int inStateRoomAndBoard = 2500;
    int outOfStateRoomAndBoard = 3500;

    // Taking input
    // Residential status
    cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state: ";
    cin >> residentialStatus;

    // Room and board requirement
    cout << "Please input \"Y\" if you require room and board and \"N\" if you do not: ";
    cin >> needRoomAndBoard;


    // Calculating the charges
    int totalCharges;
    residentialStatus == 'I' ?
    (needRoomAndBoard == 'Y' ? totalCharges = inStateTuition + inStateRoomAndBoard : totalCharges = inStateTuition) :
    (needRoomAndBoard == 'Y' ? totalCharges = outOfStateTuition + outOfStateRoomAndBoard : totalCharges = outOfStateTuition);



    // Displaying the result
    cout << "\n";
    cout << "Your total bill for this semester is $"
         << totalCharges << "\n";


    cin.ignore();
    cin.get();
    return(0);
}
