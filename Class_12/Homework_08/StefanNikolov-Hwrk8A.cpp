//Stefan Nikolov's string sorter
#include <iostream>

#include <cstdlib>

using namespace std;
void selectionSort(string[], int);
void displayArray(string[], int);

int main() {

const int SIZE = 20;
string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
"Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
"James, Jean", "Weaver, Jim", "Pore, Bob",
"Rutherford, Greg", "Javens, Renee",
"Harrison, Rose", "Setzer, Cathy",
"Pike, Gordon", "Holland, Beth"};

    int elapsed_msecs;

    cout << "Stefan Nikolov's string sorter: " << endl << endl;
    cout << "________[Sorted Array]________" << endl;
    selectionSort(names, SIZE);
    displayArray(names, SIZE);
    cin.get();
    return 0;
}
void selectionSort(string array[], int size) {
        int startScan, minIndex;
        string minValue;
        for (startScan = 0; startScan < (size - 1); startScan++) {
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
void displayArray(string array[], int size){
        int startDisplay;
        for(startDisplay = 0; startDisplay <= (size - 1); startDisplay++){
            cout << startDisplay + 1 << ". " <<array[startDisplay] << endl;
        }
}

