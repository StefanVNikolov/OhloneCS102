// This program demonstrates a unique_ptr pointing
// to a dynamically allocated array of integers.
#include <iostream>

#include <memory>

using namespace std;
int main() {
    int ptr;
    long long size = 0;
    cout << "Enter an array size to allocate: ";
    cin >> size;
    try
    {
        unique_ptr < int[] > ptr(new int[size]);
    }
    catch (const bad_alloc &)
    {
        cout << "Error allocating memory";
        exit(0);
    }
    // continue on with program
    cout << "Success!";
    //12000000000
    return 0;
}


