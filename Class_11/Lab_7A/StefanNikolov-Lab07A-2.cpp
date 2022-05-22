//Stefan Vladimirov Nikolov
#include <iostream>
#include <cmath>
using namespace std;

const int GRID_SIZE = 3;
const int WANTED_SUM = 15;
int NUMBER = 0;

bool isLoShuMagicSquare(const double[][GRID_SIZE]);
double sumOfEachRow(const double[][GRID_SIZE]);
double sumOfEachColumn(const double[][GRID_SIZE]);
double sumOfDiagonalTopLeftToRight(const double[][GRID_SIZE]);
double sumOfDiagonalTopRightToLeft(const double[][GRID_SIZE]);

void printMatrix(double arr[GRID_SIZE][GRID_SIZE])
{
    cout << "+-------+\n";
    for(int row = 0; row <= GRID_SIZE - 1 ; row++)
    {
        cout << "| ";
        for(int column = 0; column <= GRID_SIZE - 1 ; column++)
        {
            cout << arr[row][column] << " ";
        }
        cout << "|" << endl;
    }
    cout << "+-------+\n";
}

int main()
{

    cout << "Enter a " << pow(GRID_SIZE, 2) << " digit number: ";
    cin >> NUMBER;

    int number_copy = NUMBER;
    double grid_array[GRID_SIZE][GRID_SIZE];

    for(int currentRowPosition = 0; currentRowPosition <= GRID_SIZE - 1; currentRowPosition++)
    {
        for(int currentColumnPosition = 0; currentColumnPosition <= GRID_SIZE - 1; currentColumnPosition++)
        {
            int currentDigit = number_copy % 10;
            number_copy = number_copy / 10;
            grid_array[currentRowPosition][currentColumnPosition] = currentDigit;
        }
    }

    printMatrix(grid_array);
    cout << endl;
    if(isLoShuMagicSquare(grid_array))
    {
        cout << "It's a Lo Shu!";
    }
    else
    {
        cout << "It's not a Lo Shu!";
    }

    return 0;
}

double sumOfEachRow(const double array[][GRID_SIZE])
{
    double total;

    for(int row = 0; row < GRID_SIZE; row++)
    {
        total = 0;
        for(int column = 0; column < GRID_SIZE; column++)
            total += array[row][column];
    }
    return total;
}

double sumOfEachColumn(const double array[][GRID_SIZE])
{
    double total;
    for(int columns = 0; columns < GRID_SIZE; columns++)
    {
        total = 0;
        for (int row = 0; row < GRID_SIZE; row++)
            total += array[row][columns];
    }
    return total;
}

double sumOfDiagonalTopLeftToRight(const double array[][GRID_SIZE])
{
    double total = 0;

    for(int i = 0; i < GRID_SIZE; i++)
        total += array[i][i];

    return total;
}

double sumOfDiagonalTopRightToLeft(const double array[][GRID_SIZE])
{
    double total = 0;

    int column = (GRID_SIZE - 1);
    for (int row = 0; row < GRID_SIZE; row++)
    {
        total += array[row][column];
        column--;
    }

    return total;
}

bool isLoShuMagicSquare(const double array[][GRID_SIZE])
{
    if(
        sumOfEachRow(array)              == WANTED_SUM &&
        sumOfEachColumn(array)           == WANTED_SUM &&
        sumOfDiagonalTopLeftToRight(array)  == WANTED_SUM &&
        sumOfDiagonalTopRightToLeft(array)  == WANTED_SUM
       )
        return true;
    else
        return false;
}
