// This program allows the user to edit a specific record.
#include<iostream>

#include<fstream>

#include<string>

#include<vector>

#include <iomanip>

#include <string.h>

#include <cmath>

using namespace std;

const int DESC_SIZE = 31; // Description size
int NUM_RECORDS = 5;

// Declaration of InventoryItem structure
struct InventoryItem {
    char desc[DESC_SIZE];
    int ID;
    int qty;
    double price;
};

void displayMenu();
string createEmptyInventory();
string displayItems();
string makeChanges();
string displayItem();
string deleteItem();

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
                log = displayItems();
                logs.push_back(log);
                break;
            }

        case 3:
            {
                log = makeChanges();
                logs.push_back(log);
                break;
            }
        case 4:
            {
                log = displayItem();
                logs.push_back(log);
                break;
            }
        case 5:
            {
                log = deleteItem();
                logs.push_back(log);
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
    cout << "\nEnter the amount of empty records: ";
    cin >> NUM_RECORDS;

    // Create an empty InventoryItem structure.
    InventoryItem record = {"",0,0,0.0};
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

string displayItems()
{
    InventoryItem record; // To hold an inventory record
    // Open the file for binary input.
    fstream inventory("Inventory.dat", ios:: in | ios::binary);
    // Now read and display the records.
    cout << "Description     ID     Quantity     Price" << endl;
    inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));
    while (!inventory.eof()) {
        int afterDescription = 16 - strlen(record.desc);
        int afterID = 6;
        int afterQuantity = 12;
        if(record.ID != 0)
            afterID = 8 - (int(log10(record.ID))+2);
        if(record.qty != 0)
            afterQuantity = 14 - (int(log10(record.qty))+2);
        int firstRecord = 0;
        if(firstRecord == 0 && record.ID != 0 && record.qty != 0)
        {
           afterID = 8 - (int(log10(record.ID))+2);
           afterQuantity = 14 - (int(log10(record.qty))+2);
           firstRecord = 1;
        }
        cout << fixed << setprecision(2);
        cout << record.desc <<
        string(afterDescription, ' ' )<< record.ID <<
        string(afterID, ' ' )<< record.qty <<
        string(afterQuantity, ' ' )<< "$" <<record.price << endl;
        inventory.read(reinterpret_cast < char * > ( & record),
            sizeof(record));
    }
    // Close the file.
    inventory.close();
    string log ="All the items were displayed.\n";
    return log;
}

string displayItem()
{
    InventoryItem record; // To hold an inventory record
    long recNum; // To hold a record number
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);
    // Get the record number of the desired record.
    cout << "Which record do you want to display? ";
    cin >> recNum;
    // Move to the record and read it.
    inventory.seekg(recNum * sizeof(record), ios::beg);
    inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));
    // Display the record contents.
    cout << "\nDescription     ID     Quantity     Price" << endl;
    int afterDescription = 16 - strlen(record.desc);
    int afterID = 6;
    int afterQuantity = 12;
    if(record.ID != 0)
        afterID = 7 - log10(record.ID);
    if(record.qty != 0)
        afterQuantity = 13 - log10(record.qty);
    int firstRecord = 0;
    if(firstRecord == 0 && record.ID != 0 && record.qty != 0)
    {
        afterID = 6 - log10(record.ID);
        afterQuantity = 12 - (log10(record.qty));
        firstRecord = 1;
    }
    cout << fixed << setprecision(2);
    cout << record.desc <<
    string(afterDescription, ' ' )<< record.ID <<
    string(afterID, ' ' )<< record.qty <<
    string(afterQuantity, ' ' )<< "$" <<record.price << endl;
    // Close the file.
    inventory.close();
    string log = "Record N" + std::to_string(recNum) + " was displayed.\n";
    return log;
}

string makeChanges()
{
    InventoryItem record; // To hold an inventory record
    long recNum; // To hold a record number
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);
    // Get the record number of the desired record.
    cout << "Which record do you want to edit? [0-" << NUM_RECORDS-1 << "] ";
    cin >> recNum;
    // Move to the record and read it.
    inventory.seekg(recNum * sizeof(record), ios::beg);
    inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));
    // Display the record contents.
    int firstRecord = 0;
    cout << "Description     ID     Quantity     Price" << endl;
    int afterDescription = 16 - strlen(record.desc);
    int afterID = 6;
    int afterQuantity = 12;
    if(record.ID != 0)
        afterID = 8 - (int(log10(record.ID))+2);
    if(record.qty != 0)
        afterQuantity = 14 - (int(log10(record.qty))+2);
    if(firstRecord == 0 && record.ID != 0 && record.qty != 0)
    {
       afterID = 8 - (int(log10(record.ID))+2);
       afterQuantity = 14 - (int(log10(record.qty))+2);
       firstRecord = 1;
    }
    cout << fixed << setprecision(2);
    cout << record.desc <<
    string(afterDescription, ' ' )<< record.ID <<
    string(afterID, ' ' )<< record.qty <<
    string(afterQuantity, ' ' )<< "$" <<record.price << endl;
    // Get the new record data.
    cout << "\nEnter the new data:\n";
    cout << "New Description: ";
    cin.ignore();
    cin.getline(record.desc, DESC_SIZE);
    cout << "New Quantity: ";
    cin >> record.qty;
    cout << "New ID: ";
    cin >> record.ID;
    cout << "New Price: ";
    cin >> record.price;
    // Move back to the beginning of the this record's position.
    inventory.seekp(recNum * sizeof(record), ios::beg);
    // Write the new record over the current record.
    inventory.write(reinterpret_cast < char * > ( & record), sizeof(record));
    // Close the file.
    inventory.close();
    string log = "Record N" + std::to_string(recNum) + " was changed.\n";
    return log;
}

string deleteItem()
{
    InventoryItem record; // To hold an inventory record
    long recNum; // To hold a record number
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);
    // Get the record number of the desired record.
    cout << "Which record do you want to delete? ";
    cin >> recNum;
    // Move to the record and read it.
    inventory.seekg(recNum * sizeof(record), ios::beg);
    inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));
    // Display the record contents.
    cout << "\nDescription     ID     Quantity     Price" << endl;
    int afterDescription = 16 - strlen(record.desc);
    int afterID = 6;
    int afterQuantity = 12;
    if(record.ID != 0)
        afterID = 7 - log10(record.ID);
    if(record.qty != 0)
        afterQuantity = 13 - (log10(record.qty));
    cout << fixed << setprecision(2);
    cout << record.desc <<
    string(afterDescription, ' ' )<< record.ID <<
    string(afterID, ' ' )<< record.qty <<
    string(afterQuantity, ' ' )<< "$" <<record.price << endl;
    // Delete the old record data.;
    char *begin = record.desc;
    char *end = begin + sizeof(record.desc);
    std::fill(begin, end, '\0');
    record.ID = 0;
    record.qty = 0;
    record.price = 0.0;
    // Move back to the beginning of the this record's position.
    inventory.seekp(recNum * sizeof(record), ios::beg);
    // Write the new record over the current record.
    inventory.write(reinterpret_cast < char * > ( & record), sizeof(record));
    // Close the file.
    inventory.close();
    string log = "Record N" + std::to_string(recNum) + " was deleted.\n";
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
