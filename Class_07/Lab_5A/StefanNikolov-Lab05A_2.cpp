// Sum.cpp
#include <iostream>
using namespace std;
int main()
{
    int games = 0;
    double total = 0.00;
    double averagePoints = 0.00;

    cout << "Enter the number of points your team has earned\n";
    cout << "so far in the season, then strike Q when finished.\n";
    double input;

    cout << "\nEnter points for game " << games+1 << " [or press Q and exit]: ";
    while (cin >> input)
    {
        total = total + input;
        games++;
        cout << "Enter points for game " << games+1 << " [or press Q and exit]: ";
    }
    if(games != 0)
    {
        averagePoints = total / games;
        cout << "\nNumber of games: " << games << endl;
        cout << "The sum of all points is: " << total << endl;
        cout << "The average points per game are: " << averagePoints << endl;
    }
    else
    {
        cout << "\nNumber of games: " << games << endl;
        cout << "Not enough information!\n";
    }

    cin.clear(); // The following four statements will clear out the
    cin.ignore(); // false output from the while loop,
    cin.get(); // and get rid of the hanging key stroke, thus
    cin.get(); // enabling the output to be held on the screen.
    return 0;
}
