// Stefan Vladimirov Nikolov
// This program considering the effect of changing the
// basic Reproductive number, R0
// on the strength of the epidemic
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
bool checkR0_rate(double R0, double suscepriable, double infected, int days, double alpha, int closingInfectionResult) // Entering needed information
{
    bool guess = false;

    // Creating files and saving the information
    ofstream susceptibleFile, infectedFile;
    string susceptibleFileName = "SusceptibleFor" + to_string(static_cast<int>(1/alpha)) + ".txt";
    string infectedFileName = "InfectedFor" + to_string(static_cast<int>(1/alpha)) + ".txt";
    susceptibleFile.open(susceptibleFileName);
    infectedFile.open(infectedFileName);

    // Initializing work variables
    double s, sp; // susceptible people to the virus, and the previous day
    double i, ip; // infected people at any time, and the previous day
    int N = suscepriable + infected; // number of people in the closed community

    s = suscepriable;
    i = infected;

    // Initializing additional variables
    double maxInfectionCases = 0;      // Max infection cases at all
    int maxInfectionDay = 0;           // The day with the most cases
    int minInfectionDay = 0;

    double beta = alpha*R0/double(N);

    // Calculating the SIR after given time
    for(int currentDay = 0; currentDay < days; currentDay++)
    {
        sp = s;
        ip = i;

        s = sp - beta*ip*sp;
        i = ip + beta*ip*sp - alpha*ip;

        //Writing information
        susceptibleFile << static_cast<int>(s) << endl;
        infectedFile << static_cast<int>(i) << endl;

        if(i > maxInfectionCases){ // Checking for a new infection maximum
            // If there is a maximum preset the value
            maxInfectionCases = i;
            maxInfectionDay = currentDay;
        }
        if(static_cast<int>(i) == 0 && currentDay > 0 && minInfectionDay == 0){
            minInfectionDay = currentDay;
        }
    }
    if((maxInfectionDay == days-1) && (static_cast<int>(maxInfectionCases) == closingInfectionResult))
        guess = true;

    else
        guess = false;

    cout << "1/ALPHA = " << alpha << endl;
    cout << "R0 = " << R0 << endl;
    cout << "Max number of infected people = " << static_cast<int>(maxInfectionCases) << endl;
    cout << "The day of the max infection  = "  << maxInfectionDay << endl << endl;
    if(minInfectionDay != 0){
        cout << "Infection cases reached 0 on day " << minInfectionDay << endl << endl;
    }
    cout << "_____________________________________" << endl;

    // Closing the files and returning the bool value
    susceptibleFile.close();
    infectedFile.close();
    return guess;

}
int main()
{
    // Values for 31 day periods
    bool three_Days = checkR0_rate(1.8547, 3710, 1, 31, 1.0/3.0, 621);  // 3 days - can't reach 621 infected people on day 31
    bool six_Days = checkR0_rate(2.5114119, 3710, 1, 31, 1.0/6.0, 621); // 6 days - the value R0 = 2.5114119
    bool ten_Days = checkR0_rate(3.439, 3710, 1, 31, 1.0/10.0, 621);    // 10 days - the value R0 = 3.439

    return 0;
}

