#include <iostream>

using namespace std;

void print_ascending(int);

int main()
{
    int number;
    cout << "Enter a positive number: ";
    cin >> number;
    cout << endl << endl;
    print_ascending(number);

    cin.ignore();
    cin.get();
    return 0;
}

void print_ascending(int n)
{
    if(n > 0)
    {
        print_ascending( n - 1);
        printf("%d \n", n);
    }
}
