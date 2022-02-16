// Stefan Nikolov
#include <iostream>
using namespace std;
int main()
{
    long double apple;
    cout << "The size of a char is " << sizeof(char) << " bytes.\n";
    cout << "The size of a bool is " << sizeof(bool) << " bytes.\n";
    cout << "The size of a short int is " << sizeof(short int) << " bytes.\n";
    cout << "The size of a int is " << sizeof(int) << " bytes.\n";
    cout << "The size of a long integer is " << sizeof(long int) << " bytes.\n";
    cout << "The size of a long long int is " << sizeof(long long int) << " bytes.\n";
    cout << "The size of a unsigned long long int is " << sizeof(unsigned long long int) << " bytes.\n";
    cout << "The size of a float is " << sizeof(float) << " bytes.\n";
    cout << "The size of a double is " << sizeof(double) << " bytes.\n";
    cout << "The size of a long double is " << sizeof(long double) << " bytes.\n";

    cin.ignore();
    cin.get();
    return 0;
}
