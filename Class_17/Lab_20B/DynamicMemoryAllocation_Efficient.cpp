// QuickSort using Dynamic Memory Allocation & Using Efficient Sort
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

    using namespace std;
void quickSort(int[], int, int);
int partition(int[], int, int);
int bigRand(int, int);
const int MAX_NUM = 100000000;
const int MAX_VALUE = 100000000;
const int MIN_VALUE = 1;
int main() {
    for(int k = 0; k <= 4; k++)
    {
        int n, i
        ;
        int * a = nullptr;
        a = new int[MAX_VALUE];
        int elapsed_msecs
        ;
        unsigned seed = time(0);
        srand(seed);
        for (
            i = 0; i < MAX_VALUE; i++)
            a[
                i] = bigRand(MAX_VALUE, MIN_VALUE);
        cout << "The clock has now started:" << endl << endl;
        auto started = chrono::high_resolution_clock::now(); // Starts the clock
        quickSort(a, 0, MAX_NUM - 1);
        auto done = chrono::high_resolution_clock::now(); // Stops the clock
        elapsed_msecs = chrono::duration_cast < chrono::milliseconds > (done - started).count();
        cout << "Elapsed time = " << elapsed_msecs << " milliseconds." << endl << endl;
        cout << "The first sorted element is: " << a[0] << endl;
        cout << "The middle sorted element is: " << a[MAX_VALUE / 2] << endl;
        cout << "The final sorted element is: " << a[MAX_VALUE - 1];
        delete[] a;
        a = nullptr;
    }
    return 0;
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
void quickSort(int a[], int start, int end) {
    int j;
    if (start < end) {
        j = partition(a, start, end);
        quickSort(a, start, j -
            1);
        quickSort(a, j +
            1, end);
    }
}
int partition(int a[], int start, int end) {
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
    return (j); // j is now the final location for pivotpoint
}
