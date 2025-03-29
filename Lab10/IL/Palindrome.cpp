// Travis Bailey
// Lab 10 Palindrome
// edited on Apr 25, 2023

#include <iostream>
#include <string>
using namespace std;

bool isPal(const string& str, int startIndex, int endIndex) {
    if (startIndex >= endIndex) { // Base case: when startIndex >= endIndex, the string is a palindrome
        return true;
    } else if (str[startIndex] != str[endIndex]) { // Base case: when characters at startIndex and endIndex are not same, the string is not a palindrome
        return false;
    } else {
        // Recursive case: Check characters at next indices
        return isPal(str, startIndex + 1, endIndex - 1);
    }
}

int main() {
    string str;
    cout << "Enter a string, no spaces and all lower case: ";
    cin >> str;

    int startIndex = 0;
    int endIndex = str.length() - 1;

    bool result = isPal(str, startIndex, endIndex);

    if (result) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}