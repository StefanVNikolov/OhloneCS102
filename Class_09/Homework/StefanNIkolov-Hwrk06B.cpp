//Stefan Nikolov
#include<iostream>
using namespace std;
int firstPrevious = 1, secondPrevious = 0;
void nextFibo(int&, int&);
int main()
{
    int numbers = -1;
    while(numbers <= 0 || numbers > 46){
        cout << "How many numbers in the Fibonacci Sequence do you want to display? ";
        cin >> numbers;
        if(numbers <= 0 || numbers > 46)  {
            cout << "\nError: The number must be between 1 and 46!\n";
            cout << "Please enter valid data and try again!\n\n";
        }
    }
    if(numbers != 1 && numbers != 2){
        cout << "Fibonacci number 1 is: 0" << endl;
        cout << "Fibonacci number 2 is: 1" << endl;
        for(int i = 2; i < numbers; i++)
        {
            cout << "Fibonacci number " << i + 1 << " is: ";
            nextFibo(firstPrevious, secondPrevious);
            cout << endl;
        }
    }
    switch(numbers)
    {
        case 1:
               cout << "0" << endl;
               break;
        case 2:
               cout << "0" << endl;
               cout << "1" << endl;
               break;
    }


    cin.ignore();
    cin.get();
    return 0;
}
void nextFibo(int& firstPrevious, int& secondPrevious){
    int nextFiboNumber = firstPrevious + secondPrevious;
    secondPrevious = firstPrevious;
    firstPrevious = nextFiboNumber;
    cout << nextFiboNumber;
}
