// This program will sort MAX_NUM random numbers, using a Selection Sort, into ascending order, & show the time of execution.
#include <iostream>

#include <cstdlib>

#include <ctime>

#include <random>

#include <chrono>

using namespace std;
void selectionSort(int[], int);
int bigRand(int, int);
const int MAX_NUM = 10000; // This you will change
const int MAX_VALUE = 100000000;
const int MIN_VALUE = 1;
int main() {
    int a[MAX_NUM], i;
    int elapsed_msecs;
    unsigned seed = time(0);
    srand(seed);
    for (i = 0; i < MAX_NUM; i++)
        a[i] = bigRand(MAX_VALUE, MIN_VALUE);
    cout << "The clock has now started:" << endl << endl;
    auto started = chrono::high_resolution_clock::now(); // Starts the clock
    selectionSort(a, MAX_NUM);
    auto done = chrono::high_resolution_clock::now(); // Stops the clock
    elapsed_msecs = chrono::duration_cast < chrono::milliseconds > (done - started).count();
    cout << "Elapsed time = " << elapsed_msecs << " milliseconds." << endl;
    cin.get();
    return 0;
}
void selectionSort
    (int array[], int size) {
        int startScan, minIndex, minValue;
        for (startScan = 0; startScan < (size -
                1); startScan++) {
            minIndex = startScan;
            minValue = array[startScan];
            for (int index = startScan + 1; index < size; index++) {
                if (array[index] < minValue) {
                    minValue = array[index];
                    minIndex = index;
                }
            }
            array[minIndex] = array[startScan];
            array[startScan] = minValue;
        }
    }
int bigRand(int upper, int lower) {
    const int twoToFifteenth = 32768;
    int rand_num, rand_num1, rand_num2, randnum
    ;
    rand_num1 = 1 + rand();
    rand_num2 = rand();
    rand_num = twoToFifteenth * rand_num1 + rand_num2;
    randnum = rand_num % (upper -
        lower) + lower;
    return randnum;
}
