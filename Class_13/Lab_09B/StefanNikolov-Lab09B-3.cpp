#include <iostream>

#include <fstream>

using namespace std;

// Function prototype
int * reverseArray(int * , int);
int *duplicateArray(int *, int);
void displayArray(int[], int);

const int SIZE1 = 50;
int main() {
    // Array of unsorted values
    int array1[SIZE1];
    int count = 0;
    int arraySize, maxIndex;
    ifstream inputFile;
    inputFile.open("GradeList.txt");
    while (count < SIZE1 && inputFile >> array1[count])
        count++;
    inputFile.close();
    // Define pointer for the reversed array.
    int * dup1 = nullptr;
    // Reverse the array.
    dup1 = reverseArray(array1, count);
    // Display the original array.
    cout << "Here is the original array contents:\n";
    displayArray(array1, count);
    // Display the new array.
    cout << "\nHere is the reversed array:\n";
    displayArray(dup1, count);
    cin.ignore();
    cin.get();
    // Free the dynamically allocated memory and
    // set the pointer to 0.
    delete[] dup1;
    dup1 = nullptr;
    return 0;
}
//*****************************************************
// The duplicateArray function accepts an int array *
// and an int that indicates the array's size. The *
// function creates a new array that is a duplicate *
// of the argument array and returns a pointer to the *
// new array. If an invalid size is passed the *
// function returns null. *
//*****************************************************
int * duplicateArray(int * arr, int size) {
    int * newArray = nullptr;
    // Validate the size. If 0 or a negative
    // number was passed, return a null pointer.
    if (size <= 0)
        return nullptr;
    // Allocate a new array.
    newArray = new int[size];
    // Copy the array's contents to the
    // new array.
    for (int index = 0; index < size; index++)
        newArray[index] = arr[index];
    // Return a pointer to the new array.
    return newArray;
}
//**************************************************
// The displayArray function accepts an int array *
// and its size as arguments and displays the *
// contents of the array. *
//**************************************************
void displayArray(int arr[], int size) {
    for (int index = 0; index < size; index++)
        cout << arr[index] << " ";
    cout << endl;
}
//**************************************************
// The reverseArray function uses recursion *
// to flip the elements of an array and *
//**************************************************
int * reverseArray(int * arr, int size)
{
    int * newArray = nullptr;
    // Validate the size. If 0 or a negative
    // number was passed, return a null pointer.
    if (size <= 0)
        return nullptr;
    // Allocate a new array.
    newArray = new int[size];
    // Copy the array's contents to the
    // new array.

    int * beginingNewArray = nullptr;
    int * endOldArray = nullptr;

    beginingNewArray = newArray;
    endOldArray = arr + size - 1;


    int count = 0;
    for(count = 0; count < size; count++)
    {

        *beginingNewArray = *endOldArray;
        beginingNewArray++;
        endOldArray--;
        //cout << *beginingNewArray << endl;
        //cin.get();
    }
    // Return a pointer to the new array.
    return newArray;
}
