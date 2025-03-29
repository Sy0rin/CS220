// This is Lab02 On Your Own Problem 1
// Travis Bailey
// Last updated on 2/13/2023

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
    int a = 0;
    int wins = 0;
    string teamline;
    string readline[108];
    string input;
    ifstream winnerfile("WorldSeriesWinners.txt");
    ifstream teamfile("Teams.txt");
    while (!teamfile.eof())
    {
       getline(teamfile,teamline);
       cout << teamline << endl;
    }
    while (!winnerfile.eof())
    {
       getline(winnerfile,readline[a]);
       a++;
    }
    cout << "Please input the name of a team" << endl;
    getline(cin, input);
    for (int i=0;i<108;i++)
    {
        if (input == readline[i]){
        wins+=1;
        }
    }
    cout << "This team has won: " << wins << endl;
}