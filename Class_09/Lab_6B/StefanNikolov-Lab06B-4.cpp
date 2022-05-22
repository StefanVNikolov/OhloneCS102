#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void takeInput(double &, int &, int &);
void calulateBMI(double &, int &, int &, double &);
int main()
{
    double weight, BMI;
    int height_f, height_i;
    char another = 'y';
    while(another == 'y' || another == 'Y'){
        takeInput(weight, height_f, height_i);
        calulateBMI(weight, height_f, height_i, BMI);

        cout << fixed << setprecision(2);
        cout << "Your BMI is " << BMI << endl;

        if(BMI < 18.5)
            cout << "You could eat more than you are currently doing!! \n\n";
        if(BMI >= 18.5 && BMI <= 25)
            cout << "You are in optimal shape!! Good Work! \n\n";
        if(BMI > 25)
            cout << "You might consider reducing Caloric Intake!! \n\n";
        cout << "Another? (y/n)";
        cin >> another;
    }

    return 0;
}
void takeInput(double &weight, int &height_feet, int &height_inches){
    cout << "\n++++++++++++++++++++++++++++++++++++\n"
    << " Body Mass Index"
    << "\n++++++++++++++++++++++++++++++++++++\n";
    cout << "Enter your weight (in pounds): ";
    cin >> weight;
    cout << "\nEnter your height (in feet): ";
    cin >> height_feet;
    cout << "\nEnter your height (in inches): ";
    cin >> height_inches;
}
void calulateBMI(double &weight, int &height_feet, int &height_inches, double &BMI){
    int height = height_feet * 12 + height_inches;
    BMI = (weight * 703) / pow(height, 2);
}
