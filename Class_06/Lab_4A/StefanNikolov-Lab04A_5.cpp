#include <iostream>
using namespace std;
int main()
{
    int floor;
    bool containsErrors = true;

    while(containsErrors)
    {
        cout << "Floor: ";
        cin >> floor;
        // Constants containing error codes
        int errorCode = 0;
        const int cinFail = 1,
                  floor_13 = 2,
                  invalidFloor = 3;

        // Checking error type.
        if(cin.fail())
           errorCode = 1;
        else if(floor == 13)
            errorCode = 2;
        else if(floor <= 0 || floor > 20)
            errorCode = 3;
        else
            errorCode = 0;


        switch(errorCode)
        {
            case cinFail:
                         cin.clear();
                         cin.ignore();
                         cout << "Error: Not an integer." << endl;
                         break;
            case floor_13:
                         cin.clear();
                         cin.ignore();
                         cout << "Error: There is no thirteenth floor." << endl;
                         break;
            case invalidFloor:
                              cin.clear();
                              cin.ignore();
                              cout << "Error: The floor must be between 1 and 20." << endl;
                              break;
            default:
                    containsErrors = false;
                    break;
        }
    }

    // Now we know that the input is valid
    int actual_floor;
    if (floor > 13)
    {
        actual_floor = floor - 1;
    }
    else
    {
        actual_floor = floor;
    }
    cout << "The elevator will travel to the actual floor "
         << actual_floor << endl;
    return 0;
}
