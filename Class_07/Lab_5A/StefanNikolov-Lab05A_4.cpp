// This program calculates the charges for DVD rentals.
// Every third DVD is free.
#include <iostream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;
int main()
{

    const int MIN_VALUE = 1;
    const int MAX_VALUE = 12;
    // Get the system time
    unsigned seed = time(0);
    int A, B, answer;

    cout << "Welcome to Math Tutor!\n";
    char input;
    while (input != 'q' && input != 'Q')
    {
        cout << "Select an operation (+ - / *) or press q to quit: ";
        cin >> input;
        seed = time(0);
        A = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
        B = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

        switch(input)
        {
            case '+':
                {
                    questionsCount++;
                    cout << A << " " << input << " " << B << " = ";
                    cin >> answer;
                    if(answer == A+B)
                    {
                        cout << "That's right!\n";
                        accurateAnswers++;
                    }
                    else
                    {
                        cout << "Wrong answer!\n";
                    }
                    break;
                }
            case '-':
                {
                    questionsCount++;
                    int bigger = (A > B) ? A : B;
                    int smaller = (A < B) ? A : B;
                    cout << bigger << " " << input << " " << smaller << " = ";
                    cin >> answer;
                    if(answer == bigger-smaller)
                    {
                        cout << "That's right!\n";
                        accurateAnswers++;
                    }
                    else
                    {
                        cout << "Wrong answer!\n";
                    }
                    break;
                }
            case '*':
                {
                    questionsCount++;
                    cout << A << " " << input << " " << B << " = ";
                    cin >> answer;
                    if(answer == A*B)
                    {
                        cout << "That's right!\n";
                        accurateAnswers++;
                    }
                    else
                    {
                        cout << "Wrong answer!\n";
                    }
                    break;
                }
            case '/':
                {
                    questionsCount++;
                    int firstNumber = A*B;
                    cout << firstNumber << " " << input << " " << B << " = ";
                    cin >> answer;
                    if(answer == A)
                    {
                        cout << "That's right!\n";
                        accurateAnswers++;
                    }
                    else
                    {
                        cout << "Wrong answer!\n";
                    }
                    break;
                }
            case 'q':
            case 'Q':
                break;
            default:
                cout << "Wrong input! Choose between the given options!\n";
        }
    }
    cin.clear(); // The following four statements will clear out the
    cin.ignore(); // false output from the while loop,
    cin.get(); // and get rid of the hanging key stroke, thus
    return 0;
}
