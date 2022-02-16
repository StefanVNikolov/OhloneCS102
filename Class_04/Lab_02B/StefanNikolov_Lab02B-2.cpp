// Stefan Nikolov
// CS-102 Laboratory 2 Program B
// This program displays the average price
// for a number of shares
#include <iostream>
using namespace std;    //required for cin, cout
int main()
{
    // declare variables
    int shares=220;
    double avgPrice=14.67;
    cout<<"There were "<<shares<<" shares sold at $"<<avgPrice<<" per share.\n";

    cin.ignore();
    cin.get();
    return 0;
}   // end main
