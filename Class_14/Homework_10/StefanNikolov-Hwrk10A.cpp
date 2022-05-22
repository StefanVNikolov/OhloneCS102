// Stefan Vladimirov Nikolov
// This program checks if a password is valid
#include <iostream>

#include <cstring> // For str

using namespace std;

char* convertToCharArray(string);
bool passwordConstraintsCheck(char*);


int main() {
    cout << "\tStefan Nikolov's password checker\n\n";
    string password;
    cout << "Enter your password: ";
    getline (cin, password);
    cout << endl;
    char* cpassword = convertToCharArray(password);
    bool valid = passwordConstraintsCheck(cpassword);

    if(valid)
        cout << "Your password is valid" << endl;

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
bool passwordConstraintsCheck(char* charPassword)
{
    bool valid = true;

    bool passwordLength = false;
    bool containsUpperCase = false;
    bool containsLowerCase = false;
    bool contains_digit = false;
    bool contains_punctoation = false;
    bool no_spaces = true;

    if(strlen(charPassword) >= 7)
        passwordLength = true;

    for(int currentChar = 0; currentChar < strlen(charPassword); currentChar++)
    {
        int passKey = charPassword[currentChar];
        if(passKey >= 65 && passKey <= 90)
            containsUpperCase = true;

        if(passKey >= 97 && passKey <= 122)
            containsLowerCase = true;

        if(passKey >= 48 && passKey <= 57)
            contains_digit = true;

        if((passKey >= 33 && passKey <= 47) ||
           (passKey >= 58 && passKey <= 64) ||
           (passKey >= 91 && passKey <= 96) ||
           (passKey >= 123 && passKey <= 126))
            contains_punctoation = true;

    }
    for(int currentChar = 0; currentChar < strlen(charPassword); currentChar++)
    {
        int passKey = charPassword[currentChar];
        if(passKey == 32)
        {
            no_spaces = false;
            break;
        }
    }

    if(!passwordLength)
    {
        cout << "The password must contain at least 7 characters. " << endl;
        valid = false;
    }
    if(!containsUpperCase || !containsLowerCase)
    {
        cout << "The password must contain at least one uppercase and one lowercase letter." << endl;
        valid = false;
    }
    if(!contains_digit)
    {
        cout << "The password must contain at least one digit." << endl;
        valid = false;
    }
    if(!contains_punctoation)
    {
        cout << "The password should contain at least one non-alpha, non-digit, non-space, punctuation character." << endl;
        valid = false;
    }
    if(!no_spaces)
    {
        cout << "The password should contain no spaces." << endl;
        valid = false;
    }

    return valid;
}


