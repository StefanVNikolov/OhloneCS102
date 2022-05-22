// Stefan Nikolov
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    char anotherTry = 'Y';
    double rateGuess;

    while(anotherTry == 'Y' || anotherTry == 'y'){
        double averageCost_2001 = 9.92;
        double averageCost_2015 = 20.34;
        cout << "Enter Rate of Increase Guess (in %): ";
        cin >> rateGuess;
        for(int i = 0; i < 14 ; i++){
            averageCost_2001 *=(1 + (rateGuess/100));
        }
        cout << setprecision(4);
        cout << "The current rate would be: " << averageCost_2001 << " cents/KWHr\n";
        cout << "The desired rate should be: " << averageCost_2015 << " cents/KWHr\n";
        cout << "Would you like to try again (Y or N): ";
        cin >> anotherTry;
        cout << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}
