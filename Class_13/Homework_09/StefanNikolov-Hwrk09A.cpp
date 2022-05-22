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
int * expandArray(vector <int> , int);
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
    cout << "Expanded size of the array: " << numbers*2 << endl << endl;
    return numbers;
}

string fileName = "GradeList.txt";
int SIZE1 = 0;

int main() {
    cout << "\t-Stefan Nikolov's Array Expander\n\n";
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
    int * exp = nullptr;
    // Reverse the array.
    exp = expandArray(array1, count);
    // Display the original array.
    cout << "Here are the original array contents:\n";
    displayArray(array1, count);
    // Display the new array.
    cout << "\nHere are the expanded array contents:\n";
    displayArray(exp, count*2);
    cin.ignore();
    cin.get();
    // Free the dynamically allocated memory and
    // set the pointer to 0.
    delete[] exp;
    exp = nullptr;
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
// The expandArray function creates a copy of an   *
// array or a vector and doubles the size of it    *
// The first half of the values are copied and the *
// other half of values are assigned to be 0       *
//**************************************************
int * expandArray(vector <int> arr, int size)
{
    int * newArray = nullptr;
    // Validate the size. If 0 or a negative
    // number was passed, return a null pointer.
    if (size <= 0)
        return nullptr;
    // Allocate a new array.
    newArray = new int[size*2];
    // Copy the array's contents to the
    // new array.

    int * beginningNewArray = nullptr;

    beginningNewArray = newArray + 0;

    // Copy the array's contents to the
    // new array.
    int count = 0;
    for(count = 0; count < size; count++)
    {

        *beginningNewArray = arr[count];
        beginningNewArray++;
    }

    // Reset the counter
    // Assign zeros to the other part of the array
    for(count = size; count < size*2; count++)
    {

        *beginningNewArray = 0;
        beginningNewArray++;
    }

    // Return a pointer to the new array.
    return newArray;
}
