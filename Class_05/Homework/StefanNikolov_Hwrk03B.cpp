// Stefan Nikolov
// This program is a Math Tutor
#include <iostream>
#include <cstdlib>      // For the rand and srand
#include <ctime>        // For the time function
#include  <cmath>


using namespace std;
int main()
{
    // Initializing the variables
    int A, B, answer;
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 1000;

    // Get the system time
    unsigned seed = time(0);

    // Seed the random number generator.
    srand(seed);

    // Generating numbers
    A = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    B = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    int A_length = log10(A)+1;
    int B_length = log10(B)+1;

    // Displaying a math problem
    cout << "Stefan Nikolov's Math Tutor" << endl;
    cout <<string(5-A_length, ' ')<<A<<endl;
    cout <<"+"<<string(4-B_length, ' ')<<B<<endl;
    cout <<string(5, '_');
    getc(stdin);

    // Displaying answer
    answer = A+B;
    int answer_length = to_string(answer).length();
    cout <<string(5-answer_length, ' ')<<answer<<endl;




    cin.ignore();
    cin.get();
    return 0;
}
