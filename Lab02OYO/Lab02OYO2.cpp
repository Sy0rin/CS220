// This is Lab02 On Your Own Problem 2
// Travis Bailey
// Last updated on 2/13/2023

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
    int a = 0;
    int wins = 0;
    string read;
    vector<string> winnerline;
    string input;
    ifstream winnerfile("WorldSeriesWinners.txt");
    ifstream teamfile("Teams.txt");
    while (!teamfile.eof())
    {
       getline(teamfile,read);
       cout << read << endl;
    }
    while (!winnerfile.eof())
    {
       getline(winnerfile,read);
       winnerline.push_back(read);
    }
    cout << "Please input the name of a team" << endl;
    getline(cin, input);
    for (int i=0;i<108;i++)
    {
        if (input == winnerline[i]){
        wins+=1;
        }
    }
    cout << "This team has won: " << wins << endl;
}