// This program will sort MAX_NUM random numbers, using a QuickSort, into ascending order, & show the time of execution.
#include <iostream>

#include <cstdlib>

#include <ctime>

#include <random>

#include <vector>

#include <chrono>

using namespace std;
void quick_sort(vector < int > & , int, int);
int partition(vector < int > & , int, int);
int bigRand(int, int);
void showStats(vector < int > & , int);
const int MAX_NUM = 100000000;
const int MAX_VALUE = 100000000;
const int MIN_VALUE = 0;
int main() {
    vector < int > a(MAX_NUM);
    int elapsed_msecs, i;
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
    showStats(a, MAX_NUM);
    cin.get();
    return 0;
}
int bigRand(int upper, int lower) {
    const int twoToFifteenth = 32768;
    int rand_num, rand_num1, rand_num2, randnum
    ;
    int top = 32768;
    rand_num1 = 1 + rand(); //% top; // Check this out
    rand_num2 = rand(); //% top;
    rand_num = twoToFifteenth * rand_num1 + rand_num2;
    randnum = rand_num % (upper -
        lower) + lower;
    return randnum;
}
void quick_sort(vector < int > & a, int k, int u) {
    int j;
    if (k < u) {
        j = partition(a, k, u);
        quick_sort(a, k, j -
            1);
        quick_sort(a, j + 1, u);
    }
}

int partition(vector < int > & a, int k, int u) {
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
void showStats(vector < int > & bigV, int size) {
    int
    i
    ;
    int smallest = bigV[0];
    int largest = bigV[0];
    long long total = bigV[0];
    for (
        i = 1; i < size; i++) {
        largest = largest > bigV[
            i] ? largest : bigV[i];
        smallest = smallest < bigV[i] ? smallest : bigV[i];
        total += bigV[
            i];
    }
    cout << "\n " << "Number of numbers: " << size << endl;
    cout << "\n " << "Mean of numbers: " << total/size << endl;
    cout << "\n " << "Median number: " << bigV[size/2] << endl;
    cout << "\n " << "Smallest number: " << smallest << endl;
    cout << "\n " << "Largest number: " << largest << endl;
}
