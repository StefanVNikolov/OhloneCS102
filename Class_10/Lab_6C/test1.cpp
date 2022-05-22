//Stefan Nikolov
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
int calculateFirstSpaces(int fixedSpaces, string name, double stocks){
    int nameLength = name.length();
    int stocksLength = 0;
    if(stocks >= 0){
        stocksLength = log10(int(stocks))+1;
    }
    else{
        stocksLength = log10(int(stocks*-1))+2;
    }
    int spaces = fixedSpaces - (nameLength-1) - stocksLength;
    return spaces;
}
int calculateSecondSpaces(int fixedSpaces, double stocks){
    int stocksLength = log10(int(stocks)) + 1;
    int spaces = fixedSpaces - stocksLength - 3;
    return spaces;
}
void totalValue(){
    ifstream read;
    string name;

    int firstLine = 0;
    double total;
    int shares;
    double purchasePrice, currentPrice;

    read.open("Stocks.txt");
    getline(read, name, '#');

    cout << "Stock Name" << setw(15) << "Profit" << endl;
    while(!read.eof()){
        read >> shares;
        read >> purchasePrice;
        read >> currentPrice;
        double profit = double(shares)*(currentPrice - purchasePrice);
        total += profit;

        int firstSpaceSeparation = 0;
        if(firstLine == 0){
            firstSpaceSeparation = calculateFirstSpaces(21, name, profit);
        }
        else{
            firstSpaceSeparation = calculateFirstSpaces(22, name, profit);
        }


        cout << fixed << setprecision(2);
        cout << name <<string(firstSpaceSeparation,' ') <<profit;
        read.ignore();
        firstLine = 1;
        getline(read, name, '#');
    }
    int secondSpaceSeparation = calculateFirstSpaces(22, "Total Value", total);
    cout << "\n\nTotal Value" << string(secondSpaceSeparation - 1,' ')<< total << endl;
    read.close();
}
void displayStocks(){
    ifstream read;
    string name;
    int firstLine = 0;
    int shares;
    double purchasePrice, currentPrice;
    read.open("Stocks.txt");
    getline(read, name, '#');
    cout << "Stock Name" << setw(15) << "# Shares" << setw(20) << "Purchase Price" << setw(20) << "Current Price" <<endl;
    while(!read.eof()){
        read >> shares;
        read >> purchasePrice;
        read >> currentPrice;

        int firstSpaceSeparation = 0;
        if(firstLine == 0){
            firstSpaceSeparation = calculateFirstSpaces(24, name, shares);
        }
        else{
            firstSpaceSeparation = calculateFirstSpaces(25, name, shares);
        }
        int secondSpaceSeparation = calculateSecondSpaces(20, purchasePrice);
        int thirdSpaceSeparation = calculateSecondSpaces(20, currentPrice);

        cout << fixed << setprecision(2);
        cout << name <<string(firstSpaceSeparation,' ') <<shares << string(secondSpaceSeparation - 1,' ') << "$" <<purchasePrice << string(thirdSpaceSeparation-1,' ') << "$" << currentPrice;
        read.ignore();
        firstLine = 1;
        getline(read, name, '#');
    }
    read.close();
}
void displayMenu(){
    int choice;
    do{
        cout << "\tMenu Options" << endl;
        cout << "1   Display Stock Portfolio\n";
        cout << "2   Display Profit/Loss\n";
        cout << "3   Exit Program\n";
        cout << "Enter menu option(enter y or Y to exit): ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                   displayStocks();
                   cout << endl;
                   break;
            case 2:
                   totalValue();
                   cout << endl;
                   break;
            default:
                   choice = 3;
                   cout << "Exiting Program..." << endl;
                   break;
        }
     }
    while(choice != 3);

}
int main()
{
    displayMenu();
    return 0;
}
