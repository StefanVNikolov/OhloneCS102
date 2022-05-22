// Stefan Vladimirov Nikolov
// This program counts the number of words in a string
#include<iostream>

#include<stdio.h>

#include <regex>

#include <string>

#include <algorithm>

using namespace std;

char* convertToCharArray(string);
int countSpaces(char*);
int countWords(char*);

bool BothAreSpaces(char lhs, char rhs)
{
    return (lhs == rhs) && (lhs == ' ');
}

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

int main()
{
    cout << "\tStefan Nikolov's word counter\n";
    string text = "";

    cout << "Enter your text: ";
    getline(cin, text);

    std::regex reg(R"(\s+)");
    std::string cleanedText = std::regex_replace(text, reg, " ");
    std::string trimmedText = trim(cleanedText);

    char* char_text = convertToCharArray(text);
    int spaceCount = countSpaces(char_text);

    char* clean_char_text = convertToCharArray(trimmedText);
    int wordCount = countWords(clean_char_text);

    cin.ignore();
    cin.get();

    return 0;
}
char* convertToCharArray(string toConvert)
{
    int LENGTH = toConvert.size();
    char* char_array = new char[LENGTH];

    // copying the contents of the
    // string to char array
    strcpy(char_array, toConvert.c_str());

    return char_array;
}

int countSpaces(char* sentence)
{
    int i,count=1;
    for(i=0; sentence[i]!='\0';++i)
    {
        if(sentence[i]==' ')
            count++;
    }
    cout<<"\nThere are "<<count<<" spaces in the given string!\n";

    return count;
}
int countWords(char* sentence)
{
    int i,count=1;
    for(i=0; sentence[i]!='\0';++i)
    {
        if(sentence[i]==' ')
            count++;
    }
    cout<<"\nThere are "<<count<<" words in the given string!\n";

    return count;
}
