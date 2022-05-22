// Stefan Nikolov
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    cout << "Stefan Nikolov's ASCII Table \n";
    int currentCharr = 0;

    for(int i = 0; i < 16 ; i++){
        for(int j = 0; j < 16 ; j++){
            if(char(currentCharr) != '\n'){
                cout << char(currentCharr) << " ";
            }
            currentCharr++;
        }
        cout << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}
