//Stefan Nikolov

//This program calculates
//the sum or the product between 1 and a
//number entered by the user
#include<iostream>
using namespace std;

// Receives an integer as input. USE AN ACCUMULATOR to calculate the sum of
// the integers from 1 to this number. Returns the result.
int calcSum(int sumEnd){
    int sum = 0;
    for(int currentNumber = 1; currentNumber <= sumEnd; currentNumber++)
    {
        sum += currentNumber;
    }
    return sum;
}

// Receives an integer as input. USE AN ACCUMULATOR to calculate the product
// of the integers from 1 to this number. Returns the result.
int calcProd(int prodEnd){
    int product = 1;
    for(int currentNumber = 1; currentNumber <= prodEnd; currentNumber++)
    {
        product *= currentNumber;
    }
    return product;
}

// Receives no input. Prompts the user to enter an integer. Uses a loop to
// validate. Insures that no number, entered, is negative or so large that the
// resulting product becomes negative. Returns the result.
int getNum(){
    int input;
    cout << "Enter an integer greater than 1: ";
    cin >> input;
    while(input <= 1)
    {
         cout << "Must be greater than 1, re-enter: ";
         cin >> input;
    }
    return input;
}

// This method asks the user for an input to choose from sum or product
// If something else is entered the function gives an error
// If s or S is entered the function gives the sum between 1 and the number the user enters
// If p or P is entered the function gives the product between 1 and the number the user enters
void calculateSum_Product()
{
    char userChoice;
    cout << "Enter S for sum, P for prod: ";
    cin >> userChoice;
    switch(userChoice)
    {
          case 'P':
          case 'p':
              {
                  // Take an input
                  // Validate if the input is too large
                  int prodEnd = getNum();
                  int product = calcProd(prodEnd);
                  while(product <= 0)
                  {
                      cout << "The integer is too large!\n";
                      prodEnd = getNum();
                      product = calcProd(prodEnd);
                  }
                  cout << "The product of the numbers from 1 to " << prodEnd;
                  cout << " is " << product << endl;
              }
              break;

          case 'S':
          case 's':
              {
                  // Take an input
                  // Validate if the input is too large
                  int sumEnd = getNum();
                  int sum = calcSum(sumEnd);
                  while(sum <= 0)
                  {
                      cout << "The integer is too large!\n";
                      sumEnd = getNum();
                      sum = calcSum(sumEnd);
                  }
                  cout << "The sum of the numbers from 1 to " << sumEnd;
                  cout << " is " << sum << endl;
              }
              break;

          default:
                 cout << "Invalid choice!\n";
                 break;
    }
}

// Program starts here
int main()
{
    cout << "\tStefan Nikolov's Accumulative Calculator\n\n";
    char continueProgram = 'y';
    while(continueProgram == 'y' || continueProgram == 'Y')
    {
        calculateSum_Product();
        cout << "Again(y/n)? ";
        cin >> continueProgram;
    }
}



