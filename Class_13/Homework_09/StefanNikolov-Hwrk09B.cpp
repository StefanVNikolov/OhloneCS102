// Stefan Vladimirov Nikolov
// This program expands an array and
// assigns the new empty half of the
// values to be zero
// The expander function returns a pointer
// to the new vector or array
#include <iostream>

#include <fstream>

#include <vector>

using namespace std;

// Function prototype
int * shiftArray(vector <int> , int);
void displayArray(vector <int>, int);
void displayArray(int[], int);

int findSize(string fileName)
{
    int numbers = 0;
    string line;
    ifstream myfile(fileName);

    while (getline(myfile, line))
        ++numbers;
    cout << "Original size of the array: " << numbers << endl;
    cout << "Shifted size of the array: " << numbers+1 << endl << endl;
    return numbers;
}

string fileName = "GradeList.txt";
int SIZE1 = 0;

int main() {
    cout << "\t-Stefan Nikolov's Array Shifter\n\n";
    SIZE1 = findSize(fileName);
    // Array of unsorted values
    vector <int> array1(SIZE1);
    int count = 0;
    int arraySize, maxIndex;
    ifstream inputFile;
    inputFile.open(fileName);
    while (count < SIZE1 && inputFile >> array1[count])
        count++;
    inputFile.close();
    // Define pointer for the reversed array.
    int * shifted = nullptr;
    // Reverse the array.
    shifted = shiftArray(array1, count);
    // Display the original array.
    cout << "Here are the original array contents:\n";
    displayArray(array1, count);
    // Display the new array.
    cout << "\nHere are the shifted array contents:\n";
    displayArray(shifted, count+1);
    cin.ignore();
    cin.get();
    // Free the dynamically allocated memory and
    // set the pointer to 0.
    delete[] shifted;
    shifted = nullptr;
    return 0;
}
//**************************************************
// The displayArray function accepts an int array  *
// and its size as arguments and displays the      *
// contents of the array.                          *
//**************************************************
void displayArray(vector <int> arr, int size) {
    for (int index = 0; index < size; index++)
        cout << arr[index] << " ";
    cout << endl;
}
void displayArray(int arr[], int size) {
    for (int index = 0; index < size; index++)
        cout << arr[index] << " ";
    cout << endl;
}
//**************************************************
// The shiftArray function creates a copy of an    *
// array or a vector and shifts the entire array   *
// or a vector by one space and creates a new      *
// value of 0                                      *
//**************************************************
int * shiftArray(vector <int> arr, int size)
{
    int * newArray = nullptr;
    // Validate the size. If 0 or a negative
    // number was passed, return a null pointer.
    if (size <= 0)
        return nullptr;
    // Allocate a new array.
    newArray = new int[size+1];
    // Copy the array's contents to the
    // new array.

    int * beginningNewArray = nullptr;

    beginningNewArray = newArray + 0;

    // Set the first element to be equal to 0
    *beginningNewArray = 0;
    beginningNewArray++;


    // Copy the array's contents to the
    // new array.
    int count = 0;
    for(count = 0; count < size; count++)
    {

        *beginningNewArray = arr[count];
        beginningNewArray++;
    }

    // Return a pointer to the new array.
    return newArray;
}
