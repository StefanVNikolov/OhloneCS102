// QuickSort � Vector Version Using & C.A.R.Hoare sorting Algorithm
#include <iostream>

#include <cstdlib>

#include <ctime>

#include <vector>

#include <random>

#include <algorithm>

#include <chrono>

using namespace std;
void commaSeparate(int);
void quickSort(vector < int > & , int, int);
int partition(vector < int > & , int, int);
int bigRand(int, int);
const int MAX_VALUE = 100000000;
const int MIN_VALUE = 1;
int main() {
    vector < int > a(MAX_VALUE);
    int n, i;
    int elapsed_secs;
    unsigned seed = time(0);
    srand(seed);
    n = MAX_VALUE;
    for (i = 0; i < n; i++)
        a[i] = bigRand(MAX_VALUE, MIN_VALUE);
    cout << "The clock has now started:" << endl << endl;
    auto started = chrono::high_resolution_clock::now(); // Starts the clock
    quickSort(a, 0, n - 1);
    auto done = chrono::high_resolution_clock::now(); // Stops the clock
    elapsed_secs = chrono::duration_cast < chrono::milliseconds > (done - started).count();
    cout << "Elapsed time = " << elapsed_secs << " milliseconds." << endl << endl;
    cout << "The first sorted element is: " << a[0] << endl;
    cout << "The middle sorted element is: " << a[MAX_VALUE / 2] << endl;
    cout << "The final sorted element is: " << a[MAX_VALUE - 1];
    cin.get();
    return 0;
}
void quickSort(vector < int > & set, int start, int end) {
    int pivotPoint;
    if (start < end) {
        // Get the pivot point.
        pivotPoint = partition(set, start, end);
        // Sort the first sub list.
        quickSort(set, start, pivotPoint - 1);
        // Sort the second sub list.
        quickSort(set, pivotPoint + 1, end);
    }
}
//**********************************************************
// partition selects the value in the middle of the *
// array set as the pivot. The list is rearranged so *
// all the values less than the pivot are on its left *
// and all the values greater than pivot are on its right. *
//**********************************************************
int partition(vector < int > & set, int start, int end) {
    int pivotValue, pivotIndex, mid;
    mid = (start + end) / 2;
    swap(set[start], set[mid]);
    pivotIndex = start;
    pivotValue = set[start];
    for (int scan = start + 1; scan <= end; scan++) {
        if (set[scan] < pivotValue) {
            pivotIndex++;
            swap(set[pivotIndex], set[scan]);
        }
    }
    swap(set[start], set[pivotIndex]);
    return pivotIndex;
}
//***********************************************
// swap simply exchanges the contents of *
// value1 and value2. *
//***********************************************
void swap(int & value1, int & value2) {
    int temp = value1;
    value1 = value2;
    value2 = temp;
}
int bigRand(int upper, int lower) {
    const int twoToFifteenth = 32768;
    int rand_num, rand_num1, rand_num2, randnum;
    int top = 32768;
    rand_num1 = 1 + rand(); //% top; // Check this out
    rand_num2 = rand(); //% top;
    rand_num = twoToFifteenth * rand_num1 + rand_num2;
    randnum = rand_num % (upper - lower) + lower;
    return randnum;
}
