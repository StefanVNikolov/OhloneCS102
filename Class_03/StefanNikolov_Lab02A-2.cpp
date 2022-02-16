// Stefan Nikolov
// This program calculates the sale price of an item
// that is regularly priced at $59.95, with a 20 percent
// discount subtracted.
#include <iostream>
using namespace std;
int main()
{
    // Variables to hold the regular price, the
    // amount of a discount, and the sale price.
    double regularPrice = 59.95, discount, salePrice, saleTax;
    // Calculate the amount of a 20% discount.
    discount = regularPrice * 0.20;
    // Calculate the sale price by subtracting the
    // discount from the regular price.
    salePrice = regularPrice - discount;
    // Calculate the amount of a 10% sales tax.
    saleTax = salePrice * 0.10;
    // Calculate the sale price by adding the
    // sales tax to the sale price.
    salePrice = salePrice + saleTax;
    // Display the results.
    cout << "Regular price: $" << regularPrice << endl;
    cout << "Discount amount: $" << discount << endl;
    cout << "Sale tax: $" << saleTax << endl;
    cout << "Sale price after tax: $" << salePrice << endl;
    cin.get();
    return 0;
}
