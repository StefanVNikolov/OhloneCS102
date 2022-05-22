// This program uses reference variables as function parameters.
#include <iostream>
using namespace std;
// Function prototypes. Both functions use reference variables
// as parameters.
int getNum()
{
    int userNum = 0;
    cout << "Enter a number: ";
    cin >> userNum;
    return userNum;
}
//**********************************************************
// Definition of doubleNum. *
// The parameter refVar is a reference variable. The value *
// in refVar is doubled. *
//**********************************************************
int doubleNum (int userNum)
{
    int doubledNumber = userNum*2;
    return doubledNumber;
}
int main()
{
    int value;
    // Get a number and store it in value.
    value = getNum();
    // Double the number stored in value.
    value = doubleNum(value);
    // Display the resulting number.
    cout << "That value doubled is " << value << endl;
    return 0;
}

