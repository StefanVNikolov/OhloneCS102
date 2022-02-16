// Stefan Nikolov
// This program displays item prices
// with formatting
#include <iostream>
#include <iomanip>
#include <sstream>

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

    stringstream price1_ss, price2_ss;
    price1_ss << setprecision(2) << fixed << price1;
    price2_ss << setprecision(2) << fixed << price2;

    cout <<left<<setw(15)<<item1<<right<<setw(6)<< "$"+price1_ss.str() <<endl;
    cout <<left<<setw(15)<<item2<<right<<setw(6)<< "$"+price2_ss.str() <<endl;

    cin.ignore();
    cin.get();
    return 0;
}
