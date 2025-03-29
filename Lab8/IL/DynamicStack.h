#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>
using namespace std;

template <class T>
class DynamicStack
{
    private:
    struct StackNode
    {
        T value;
        StackNode *next;
    };
    StackNode *top;
    public:
    DynamicStack(){top=nullptr;}
    ~DynamicStack();

    void push(T);
    void pop(T &);
    bool isEmpty();
};

template<class T>
DynamicStack<T>::~DynamicStack(){
    StackNode *nodePtr, *nextNode;
    nodePtr=top;
    while(nodePtr != nullptr){
        nextNode=nodePtr->next;
        delete nodePtr;
        nodePtr=nextNode;
    }
}

template<class T>
void DynamicStack<T>::push(T item){
    StackNode *newNode = nullptr;

    newNode = new StackNode;
    newNode->value = item;

    if(isEmpty()){
        top = newNode;
        newNode->next=nullptr;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
}

template<class T>
void DynamicStack<T>::pop(T &item){
    StackNode *temp = nullptr;
    if (isEmpty()) cout << "The Stack is Empty." << endl;
    else{
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

template<class T>
bool DynamicStack<T>::isEmpty(){
    bool status;
    if (!top) status = true;
    else status = false;
    return status;
}

#endif