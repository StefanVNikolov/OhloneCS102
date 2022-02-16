// Name: Stefan Nikolov
// This program calculates the cost of a Meal at a Restaurant
// using 9% for the tax rate and 20% for the tip rate.
#include <iostream>
using namespace std;
int main()
{
    // Variables to hold the meal cost, the
    // tip, and the tax.
    double cost, tip, tax;

    // Taking the cost from the input.
    cout << "Enter the meal cost: ";
    cin >> cost;

    // Calculating the tax charged for the meal
    tax = cost * 0.09;

    // Adding the tax to the cost of the meal
    cost = cost + tax;

    // Calculating the gratuity charge for the meal
    tip = cost * 0.2;

    // Adding the tip to the cost of the meal
    cost = cost + tip;

    // Displaying the result
    cout << "Tax for the meal: " << tax << "$\n";
    cout << "Tip for the meal: " << tip << "$\n";
    cout << "Final cost for the meal: " << cost << "$\n";
    cin.ignore();
    cin.get();
    return 0;
}
