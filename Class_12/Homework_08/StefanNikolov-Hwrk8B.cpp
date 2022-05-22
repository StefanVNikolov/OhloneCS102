// This program will sort numbers and find their median
#include <iostream>

#include <cstdlib>

#include <iostream>

#include <fstream>

using namespace std;
void quick_sort(int[], int, int);
int partition(int[], int, int);
void displayArray(int[], int);
double findMedian(int[], int);

int main() {
    cout << "Stefan Nikolov's median finder:\n";
    cout << "\tChoose File Name:\n";
    cout << "\t-GradeListO.txt - Press O\n";
    cout << "\t-GradeListE.txt - Press E\n";
    char fileChoice;
    cin >> fileChoice;

    string FileName;
    int SIZE = 0;
    if(fileChoice == 'O' || fileChoice == 'o'){
        FileName = "GradeListO.txt";
        SIZE = 49;
    }
    else if(fileChoice == 'E' || fileChoice == 'e'){
        FileName = "GradeListE.txt";
        SIZE = 50;
    }
    else{
        cout << "Error: Wrong input or missing file!\n";
        return 1;
    }
    int numbers[SIZE];
    std::fstream myfile(FileName, std::ios_base::in);
    float a;

    int index = 0;
    while (myfile >> a)
    {
        numbers[index] = a;
        index++;
    }

    quick_sort(numbers, 0, SIZE - 1);
    displayArray(numbers, SIZE);
    double median = findMedian(numbers, SIZE);
    cout << "The median is - " << median << endl;
    cin.ignore();
    cin.get();
    return 0;
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
    int v, i, j, temp;
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
void displayArray(int array[], int SIZE){
    cout << "__Soreted Array__\n";
    for(int currentNumber = 0; currentNumber <= SIZE - 1; currentNumber++){
        cout << currentNumber + 1 << ". [" << array[currentNumber] << "]\n";
    }
}
double findMedian(int array[], int SIZE){
    double median = 0;
    if(SIZE % 2 == 0){
        median = (double(array[SIZE/2]) +  double(array[SIZE/2 - 1]))/2.00;
    }
    else if(SIZE % 2 != 0){
        median = array[SIZE/2];
    }
    else{
        return 0;
    }
    return median;
}
