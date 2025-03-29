// Travis Bailey
// Updated on 3/8/23
// PersonData Class Header

#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <iostream>
#include <string>

using namespace std;

class PersonData
{
    protected:
        string lastName,firstName,city,address,state,zip,phone,strm; // Member Variables
    public:
        PersonData(){lastName="0";firstName="0";city="0";address="0";state="0";zip="0";phone="0";}   // default constructor
        PersonData(string a,string b,string c,string d,string e,string f,string g){lastName=a;firstName=b;city=c;address=d;state=e;zip=f;phone=g;}
        void setFirstName(string a){firstName=a;}    //  accessor set First Name
        void setLastName(string a){lastName=a;}     // accessor set Last Name
        void setAddress(string a){address=a;}    // accessor set Address
        void setState(string a){state=a;}
        void setZip(string a){zip=a;}
        void setCity(string a){city=a;}
        void setPhone(string a){phone=a;} // accessor set Phone
        virtual void PrintRecord(){ // Return the Member Variables
            cout << lastName << ", " << firstName << endl << address << endl << city << ", " << state << " " << zip << endl << phone << endl;
        }
        virtual string getRecord(){ // Map the member variables to a string for return
            strm = firstName + ", " + lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone;
            return strm;
        }
        virtual void asking();  // Function that will be used by all to get the basic variables for all the classes.
};
#endif