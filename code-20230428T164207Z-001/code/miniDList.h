#ifndef MINIDLIST_H
#define MINIDLIST_H
#include <iostream>     // For cout
using namespace std;


template <class DataType> 
class miniDList{
private:
struct   DNode{	// doubly linked list node
  DataType   data;	//  data stored in node   
  DNode*   next;	//  next node in list   
  DNode*   prev;	//  previous node  in list
};

 DNode* header;	// list sentinels
 DNode* trailer;	
public:
miniDList(){                      // constructor
header = new DNode;
trailer  = new DNode;         //have them point to each other
header->next = trailer;
trailer->prev = header;
}	
miniDList(const   miniDList<DataType>&  l);  // Copy constructor
~miniDList();	// Destructor
const DataType& front() const;      // get front element
const DataType& back() const;       // get back element
void   removeFront();	// Remove the front 
void   removeBack();             // Remove the back 
void addFront(const DataType& e);       // Add to the front 
void addBack(const DataType& e);           // Add to the back
int   size()   const;	// Returns the number of elements in list
bool contains(const DataType& e);   // Tests for membership
void  display()  const;	// Prints the elements of list
 miniDList<DataType>& operator=(const miniDList<DataType>& l);   //Overloaded assignment

protected:                          //local utilities
void add(DNode * v, const DataType& e); //insert new node  before  v
void remove(DNode* v);     //remove node v
};

//implementations go below...

// Copy constructor
template <class DataType>
miniDList<DataType>::miniDList(const miniDList<DataType>& l) {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
    DNode* temp = l.header->next;
    while(temp != l.trailer) {
        addBack(temp->data);
        temp = temp->next;
    }
}

// Destructor
template <class DataType>
miniDList<DataType>::~miniDList() {
    while (header->next!=trailer) {
        removeFront();
    }
    delete header;
    delete trailer;
}

// get front element
template <class DataType>
const DataType& miniDList<DataType>::front() const {
    if (header->next==trailer) {
        throw out_of_range("List Empty");
    }
    return header->next->data;
}

// get back element
template <class DataType>
const DataType& miniDList<DataType>::back() const {
    if (header->next==trailer) {
        return 0;
    }
    return trailer->prev->data;
}

// Remove the front
template <class DataType>
void miniDList<DataType>::removeFront() {
    if (header->next==trailer) {
        return ;
    }
    remove(header->next);
}

// Remove the back
template <class DataType>
void miniDList<DataType>::removeBack() {
    if (header->next==trailer) {
        return ;
    }
    remove(trailer->prev);
}

// Add to the front
template <class DataType>
void miniDList<DataType>::addFront(const DataType& e) {
    add(header->next, e);
}

// Add to the back
template <class DataType>
void miniDList<DataType>::addBack(const DataType& e) {
    add(trailer, e);
}

// Returns the number of elements in list
template <class DataType>
int miniDList<DataType>::size() const {
    int count = 0;
    DNode* temp = header->next;
    while (temp != trailer) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Tests for membership
template <class DataType>
bool miniDList<DataType>::contains(const DataType& e) {
    DNode* temp = header->next;
    while (temp != trailer) {
        if (temp->data == e) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Prints the elements of list
template <class DataType>
void miniDList<DataType>::display() const {
    DNode* temp = header->next;
    while (temp != trailer) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Overloaded assignment
template <class DataType>
miniDList<DataType>& miniDList<DataType>::operator=(const miniDList<DataType>& l) {
    if (this == &l) {
        return *this;
    }
    while (header) {
        removeFront();
    }
    DNode* temp = l.header->next;
    while (temp != l.trailer) {
        addBack(temp->data);
        temp = temp->next;
    }
    return *this;
}

// local utilities
template <class DataType>
void miniDList<DataType>::add(DNode * v, const DataType& e){
DNode* u = new DNode; // create a new node
u->data = e; // set data of the new node
u->next = v; // set next pointer of new node
u->prev = v->prev; // set prev pointer of new node
v->prev->next = u; // update next pointer of the previous node
v->prev = u; // update prev pointer of v
}

template <class DataType>
void miniDList<DataType>::remove(DNode* v){
DNode* u = v->prev; // predecessor
DNode* w = v->next; // successor
u->next = w; // unlink v from the list
w->prev = u;
delete v; // delete node v
}

#endif
