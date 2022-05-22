#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int numChars(char, string, int);
int main()
{
    string str = "";
    char ch;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Enter a char to count: ";
    cin >> ch;

    std::for_each(str.begin(), str.end(), [](char & c){
    c = ::tolower(c);});

    cout << "\n\nThe letter " << ch << " appears "
    << numChars(tolower(ch), str, 0) << " times.\n";
    return 0;
}
int numChars(char search, string str, int subscript)
{
    if (subscript >= str.length())
        return 0;
    else if (str[subscript] == search)
        return 1 + numChars(search, str, subscript+1);
    else
        return numChars(search, str, subscript+1);
}
