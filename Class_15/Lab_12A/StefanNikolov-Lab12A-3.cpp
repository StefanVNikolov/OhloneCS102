#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include <algorithm>


using namespace std;

int wordCount = 0;

std::string stream_as_string( std::istream& stm ) // #include <iterator>
{
    return {std::istreambuf_iterator<char>(stm), std::istreambuf_iterator<char>{}};
}

bool containsOnlyLetters(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
        std::string::npos;
}

int main()
{
    std::ifstream file("Gettysburg.txt") ;
    string text = stream_as_string(file);
    replace(text.begin(), text.end(), '\n', ' ');
    auto it = std::remove_if(text.begin(), text.end(), ::ispunct);
    text.erase(it, text.end());

    // given string with delimiter
    string delim = " "; // delimiter

    size_t pos = 0;
    string token1; // define a string variable

    // use find() function to get the position of the delimiters
    while (( pos = text.find (delim)) != std::string::npos)
    {
    token1 = text.substr(0, pos); // store the substring
    bool isWord = containsOnlyLetters(token1);

    if(isWord == true && !token1.empty())
    {
        wordCount++;
        cout << wordCount << ". " <<token1<< endl;
    }

    text.erase(0, pos + delim.length());  /* erase() function store the current positon and move to next token. */
    }
    cout << wordCount + 1 << ". " << text << endl;
    cout << endl;
    cout << "This text has "  <<wordCount + 1 << " words " << endl;
}
