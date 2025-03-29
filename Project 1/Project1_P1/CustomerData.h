// Travis Bailey
// Updated on 3/8/23
// CustomerData Class Header

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include <iostream>
#include <string>
#include "PersonData.h"

using namespace std;

class CustomerData:public PersonData
{
    protected:
        int customerNumber; // Customer Number Member
        bool mailingList;   // Mailing List Member
        char mail;
    public:
        CustomerData(){;}
        void setCustomerNumber(int a){customerNumber=a;}    // Accessor set Customer Number
        void setMailingList(bool a){mailingList=a;}  // Accessor set Mailing List
        virtual void PrintRecord() {     // Calling the Parent function, then adding the Mailing list and Customer Number
            PersonData::PrintRecord();cout<<"CustomerNumber: " << customerNumber << endl;
            if (mailingList){cout << "On the Mailing List: Yes" << endl;}
            else {cout << "On the Mailing List: No" << endl;}
        }
        virtual string getRecord(){     // Calling Parent function, adding to the strm variable
            string strm = PersonData::getRecord() + " / " + "C#: " + to_string(customerNumber) + " / ";
            if (mailingList)strm += "ML: Yes";
            else {strm  += "ML: No";} return strm;
        }
        virtual void asking(){PersonData::asking(); cout << "Input Customer Number: ";  // Void asking for the values using parent functions, adding customer number and mailing
                cin >> customerNumber;
                cout << "Do they wish to be on the mailing list? (Y/N): ";
                cin >> mail; mailingList = (mail == 'Y' || mail == 'y');
        }
};

class PreferredCustomer:public CustomerData
{
    private:
        double purchasesAmount=0; // Purchase Amount Number Member
        double discountLevel=0;   // Discount Level Member
    public:
        PreferredCustomer(){;}      // Default Constructor
        void purchase();        // Set Purchase values
        void updateDiscount();      // Use Purchase values to update the Discount Level
        void PrintRecord(){CustomerData::PrintRecord(); // Print Record using the Parent Functions
                cout << "Purchases Amount: " << purchasesAmount << endl; 
                cout << "Discount Level: " << discountLevel*100.0 << "%" << endl;
            }
        string getRecord(){ // Get Record using Parent functions, adding the accounts and discounts
                string strm = CustomerData::getRecord()+ " / " + "Purchases Account: $" + to_string(purchasesAmount) + " / " + "Discount: " + to_string(discountLevel*100) + "%"; 
                return strm;
            }
        void asking(){CustomerData::asking(); purchase();}  // Calling the functions to get values
};
#endif