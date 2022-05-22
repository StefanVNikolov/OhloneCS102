// This program allows the user to edit a specific record.
#include<iostream>

#include<fstream>

#include<string>

#include<vector>

#include <iomanip>

#include <string.h>

#include <cmath>

using namespace std;

const int DESC_SIZE = 20; // Description size
int NUM_RECORDS = 7;

// Declaration of InventoryItem structure
struct InventoryItem {
    char desc[DESC_SIZE];
    double price;
    int quantity_in_stock;
    int quantity_sold;
};

void displayMenu();
void Clear();

int main()
{
bool exit = false;
vector<std::string> logs;
do
{
    string log;
    int answer;

    displayMenu();
    cout << "Enter [1-6]: ";
    cin >> answer;

    switch(answer)
    {
        case 1:
            {
                log = createEmptyInventory();
                logs.push_back(log);
                break;
            }

        case 2:
            {
                //log = displayItems();
                //logs.push_back(log);
                break;
            }

        case 3:
            {
                //log = makeChanges();
                //logs.push_back(log);
                break;
            }
        case 4:
            {
                //log = displayItem();
                //logs.push_back(log);
                break;
            }
        case 5:
            {
                //log = deleteItem();
                //logs.push_back(log);
                break;
            }
        case 6:
            {
                int currentLog = 1;
                cout << "\nLog file___\n";
                for(string log : logs)
                {
                    cout << currentLog << ". " << log;
                    currentLog++;
                }
                exit = true;
                break;
            }

        default:
            cout << "Invalid choice! Please try again...\n";  //<- print this message
            break;
    }
    cin.ignore();
    cin.get();
    Clear();
} while(exit == false);

}

string createEmptyInventory()
{
    cout << "\nEnter the amount of empty records [(MIN)1-(MAX)10]: ";
    cin >> NUM_RECORDS;

    // Create an empty InventoryItem structure.
    InventoryItem record = {"",0.0,0,0};
    // Open the file for binary output.
    fstream inventory("Inventory.dat", ios::out | ios::binary);
    // Write the blank records.
    for (int count = 0; count < NUM_RECORDS; count++) {
        cout << "Now writing record " << count << endl;
        inventory.write(reinterpret_cast < char * > ( & record),
            sizeof(record));
    }
    // Close the file.
    inventory.close();
    string log = std::to_string(NUM_RECORDS) + " empty records were created.\n";
    return log;
}



void displayMenu()
{
    cout << "\t\tMain Menu" << endl << endl;
    cout << "1. Create file of empty inventory" << endl;
    cout << "2. Display the contents of all the items" << endl;
    cout << "3. Make changes to a particular item" << endl;
    cout << "4. Search and display a particular item" << endl;
    cout << "5. Delete an item" << endl;
    cout << "6. Quit" << endl << endl;
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
