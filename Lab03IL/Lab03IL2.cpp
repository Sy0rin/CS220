// Travis Bailey   
// Problem 2 Coin code Lab 3
// Last updated on 2/14/23

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// Global Variables for the counter for main and Class use
int heads=0;
int tails=0;

class Coin
{
    public:
    // Constructor to initialize starting values.
        Coin()
        {
            toss();
            getSideUp();
        }
    // Toss function to generate the random number (even or odd)
        void toss(){
            flip = rand() % 2 + 1;
        }
    // SideUp function to interpret even or odd in terms of heads or tails.
        string getSideUp(){
            // If odd then heads
            if (flip == 1)
                { sideUp = "heads";
            }
            // If even then tails
            else
                {sideUp = "tails";
                }
            return sideUp;
            }
    // Counter function to keep track of toss results
        void tosscount(){
            if (sideUp == "heads"){
                heads++;
            }
            else{
                tails++;
            }
        }

    private:
    // Declare Random number and output of class function
        string sideUp;
        int flip;


};

int main()
{
    // Correct random number generation for the rand() function
    srand(time(0));
    // Create the object with starting values
    Coin f1;
    // Output the start of the flip "doesn't count for the toss"
    cout << "The Coin is currently: " << f1.getSideUp() << endl;
    // Toss coin 20 times
    for (int i = 0; i<20;i++)
    {
        // Toss the coin
        f1.toss();
        // Use the sideup to interpret the toss in head or tails
        cout << f1.getSideUp() << endl;
        // Count the results of the prior
        f1.tosscount();
    }
    // Output the counter variables in heads or tails terms.
    cout << "Total Heads: " << heads << endl;
    cout << "Total Tails: " << tails << endl;

}