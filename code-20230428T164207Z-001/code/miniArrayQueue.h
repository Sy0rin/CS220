#ifndef MINIARRAYQUEUE_H
#define MINIARRAYQUEUE_H
#include <iostream>     // For cout
#include "RuntimeException.h"
using namespace std;
//use modular arithmetic "%" to save array space, like in-class code example
template <class DataType>
 class miniArrayQueue {
    private:
    enum {DEF_CAPACITY =100}; 	//default queue capacity
DataType* arr;		// The array of items
int	capacity;	// The capacity of the current array
int	front;	// The location of the front element
int	rear;	// The location of the rear element
int queueSize;  //number of elements in queue

 public:
miniArrayQueue (int cap=DEF_CAPACITY );	// Constructor 
miniArrayQueue(const miniArrayQueue<DataType> &); // Copy Constructor
~miniArrayQueue();	//   Destructor
int   size()   const;	// get the number of elements in the queue
bool isEmpty() const;	// Check if the queue is empty
void  enqueue(const  DataType& e); //throw(QueueFull), Enqueue element at rear
void  dequeue();     //throw(QueueEmpty), dequeue element at front 
const DataType& getFront() const ;//throw(QueueEmpty), return the front element but not remove
void  printQueue()  const;	// Prints the queue from the front to the rear
 miniArrayQueue<DataType>& operator=(const miniArrayQueue<DataType>&); // Assignment operator
};


//implementations go below...
template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue(int cap) {
    capacity = cap;
    arr = new DataType[capacity];
    front = 0;
    rear = 0;
    queueSize = 0;
}

template <class DataType>
miniArrayQueue<DataType>::miniArrayQueue(const miniArrayQueue<DataType>& q) {
    capacity = q.capacity;
    arr = new DataType[capacity];
    front = q.front;
    rear = q.rear;
    queueSize = q.queueSize;
    for (int i = 0; i < capacity; i++) {
        arr[i] = q.arr[i];
    }
}

template <class DataType>
miniArrayQueue<DataType>::~miniArrayQueue() {
    delete[] arr;
}

template <class DataType>
int miniArrayQueue<DataType>::size() const {
    return queueSize;
}

template <class DataType>
bool miniArrayQueue<DataType>::isEmpty() const {
    return queueSize == 0;
}

template <class DataType>
void miniArrayQueue<DataType>::enqueue(const DataType& e) {
    if (queueSize == capacity) {
        throw out_of_range("Queue is Full");
    }
    arr[rear] = e;
    rear = (rear + 1) % capacity;
    queueSize++;
}

template <class DataType>
void miniArrayQueue<DataType>::dequeue() {
    if (isEmpty()) {
        throw out_of_range("Queue is Empty");
    }
    front = (front + 1) % capacity;
    queueSize--;
}

template <class DataType>
const DataType& miniArrayQueue<DataType>::getFront() const {
    if (isEmpty()) {
        throw out_of_range("Queue is Empty");
    }
    return arr[front];
}

template <class DataType>
void miniArrayQueue<DataType>::printQueue() const {
    cout << "Queue: ";
    int i = front;
    while (i != rear) {
        cout << arr[i] << " ";
        i = (i + 1) % capacity;
    }
    cout << endl;
}

template <class DataType>
miniArrayQueue<DataType>& miniArrayQueue<DataType>::operator=(const miniArrayQueue<DataType>& q) {
    if (this == &q) {
        return *this;
    }
    capacity = q.capacity;
    delete[] arr;
    arr = new DataType[capacity];
    front = q.front;
    rear = q.rear;
    queueSize = q.queueSize;
    for (int i = 0; i < capacity; i++) {
        arr[i] = q.arr[i];
    }
    return *this;
}

#endif
