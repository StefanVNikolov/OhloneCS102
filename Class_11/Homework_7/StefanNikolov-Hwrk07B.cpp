//Stefan Vladimirov Nikolov

//This program uses arrays to compare the
//correct answers of an exam with the
//answers of a student

#include <iostream>

#include <fstream>

#include <string>

#include <iomanip>

#include <vector>

using namespace std;
void ShowMissedQuestions(vector <char> studentAnswers, vector <char> correctAnswers, int studentAnswersCount, int correctAnswersCount) {
    if(studentAnswersCount == correctAnswersCount)
    {
        int missedQuestions = 0;
        for (int currentAnswer = 0; currentAnswer <= correctAnswersCount - 1; currentAnswer++) {
            if (studentAnswers[currentAnswer] != correctAnswers[currentAnswer]) {
                cout << "The student missed question N[" << currentAnswer + 1 << "]\n";
                cout << "\tStudent Answer - [" << studentAnswers[currentAnswer] << "]\n";
                cout << "\tCorrect Answer - [" << correctAnswers[currentAnswer] << "]\n\n";
                missedQuestions++;
            }
        }
        cout << "___________________________________________\n";
        cout << "Total Missed : " << missedQuestions << endl;
        cout << "Correct Answers: " << 20 - missedQuestions << "/" << 20 << endl;
        double finalScore = (double(20 - missedQuestions) / 20.00) * 100;
        cout << fixed << setprecision(2);
        cout << "Final Score: " << finalScore << " %" << endl;
    }
    else
    {
        cout << "Error:\n";
        cout << "The student provided " << studentAnswersCount << " answers\n";
        cout << "The exam contains of " << correctAnswersCount << " questions\n";

    }
}

int main() {

    cout << "\tSTEFAN NIKOLOV'S EXAM CHECK\n";
    cout << "___________________________________________\n\n";

    vector <char> correctAnswers;
    vector <char> studentAnswers;
    int correctAnswersCount = 0;
    int studentAnswersCount = 0;

    ifstream correctAnswersFile;
    ifstream studentAnswersFile;
    correctAnswersFile.open("CorrectAnswers.txt"); // open correct answer file
    studentAnswersFile.open("StudentAnswers.txt"); // open student answer file

    //read from correct answers file
    if (correctAnswersFile.is_open()) { //checking whether the file is open
        string line;
        while (getline(correctAnswersFile, line)) { //read data from file object and put it into string.
            correctAnswers.push_back(line[0]); //get the first part of the string to convert it to a char
            correctAnswersCount++;
        }
        correctAnswersFile.close(); //close the file object.

    }
    //read from student answers file
    if (studentAnswersFile.is_open()) { //checking whether the file is open
        string line;
        while (getline(studentAnswersFile, line)) { //read data from file object and put it into string.
            studentAnswers.push_back(line[0]); //get the first part of the string to convert it to a char
            studentAnswersCount++;
        }
        studentAnswersFile.close(); //close the file object.

    }

    ShowMissedQuestions(studentAnswers, correctAnswers, studentAnswersCount, correctAnswersCount);
    cin.get();
    return 0;
}
