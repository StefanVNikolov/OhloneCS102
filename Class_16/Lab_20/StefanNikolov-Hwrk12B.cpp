//Stefan Nikolovs ORCHARD TABLE
// This program allows the user to edit a specific record.
#include<iostream>

#include<fstream>

#include<string>

#include<vector>

#include <iomanip>

#include <string.h>

#include <cmath>

#include <ctime>

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

string createEmptyInventory();
string editInventory();

string displayItem(int);
string displayItems();

string editInventory();

string makeAnOrder();
string createReorderReport();
string createRevenueReport();

string saveInventory();


int main()
{
bool exit = false;
vector<std::string> logs;
do
{
    string log;
    int answer;

    displayMenu();
    cout << "Enter [1-8]: ";
    cin >> answer;

    switch(answer)
    {
        case 1:
            {
                saveInventory();
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
                log = editInventory();
                logs.push_back(log);
                break;
            }
        case 4:
            {
                log = makeAnOrder();
                break;
            }
        case 5:
            {
                log = createReorderReport();
                break;
            }
        case 6:
            {
                log = createRevenueReport();
                break;
            }
        case 7:
            {
                log = saveInventory();
                break;
            }
        case 8:
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
        inventory.write(reinterpret_cast < char * > ( & record),sizeof(record));
    }
    // Close the file.
    inventory.close();
    string log = std::to_string(NUM_RECORDS) + " empty records were created.\n";
    return log;
}

void displayMenu()
{
    cout << "   Stefan's ORCHARD TO TABLE ORDERING SYSTEM" << endl << endl;
    cout << "1. Create Empty Inventory" << endl;
    cout << "2. Display State of Inventory" << endl;
    cout << "3. Edit Inventory" << endl;
    cout << "4. Make an Order" << endl;
    cout << "5. Create Reorder Report" << endl;
    cout << "6. Create Revenue Report" << endl;
    cout << "7. Save Current Inventory" << endl;
    cout << "8. Quit" << endl;
}


string displayItem(int recNum)
{
    InventoryItem record; // To hold an inventory record
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);
    // Move to the record and read it.
    inventory.seekg(recNum * sizeof(record), ios::beg);
    inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));
    // Display the record contents.
    std::cout.width(16); std::cout << std::left << record.desc;
    cout << fixed << setprecision(2);
    std::cout.width(12); std::cout << std::left << record.price;
    std::cout.width(4); std::cout << std::right << record.quantity_in_stock;
    std::cout.width(11); std::cout << std::right << record.quantity_sold << endl;

    inventory.close();
    string log = "Record N" + std::to_string(recNum) + " was displayed.\n";
    return log;
}

string displayItems()
{
    cout << "\nITEM# DESCRIPTION     PRICE     #INSTOCK     #SOLD" << endl;
    for(int currentItem = 0; currentItem < NUM_RECORDS; currentItem++)
    {
       std::cout.width(6); std::cout << std::left << currentItem + 1;
       displayItem(currentItem);
    }
    string log ="All the items were displayed.\n";
    return log;
}

string editInventory()
{
    InventoryItem record; // To hold an inventory record
    long recNum; // To hold a record number
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);

    char continueEdit = 'y';
    int firstChange = 1;

    while(continueEdit == 'y' || continueEdit == 'Y')
    {
        if(firstChange != 1)
            displayMenu();
        // Get the record number of the desired record.
        cout << "Which Item # do you want to edit? [1-" << NUM_RECORDS << "] ";
        cin >> recNum;
        // Move to the record and read it.
        inventory.seekg((recNum - 1)* sizeof(record), ios::beg);
        inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));
        // Display the record contents.
        cout << "\nITEM# DESCRIPTION     PRICE     #INSTOCK     #SOLD" << endl;
        std::cout.width(6); std::cout << std::left << recNum;
        displayItem(recNum - 1);

        // Get the new record data.
        cout << "\nEnter the new data:\n";
        cout << "New Description: ";
        cin.ignore();
        cin.getline(record.desc, DESC_SIZE);
        cout << "New Price: ";
        cin >> record.price;
        cout << "New Quantity in Stock: ";
        cin >> record.quantity_in_stock;
        cout << "New Quantity Sold: ";
        cin >> record.quantity_sold;
        // Move back to the beginning of the this record's position.
        inventory.seekp((recNum - 1) * sizeof(record), ios::beg);
        // Write the new record over the current record.
        inventory.write(reinterpret_cast < char * > ( & record), sizeof(record));
        cout << "Do you want to edit another record? (Y/N)";
        cin.ignore();
        cin >> continueEdit;
        firstChange = 0;
        Clear();
    }
    // Close the file.
    inventory.close();
    string log = "Record N" + std::to_string(recNum) + " was changed.\n";
    return log;
}

string makeAnOrder()
{
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);
    InventoryItem record; // To hold an inventory record

    int choice = 0;
    int amount = 0;
    while(choice != -1)
    {
        // Display the record contents.
        displayItems();
        cout << endl << "Which Item # do you want to order? (-1 to exit) ";
        cin >> choice;

        if(choice != -1)
        {
            cout << "\nDESCRIPTION     PRICE     #INSTOCK     #SOLD" << endl;
            displayItem(choice - 1);

            // Move to the record and read it.
            inventory.seekg((choice - 1)* sizeof(record), ios::beg);
            inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));

            double price = record.price;
            int itemCount = record.quantity_in_stock;
            int itemSoldCount = record.quantity_sold;

            cout << endl << "How many items do you want? ";
            cin >> amount;

            if(amount <= itemCount)
            {
                itemCount -= amount;
                itemSoldCount += amount;
                record.quantity_in_stock = itemCount;
                record.quantity_sold = itemSoldCount;

                // Move back to the beginning of the this record's position.
                inventory.seekp((choice - 1) * sizeof(record), ios::beg);
                // Write the new record over the current record.
                inventory.write(reinterpret_cast < char * > ( & record), sizeof(record));

                cout << "Amount due: $" << amount * price;
            }
            else
            {
                cout << "Sorry, your order exceeds number in stock!" << endl;
            }
            cin.ignore();
            cin.get();
            Clear();
        }
    }

    return "Order was made!";
}

string createReorderReport()
{
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);
    InventoryItem record; // To hold an inventory record

    cout << endl;
    cout << "ITEM            STOCK" << endl;
    for(int currentItem = 0; currentItem < NUM_RECORDS; currentItem++)
    {

        // Move to the record and read it.
        inventory.seekg(currentItem * sizeof(record), ios::beg);
        inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));

        if(record.quantity_in_stock <= 5)
        {
            // Display the record contents.
            std::cout.width(16); std::cout << std::left << record.desc;
            std::cout.width(4); std::cout << std::right << record.quantity_in_stock;
            cout << endl;
        }
    }

    inventory.close();
    return "test";
}

string createRevenueReport()
{
    InventoryItem record; // To hold an inventory record
    // Open the file in binary mode for input and output.
    fstream inventory("Inventory.dat", ios:: in | ios::out | ios::binary);

    cout << "\nITEM#      DESCRIPTION  #INSTOCK   #SOLD   PRICE  REVENUE" << endl;
    for(int currentItem = 0; currentItem < NUM_RECORDS; currentItem++)
    {
        std::cout.width(5); std::cout << std::right << currentItem + 1;
        // Move to the record and read it.
        inventory.seekg(currentItem * sizeof(record), ios::beg);
        inventory.read(reinterpret_cast < char * > ( & record), sizeof(record));
        // Display the record contents.
        std::cout.width(17); std::cout << std::right << record.desc;
        std::cout.width(10); std::cout << std::right << record.quantity_in_stock;
        std::cout.width(8); std::cout << std::right << record.quantity_sold;
        cout << fixed << setprecision(2);
        std::cout.width(8); std::cout << std::right << record.price;
        cout << fixed << setprecision(2);
        std::cout.width(9); std::cout << std::right << record.price * record.quantity_sold << endl;
    }
    return "";
}

string saveInventory()
{
    const int MAXLEN = 80;
    char date[MAXLEN];
    time_t t = time(0);
    strftime(date, MAXLEN, "_%Y-%d-%m", localtime(&t));
    string copyFileName = "inventory" + string(date) + ".dat";

    // Open the file for binary output.
    fstream in("Inventory.dat",ios::binary|ios::in);
    fstream out(copyFileName,ios::binary|ios::out);

    char c;
    while(true) {
    c=in.get();
    if(in.eof()) break;
    out.put(c);
    }
    in.close();
    out.close();

    std::cout << copyFileName << " was created!" << endl;
    return "";
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
