// Stefan Nikolov
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    cout << string(6, ' ');
    for (int i = 1; i <= 4; i++) {
        cout << i << string(6, ' ');
    }
    cout << endl << string(5, ' ');
    for (int i = 1; i <= 4; i++) {
        cout << 'x' << string(6, ' ');
    }
    cout << "\n\n";


    for (int number = 1; number <= 10; number++) {
        cout << string(6, ' ');
        for (int power = 1; power <= 4; power++) {
            cout << pow(number, power) << string(6 - int(log10(pow(number, power))), ' ');
        }
        cout << "\n";
    }


    cin.ignore();
    cin.get();
    return 0;
}
