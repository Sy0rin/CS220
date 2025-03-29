// Travis Bailey
// Project 1
// 3/13/23
#include "PersonData.h"
#include "CustomerData.h"

using namespace std;

const int MAX_ENTRIES = 10;
int main() {
    // Initialize database
    PersonData* database[MAX_ENTRIES];
    int databaseSize = 0;

    // Display menu and process user input
    int choice=0;
    int i=0;

    do {
        cout << endl
             << "1. Add Personal Data Object\n"
             << "2. Add Customer Data Object\n"
             << "3. Add Preferred Customer Data Object\n"
             << "4. View Database Long Form\n"
             << "5. View Database Short Form\n"
             << "6. Quit\n"
             << "Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                database[i] = new PersonData();
                // Add PersonalData object
                database[i]->asking();
                databaseSize++;
                i++;
                break;
            }
            case 2: {
                database[i] = new CustomerData();
                database[i]->asking();
                // Add CustomerData object
                databaseSize++;
                i++;
                break;
            }
            case 3: {
                database[i] = new PreferredCustomer();
                database[i]->asking();
                // Add PreferredCustomer object
                databaseSize++;
                i++;
                break;
            }
            case 4: {
                for (int j=0;j<databaseSize;j++)
                {
                    // Reading out object PrintRecords
                    database[j]->PrintRecord();
                    cout << endl;
                }
                break;
            }
            case 5: {
                for (int j=0;j<databaseSize;j++)
                {
                    // Reading out the GetRecord for the objects
                    cout << database[j]->getRecord();
                    cout << endl;
                }
                break;
            }
            case 6: {
                //  Exiting the Do-While Loop
                databaseSize = 10;
            }
        }
    } while (databaseSize<10); //  Maximum of 10 values.
}