// Stefan Nikolov
// This program displays item prices
// with formatting
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    //assume this data
    string item1, item2;
    double price1, price2;
    item1 = "Buffalo Wings";
    item2 = "Nachos";
    price1 = 10.50;
    price2 = 8.50;

    cout << setprecision(2) << fixed; //requires iomanip
    cout << item1 << " $" << setw(6) << price1 << endl;
    cout << item2 << " $" << setw(6) << price2 << endl;
    cout << endl; // CASE 2:

    cin.ignore();
    cin.get();
    return 0;
}
