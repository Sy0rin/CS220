#ifndef MINIARRAYSTACK_H
#define MINIARRAYSTACK_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;


template <class DataType>
 class miniArrayStack{
private:
enum {DEF_CAPACITY =100}; 	//default stack capacity
DataType* arr;	// The array of items
int	capacity;	// The capacity of the current array
int	top;	// The location of the top element
int stackSize;  //number of elements in stack
 

 public:
 miniArrayStack (int cap= DEF_CAPACITY);	// Constructor for ArrStack
miniArrayStack(const miniArrayStack<DataType> &); 	// Copy contstructor
~miniArrayStack();	// Destructor
int  size()  const;	// get the number of elements in the stack
 bool isEmpty() const;	// Check if the stack is empty
const DataType& getTop() const; //throw(StackEmpty);       //get the top emement without popping it
void push(const DataType&); //throw(StackFull);	// Pushes  an  object  onto  the  stack
void pop() ;//throw(StackEmpty);	// Pop an object off the stack 
 void  printStack()  const;	// Prints the stack from the top, down
miniArrayStack<DataType>& operator=(const  miniArrayStack<DataType>&);  //  Assignment  operator
};

//implementations go below...
template <class DataType>
miniArrayStack<DataType>::miniArrayStack(int cap) {
    capacity = cap;
    top = -1;
    stackSize = 0;
    arr = new DataType[capacity];
}

template <class DataType>
miniArrayStack<DataType>::miniArrayStack(const miniArrayStack<DataType>& s) {
    capacity = s.capacity;
    top = s.top;
    stackSize = s.stackSize;
    arr = new DataType[capacity];
    for (int i = 0; i <= top; i++) {
        arr[i] = s.arr[i];
    }
}

template <class DataType>
miniArrayStack<DataType>::~miniArrayStack() {
    delete [] arr;
}

template <class DataType>
int miniArrayStack<DataType>::size() const {
    return stackSize;
}

template <class DataType>
bool miniArrayStack<DataType>::isEmpty() const {
    return stackSize == 0;
}

template <class DataType>
const DataType& miniArrayStack<DataType>::getTop() const {
    if (isEmpty()) {
        throw logic_error("Stack is empty");
    }
    return arr[top];
}

template <class DataType>
void miniArrayStack<DataType>::push(const DataType& e) {
    if (stackSize == capacity) {
        throw logic_error("Stack is full");
    }
    top++;
    arr[top] = e;
    stackSize++;
}

template <class DataType>
void miniArrayStack<DataType>::pop() {
    if (isEmpty()) {
        throw logic_error("Stack is empty");
    }
    top--;
    stackSize--;
}

template <class DataType>
void miniArrayStack<DataType>::printStack() const {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

template <class DataType>
miniArrayStack<DataType>& miniArrayStack<DataType>::operator=(const miniArrayStack<DataType>& s) {
    if (this == &s) {
        return *this;
    }
    delete [] arr;
    capacity = s.capacity;
    top = s.top;
    stackSize = s.stackSize;
    arr = new DataType[capacity];
    for (int i = 0; i <= top; i++) {
        arr[i] = s.arr[i];
    }
    return *this;
}


#endif
