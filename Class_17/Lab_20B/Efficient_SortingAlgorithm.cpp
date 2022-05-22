// QuickSort – Vector Version Using Efficient Sort Algorithm
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
void quickSort(vector < int > & a, int start, int end) {
    int j;
    if (start < end) {
        j = partition(a, start, end);
        quickSort(a, start, j - 1);
        quickSort(a, j + 1, end);
    }
}
int partition(vector < int > & a, int start, int end) {
    int v, i, j, temp;
    v = a[start]; // v = a[start] is the pivotpoint
    i = start;
    j = end + 1;
    do {
        do
            i++;
        while (a[i] < v && i <= end); // while a[i] is less than pivotpoint
        do
            j--;
        while (v < a[j]); // while a[j] is greater than pivotpoint
        if (i < j) {
            temp = a[i]; // since a[i] is greater than pivotpoint
            a[i] = a[j]; // and a[j] is less than the pivotpoint
            a[j] = temp; // swapping the two will correct them both
        }
    } while (i < j); // When i==j, we're done.
    a[start] = a[j]; // Swap the contents of a[j] with pivotpoint
    a[j] = v;
    return j; // j is now the final location for pivotpoint
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
