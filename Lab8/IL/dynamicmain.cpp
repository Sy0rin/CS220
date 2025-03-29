#include <iostream>
#include "DynamicStack.h"

using namespace std;

int main()
{
    DynamicStack<int> myStack;

    // Push values onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    // Pop and display the values
    int value;
    while (!myStack.isEmpty())
    {
        myStack.pop(value);
        cout << value << endl;
    }

    return 0;
}