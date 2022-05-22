//Stefan Nikolov
#include<iostream>
#include <iomanip>
using namespace std;
double judgeScoresSum, lowestScore, highestScore, averageScore;
void getJudgeData(double &, double &, double &);
void calcScore(double &, double &, double &, double &);
int main()
{
    getJudgeData(judgeScoresSum, lowestScore, highestScore);
    calcScore(judgeScoresSum, lowestScore, highestScore, averageScore);
    cout <<fixed << setprecision(2);
    cout << "The Mean of the 3 middle scores is: " << averageScore << endl;
    cin.ignore();
    cin.get();
    return 0;
}
void getJudgeData(double &judgeScoresSum, double &lowestScore, double &highestScore)
{
    cout << "Stefan Nikolov's Scoreboard\n";
    double input;
    cout << "Enter Score from a Judge number 1: ";
    cin >> input;
    if(input > 0 && input <= 10)
    {
        judgeScoresSum += input;
        lowestScore = input;
        highestScore = input;
    }
    for(int i = 1; i < 5; i++)
    {
        if(i == 5)
            input = 0;
        else
            input = -1;
        while(input < 0 || input > 10)
        {
            cout << "Enter Score from a Judge number " << i + 1<< ": ";
            cin >> input;
            if(input >= 0 && input <= 10)
            {
                judgeScoresSum += input;
                if(input < lowestScore)
                {
                   lowestScore = input;
                   cout << "Lowest changed to " << lowestScore << endl;
                }
                if(input > highestScore)
                {
                    highestScore = input;
                    cout << "Highest changed to " << highestScore << endl;
                }
            }
            else
            {
                cout << "\nError: The score must be between 0 and 10! \n";
                cout << "Please enter valid data and try again!\n\n";
            }
        }
    }
    cout << "Highest score of " << highestScore << " will be dropped\n";
    cout << "Lowest score of " << lowestScore << " will be dropped\n";
}
void calcScore(double &judgeScoresSum, double &lowestScore, double &highestScore, double &averageScore){
    judgeScoresSum -= (lowestScore + highestScore);
    averageScore = judgeScoresSum / 3.00;
}

