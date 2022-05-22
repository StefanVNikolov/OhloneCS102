//Stefan Nikolov
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;

// Declaration of Sales Report
struct SalesReport {
    string name;
    double productSales_1;
    double productSales_2;
};

string checkIfExists();        // Checks if the datafile exists
void Clear();                  // Clears the screen
int countReports(string);      // Counts the number of reports
void loadSalesReports(string, SalesReport*);  // Loads the Sales Reports
void generateSalesReport(SalesReport*, int);  // Displays a General Sales Report
void generateDiamondReport(SalesReport*, int); // Displays a Diamond Report (people with sales above 10k)

int main()
{
    SalesReport reports[20]; // To store the structure values
    int recordsCount = 0;    // To store the number of records

    string fileName = "DNE";
    while(fileName == "DNE")  // Asks for a name until a true path is reached
    {
        fileName = checkIfExists();
        cin.ignore();
        cin.get();
        Clear();              // Clears the buffer
    }
    recordsCount = countReports(fileName); // Counts the number of reports

    if(recordsCount <= 20) // Load the sales reports only if less that 20
        loadSalesReports(fileName, reports);

    generateSalesReport(reports, recordsCount);

    cout << "\n\nPress Enter to continue...";
    cin.get();
    Clear();              // Clears the buffer

    generateDiamondReport(reports, recordsCount);
    cout << "\n\nPress Enter to continue...";
    cin.get();
    Clear();              // Clears the buffer

    cout << "Report generated\nProgrammed by Stefan Nikolov";
    cout << "\nPress Enter to Finish...";
    cin.get();

    return 0;
}

string checkIfExists()
{
    string datafileName; // To hold the name
    string result;       // To hold the result

    //Display the main menu
    cout << "Enter data file: ";
    cin >> datafileName;

    //Creating ifstream to try to open the file
    ifstream dataFile;
    dataFile.open(datafileName);

    if(dataFile)
    {
        cout << "\nThe Datafile was found." << endl;
        cout << "Press Enter to continue..." << endl;
        result = datafileName;
    }
    else
    {
        cout << "\nThe Datafile was not found." << endl;
        cout << "Press Enter to continue..." << endl;
        result = "DNE";
    }
    dataFile.close();
    return result;
}

int countReports(string dataFile)
{
    int number_of_lines = 0;
    string line;
    ifstream myfile(dataFile);

    while (getline(myfile, line))
        ++number_of_lines;
    myfile.close();
    return number_of_lines;
}

void Clear()
{
    #if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

void loadSalesReports(string datafile, SalesReport reports[20])
{
    // Open datafile reader
    ifstream read;
    read.open(datafile);

    // Current sales report
    SalesReport currentSalesReport;
    int currentReportIndex = 0;

    // Load the first name
    getline(read, currentSalesReport.name, '#');

    while(!read.eof()){
        // Read the numerical data
        read >> currentSalesReport.productSales_1;
        read >> currentSalesReport.productSales_2;

        // Assigning a new report into the sales array
        reports[currentReportIndex] = currentSalesReport;
        currentReportIndex++;

        getline(read, currentSalesReport.name, '#');
    }
    read.close();
}

void generateSalesReport(SalesReport reports[20], int reportCount)
{
    double total, totalCommission;

    cout << "\tGeneral Sales Report\n";
    cout << "\nEmployee      Total Sales   Commission" << endl;
    for(int currentReport = 0;  currentReport < reportCount; currentReport++)
    {
        if(currentReport == 0)
        {
            cout.width(14);
            cout << std::left << reports[currentReport].name;
        }
        else
        {
            // Display the name left intended
            cout.width(15);
            cout << std::left << reports[currentReport].name;
        }
        cout << "$"; // Display dollar sign
        cout.width(9);
        // Calculate the total sales
        double totalSales = reports[currentReport].productSales_1 + reports[currentReport].productSales_2;
        cout << fixed << setprecision(2) <<std::right << totalSales;
        total += totalSales;

        cout << "    $"; // Display dollar sign
        cout.width(8);
        // Calculate the total sales
        double commission;
        if(totalSales < 4000.00)
            commission = totalSales * 0.05;
        else if(totalSales >= 4000.00 && totalSales < 8000)
            commission = totalSales * 0.07;
        else
            commission = totalSales * 0.1;
        cout << fixed << setprecision(2) <<std::right << commission;
        totalCommission += commission;
    }

    cout << "\n\nTotal" + string(9,' ') << "$ ";
    cout << fixed << setprecision(2) << total;
    cout << string(4,' ') << "$ ";
    cout << fixed << setprecision(2) << totalCommission;
}

void generateDiamondReport(SalesReport reports[20], int reportCount)
{
    double total, totalCommission;

    cout << "\tDiamond Report\n";
    cout << "\nName            Total Sales" << endl;
    for(int currentReport = 0;  currentReport < reportCount; currentReport++)
    {
        // Calculate the total sales
        double totalSales = reports[currentReport].productSales_1 + reports[currentReport].productSales_2;
        if(totalSales >= 10000.00)
        {
            if(currentReport == 0)
            {
                cout.width(16);
                cout << std::left << reports[currentReport].name;
            }
            else
            {
                // Display the name left intended
                cout.width(17);
                cout << std::left << reports[currentReport].name;
            }
            cout << "$"; // Display dollar sign
            cout.width(9);
            cout << fixed << setprecision(2) <<std::right << totalSales;
        }
    }
}


