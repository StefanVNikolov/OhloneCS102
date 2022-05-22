// Laboratory07B Passing Vectors by Reference
// Creates a Vector with the number of elements input from the keyboard
// And reports the length of time it takes to pass the Vector by Reference
#include <iostream>

#include <vector>

#include <chrono>

using namespace std;
void showStats(vector < int > & );
int main() {
    int index, num, startTime, endTime;
    vector < int > bigVector;
    cout << "How many elements do you want in your Vector: ";
    cin >> num;
    for (index = 0; index < num; index++)
        bigVector.push_back(index); // This loads the vector up with data
    auto started = chrono::high_resolution_clock::now(); // Starts the clock
    showStats(bigVector);
    auto done = chrono::high_resolution_clock::now(); // Stops the clock
    cout << chrono::duration_cast < chrono::milliseconds > (done - started).count();
    cout << " milliseconds required to pass by value ";
    cout << "a Vector having " << num << " elements!" << endl;
    return 0;
}
void showStats(vector < int > & bigV) {
    cout << "Passed all the data by Reference" << endl << endl;
}
