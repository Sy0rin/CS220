#include <iostream>
#include "StaticStack.h"
using namespace std;

int main()
{
    // create a stack of integers with size 5
    Stack<int> myStack(5);

    // push some items onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // pop an item from the stack
    int item;
    myStack.pop(item);
    cout << "Popped item: " << item << endl;

    // push more items onto the stack
    myStack.push(40);
    myStack.push(50);

    // try to push an item onto a full stack
    myStack.push(60);

    // pop all items from the stack
    while (!myStack.isEmpty())
    {
        myStack.pop(item);
        cout << "Popped item: " << item << endl;
    }

    return 0;
}