#ifndef MINIDLISTQUEUE_H
#define MINIDLISTQUEUE_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;

template <class DataType>
 class miniDListQueue {
    private:
miniDList<DataType> list;


 public:
miniDListQueue ();	// Constructor 
miniDListQueue(const miniDListQueue<DataType> &); // Copy Constructor
~miniDListQueue();	//   Destructor
int   size()   const;	// get the number of elements in the queue
bool isEmpty() const;	// Check if the queue is empty
void  enqueue(const  DataType& e);		// Enqueue element at rear
void  dequeue() ; //throw(QueueEmpty);	// dequeue element at front 
const DataType& front() const; //throw(QueueEmpty); //return the front element but not remove
void  printQueue()  const;	// Prints the queue from the front to the rear
 miniDListQueue<DataType>& operator=(const miniDListQueue<DataType>&); // Assignment operator
};

//implementations go below...

// Constructor
template <class DataType>
miniDListQueue<DataType>::miniDListQueue() {}

// Copy Constructor
template <class DataType>
miniDListQueue<DataType>::miniDListQueue(const miniDListQueue<DataType> &queue) : list(queue.list) {}

// Destructor
template <class DataType>
miniDListQueue<DataType>::~miniDListQueue() {}

// get the number of elements in the queue
template <class DataType>
int miniDListQueue<DataType>::size() const {
    return list.size();
}

// Check if the queue is empty
template <class DataType>
bool miniDListQueue<DataType>::isEmpty() const {
    if (list.size()==0){
        return true;
    }
    return false;
}

// Enqueue element at rear
template <class DataType>
void miniDListQueue<DataType>::enqueue(const DataType& e) {
    list.addBack(e);
}

// dequeue element at front 
template <class DataType>
void miniDListQueue<DataType>::dequeue() {
    if (isEmpty()) {
        throw QueueEmpty("Queue is Empty");
    }
    list.removeFront();
}

// return the front element but not remove
template <class DataType>
const DataType& miniDListQueue<DataType>::front() const {
    if (isEmpty()) {
        throw QueueEmpty("Queue is Empty");
    }
    return list.front();
}

// Prints the queue from the front to the rear
template <class DataType>
void miniDListQueue<DataType>::printQueue() const {
    list.display();
}

// Assignment operator
template <class DataType>
miniDListQueue<DataType>& miniDListQueue<DataType>::operator=(const miniDListQueue<DataType>& queue) {
    if (this == &queue) {
        return *this;
    }
    list = queue.list;
    return *this;
}

#endif
