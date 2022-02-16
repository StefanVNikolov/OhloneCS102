// Stefan Nikolov
// CS-102 Laboratory 3 Program A
// This program calculates
// plays a word game with the user
#include <iostream>
using namespace std;
int main()
{
    // Declaring variables
    string name, city, college, profession, animal, petName;
    int age;

    cout <<"Please Enter Your Name: ";
    getline(cin, name);

    cout <<"Enter the City that you live in: ";
    getline(cin, city);

    cout <<"Enter your age when you started attending college: ";
    cin >> age;
    cin.ignore();

    cout <<"Enter your College name: ";
    getline(cin, college);

    cout <<"Enter your Profession: ";
    getline(cin, profession);

    cout <<"Enter the type of pet you like: ";
    getline(cin, animal);

    cout <<"Enter the pet's name: ";
    getline(cin, petName);

    // Displaying the result
    cout << endl;
    cout << "Thee once was a person named " << name<< " who lived in "<< city<< ". At the age of "<< age<< "," << endl;
    cout << name<< " went to college at "<< college<< ". "<< name<< " graduated and went to work as a " << endl;
    cout << profession<< ". Then, "<< name<< " adopted a "<< animal<< " named "<< petName<< ". They both " << endl;
    cout << "lived happily ever after!";

    cin.ignore();
    cin.get();

    return 0;


}   // end main

