// This program will sort MAX_NUM random numbers, using arrays & QuickSort, into ascending order, & show the time of execution.
#include <iostream>

#include <cstdlib>

#include <ctime>

#include <random>

#include <chrono>

using namespace std;
void quick_sort(int[], int, int);
int partition(int[], int, int);
int bigRand(int, int);
const int MAX_NUM = 300000; // This you will change
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
    quick_sort(a, 0, MAX_NUM - 1);
    auto done = chrono::high_resolution_clock::now(); // Stops the clock
    elapsed_msecs = chrono::duration_cast < chrono::milliseconds > (done - started).count();
    cout << "Elapsed time = " << elapsed_msecs << " milliseconds." << endl;
    cin.get();
    return 0;
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
void quick_sort(int a[], int k, int u) {
    int j;
    if (k < u) {
        j = partition(a, k, u);
        quick_sort(a, k, j -
            1);
        quick_sort(a, j + 1, u);
    }
}
int partition(int a[], int k, int u) {
    int v, i, j, temp
    ;
    v = a[k];
    i = k;
    j = u + 1;
    do {
        do
            i++;
        while (a[
                i] < v &&
            i <= u);
        do
            j--;
        while (v < a[j]);
        if (
            i < j) {
            temp = a[i];
            a[
                i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    a[k] = a[j];
    a[j] = v;
    return (j);
}
