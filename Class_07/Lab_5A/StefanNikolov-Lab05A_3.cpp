// This program calculates the charges for DVD rentals.
// Every third DVD is free.
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int dvdCount = 1; // DVD counter
    int numDVDs; // Number of DVDs rented
    double total = 0.0; // Accumulator
    char current; // Current release, Y or N
    // Get the number of DVDs.
    cout << "How many DVDs are being rented? ";
    cin >> numDVDs;
    // Determine the charges.
    do
    {
        if ((dvdCount % 3) == 0)
        {
            cout << "DVD #" << dvdCount << " is free!\n";
        }
        else if((dvdCount % 3) != 0)
        {
            cout << "Is DVD #" << dvdCount;
            cout << " a current release? (Y/N) ";
            cin >> current;
            if (current == 'Y' || current == 'y')
                total += 3.50;
            else
                total += 2.50;
        }
    } while (dvdCount++ < numDVDs);

    // Display the total.
    cout << fixed << showpoint << setprecision(2);
    cout << "The total is $" << total << endl;

    cin.clear(); // The following four statements will clear out the
    cin.ignore(); // false output from the while loop,
    cin.get(); // and get rid of the hanging key stroke, thus
    cin.get(); // enabling the output to be held on the screen.
    return 0;
}
