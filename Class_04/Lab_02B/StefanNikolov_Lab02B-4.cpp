// Stefan Nikolov
// CS-102 Laboratory 2 Program B
// This program calculates
// the volume of the Earth
#include <iostream>
#include <cmath>
using namespace std;    //required for cin, cout
int main()
{
    //declare variables
    const double  PI = 3.141592653589793;
    double radiusThirdPower = pow(6371.0, 3);
    double fraction = 4.0/3;

    double volumeOfEarth = PI*radiusThirdPower*fraction;
    cout << "The volume of the Earth is: " << volumeOfEarth << " cubic km \n";

    cin.ignore();
    cin.get();
    return 0;

}   // end main
