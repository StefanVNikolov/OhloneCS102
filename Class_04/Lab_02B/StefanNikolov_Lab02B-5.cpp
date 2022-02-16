// Stefan Nikolov
// CS-102 Laboratory 2 Program B
// This program
#include <iostream>
#include <cmath>
using namespace std;    //required for cin, cout
int main()
{
    //declare variables
    // The value of the largest long long integer possible.
    long long int LLI_Max_Value = 0x7FFFFFFFFFFFFFFF;
    //The value of the smallest long long integer possible.
    long long int LLI_Min_Value = 0x7FFFFFFFFFFFFFFF + 1;
    //The value of the largest unsigned long long integer possible.
    unsigned long long int ULLI_Max_Value = 0x7FFFFFFFFFFFFFFFF;
    //The value of the smallest unsigned long long integer possible.
    unsigned long long int ULLI_Min_Value = 0x7FFFFFFFFFFFFFFFF + 1;


    cout <<"The value of the largest long long integer possible: "<< LLI_Max_Value <<"\n";
    cout <<"The value of the smallest long long integer possible: "<< LLI_Min_Value <<"\n";
    cout <<"The value of the largest unsigned long long integer possible: "<< ULLI_Max_Value <<"\n";
    cout <<"The value of the smallest unsigned long long integer possible: "<< ULLI_Min_Value <<"\n";

    cin.ignore();
    cin.get();
    return 0;

}   // end main
