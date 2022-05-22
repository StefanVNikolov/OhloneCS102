#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int currentInputNumber;
    int inputsCount = 0;
    double valuesSum = 0.00;
    double averageValue = 0.00;

    cout << "Stefan Nikolov's Statistics Program\n";

    while(currentInputNumber != -99)
    {
        cout << "Enter a number: ";
        cin >> currentInputNumber;

        if(currentInputNumber != -99)
        {
            inputsCount++;
            valuesSum += currentInputNumber;
        }
    }
    if(inputsCount != 0)
    {
        averageValue = valuesSum / inputsCount;
        cout << "The number of numbers you entered is " << inputsCount << endl;
        cout << "The sum of the numbers is: " << valuesSum << endl;
        cout << "The average value is: " << averageValue << endl;
    }
    else
    {
        cout << "DIVIDING BY ZERO!\n";
        cout << "SELF DESTRUCTION IN \n";
        cout << "3...\n2...\n1...\n";
    }

    cin.ignore();
    cin.get();
    return(0);



}
