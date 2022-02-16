// Stefan Nikolov
// CS-102 Laboratory 2 Program B
// This program converts takes input
// in Fahrenheit and converts it to Celsius
#include <iostream>
using namespace std;    //required for cin, cout
int main()
{
    //declare variables
    double fTemp, cTemp;
    //get inputs
    cout << "Enter temp in Fahrenheit: ";
    cin >> fTemp ;
    //convert to Celsius
    cTemp = 5.0/9*(fTemp-32); // Careful with this line
    //display output
    cout <<fTemp<< " Fahrenheit = " <<cTemp<< " Celsius" << endl;

    cin.ignore();
    cin.get();
    return 0;

}   // end main
