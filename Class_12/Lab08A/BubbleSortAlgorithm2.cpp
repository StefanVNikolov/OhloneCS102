// This program will sort MAX_NUM random numbers, using a Bubble Sort, into ascending order, & show the time of execution.
using namespace std;
#include <iostream>

#include <cstdlib>

#include <ctime>

#include <random>

#include <chrono>

void sortArray
    (vector <int> &array, int size) {
        bool swap;
        int temp;
        do {
            swap = false;
            for (int count = 0; count < (size -
                    1); count++) {
                if (array[count] > array[count + 1]) {
                    temp = array[count];
                    array[count] = array[count + 1];
                    array[count + 1] = temp;
                    swap = true;
                }
            }
        } while (swap);
    }


int bigRand(int upper, int lower) {
    const int twoToFifteenth = 32768;
    int rand_num, rand_num1, rand_num2, randnum;
    rand_num1 = 1 + rand();
    rand_num2 = rand();
    rand_num = twoToFifteenth * rand_num1 + rand_num2;
    randnum = rand_num % (upper -
        lower) + lower;
    return randnum;
}
int bigRand(int, int);
const int MAX_NUM = 10; // This you will change
const int MAX_VALUE = 100000000;
const int MIN_VALUE = 1;
int main() {
    vector <int> a(MAX_NUM);
    int i = 0;
    int elapsed_msecs;
    unsigned seed = time(0);
    srand(seed);
    for (i = 0; i < MAX_NUM; i++)
        a[i] = bigRand(MAX_VALUE, MIN_VALUE);
    cout << "The clock has now started:" << endl << endl;
    auto started = chrono::high_resolution_clock::now(); // Starts the clock
    sortArray(a, MAX_NUM);
    auto done = chrono::high_resolution_clock::now(); // Stops the clock
    elapsed_msecs = chrono::duration_cast < chrono::milliseconds > (done - started).count();
    cout << "Elapsed time = " << elapsed_msecs << " milliseconds." << endl;
    cin.get();
    return 0;
}
