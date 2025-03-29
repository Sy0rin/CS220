// Travis Bailey
// Project 1
// 3/13/23

#include "CustomerData.h"
#include "PersonData.h"

using namespace std;
// Parent function to ask for all the values
void PersonData::asking(){
    cout << "Input Last Name: ";
    cin >> lastName;
    cout << "Input First Name: ";
    cin >> firstName;
    cout << "Input Street Address: ";
    cin.ignore(); // Ignore newline character left by cin
    getline(cin, address);
    cout << "Input City: ";
    cin >> city;
    cout << "Input State: ";
    cin >> state;
    cout << "Input Zip Code: ";
    cin >> zip;
    cout << "Input Phone Number: ";
    cin >> phone;
}
// Purchases function to prompt the purchase function for the 3rd option
void PreferredCustomer::purchase(){
    cout << "Input Purchases Amount: ";
    cin >> purchasesAmount;
    if(purchasesAmount<0.0) purchase();
    else updateDiscount();
}
void PreferredCustomer::updateDiscount(){
    //  Bracketted Update of Discount Levels
    if (purchasesAmount>=500.0) discountLevel=.05;
    if (purchasesAmount>=1000.0) discountLevel=.06;
    if (purchasesAmount>=1500.0) discountLevel=.07;
    if (purchasesAmount>=2000.0) discountLevel=.1;
}

