#ifndef STATICSTACK_H
#define STATICSTACK_H
#include <iostream>
using namespace std;

template <class T>
class Stack
{
    private:
        T *ArStack;
        int stackSize;
        int top;
    public:
        Stack(int);
        Stack(const Stack&);
        ~Stack();

        void push(T);
        void pop(T &);
        bool isFull();
        bool isEmpty();
};

template <class T>
Stack<T>::Stack(int size){
    ArStack = new T[size];
    stackSize = size;
    top = -1;
}

template <class T>
Stack<T>::Stack(const Stack &obj){
    if (obj.stackSize>0) ArStack = new T[obj.stackSize];
    else ArStack = nullptr;
    for (int i=0;i<stackSize;i++) ArStack[i]=obj.ArStack[i];
    top = obj.top;
}

template <class T>
Stack<T>::~Stack(){
    if (stackSize>0)
        delete [] ArStack;
}

template <class T>
void Stack<T>::push(T item){
    if (isFull()) cout << "The Stack is full." << endl;
    else{
        top++;
        ArStack[top]=item;
    }
}

template <class T>
void Stack<T>::pop(T &item){
    if (isEmpty()) cout << "The Stack is empty." << endl;
    else{
        item = ArStack[top];
        top--;
    }
}

template <class T>
bool Stack<T>::isFull(){
    bool status;
    if (top==stackSize-1) status = true;
    else status = false;
    return status;
}

template <class T>
bool Stack<T>::isEmpty(){
    bool status;
    if (top==-1) status = true;
    else status = false;
    return status;
}

#endif