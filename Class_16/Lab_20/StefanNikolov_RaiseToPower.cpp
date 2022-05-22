#include <iostream>
using namespace std;

int raiseToPower(int, int);

int main()
{
    int base, powerRaised, result;

    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter power: ";
    cin >> powerRaised;

    result = raiseToPower(base, powerRaised);
    cout << base << "^" << powerRaised << " = " << result;

    cin.ignore();
    cin.get();
    return 0;
}

int raiseToPower(int base, int powerRaised)
{
    if (powerRaised != 0)
        return (base*raiseToPower(base, powerRaised-1));
    else
        return 1;
}
