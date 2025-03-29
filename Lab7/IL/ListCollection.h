#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H#include <iostream>
#include <cstdlib>using namespace std;template<class T>
class ListCollection {   private:   class ListNode {
public:
T value;
ListNode *next;ListNode(T nodeValue) {
value = nodeValue;
next = nullptr;
}
};
ListNode *head = nullptr;bool isValid(int);
public:
ListCollection(int sz = 10);
ListCollection();
void setElement(int, T);
T getElement(int);
void displayList(bool nl = false) const;
ListCollection(const ListCollection &obj);
const ListCollection<T> operator=(const ListCollection &right);const ListCollection<T> operator+(const ListCollection &right);
const ListCollection<T> sublist(int, int);
const ListCollection<T> sublist(int);
const ListCollection<T> sort();
void clear();
int size();
int capacity();
void pushFront(T);
void pushBack(T);
T popFront();T popBack();
void insertOrdred(T);
void removeElement(T);
void insert(int, T);
void remove(int);
};template<class T>
ListCollection<T>::ListCollection(int sz) {
head = nullptr;
}
template<class T>
ListCollection<T>:: ̃ListCollection() {
ListNode *nodePtr = head;
ListNode *nextNode;while (nodePtr != nullptr) {
nextNode = nodePtr->next;
delete nodePtr;
nodePtr = nextNode;
}
}template<class T>
ListCollection<T>::ListCollection(const ListCollection &obj) {
ListNode *nodePtr = obj.head;
while (nodePtr) {
pushBack(nodePtr->value);
nodePtr = nodePtr->next;
}
}
template<class T>
const ListCollection<T> ListCollection<T>::operator=(
const ListCollection &right) {
clear();
ListNode *nodePtr = right.head;
while (nodePtr) {
pushBack(nodePtr->value);
nodePtr = nodePtr->next;
}return *this;
}template<class T>
bool ListCollection<T>::isValid(int index) {
int sz = size();
return (index >= 0 && index < sz);
}template<class T>
void ListCollection<T>::setElement(int index, T value) {
if (isValid(index)) {
ListNode *nodePtr = head;
for (int i = 0; i < index; i++)
nodePtr = nodePtr->next;
nodePtr->value = value;
}
}template<class T>
T ListCollection<T>::getElement(int pos) {
T defaultret;
int sz = size();if (sz == 0)
return defaultret;if (pos < 0)
return head->value;if (pos >= sz)
pos = sz - 1;ListNode *nodePtr = head;
for (int i = 0; i < pos; i++)
nodePtr = nodePtr->next;
return nodePtr->value;
}template<class T>
void ListCollection<T>::displayList(bool nl) const {
ListNode *nodePtr = head;
while (nodePtr) {
cout << nodePtr->value << " ";
if (nl)
cout << endl;nodePtr = nodePtr->next;
}
if (!nl)
cout << endl;
}template<class T>
const ListCollection<T> ListCollection<T>::operator+(
const ListCollection &right) {
ListCollection<T> newList;
ListNode *nodePtr = head;
while (nodePtr) {
newList.pushBack(nodePtr->value);
nodePtr = nodePtr->next;
}*nodePtr = right.head;
while (nodePtr) {
newList.pushBack(nodePtr->value);
nodePtr = nodePtr->next;
} 
return newList;} 
template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b, int e) 
{
    int sz = size(); 
    if (b > e) {
        int temp = b;
        b = e;
        e = temp;
        } 
    if (b < 0)
        b = 0; 
    if (e < 0)
        e = 0; 
    if (b >= sz)
        b = sz - 1;
    if (e >= sz)
        e = sz - 1; 
    ListCollection<T> newList; 
    ListNode *nodePtr = head;
    for (int i = 0; i < b; i++)
        nodePtr = nodePtr->next; 
    for (int i = 0; i < e - b + 1; i++) {
        newList.pushBack(nodePtr->value);
        nodePtr = nodePtr->next;
        } 
        return newList;
    } 
template<class T>
const ListCollection<T> ListCollection<T>::sublist(int b) {
    return sublist(b, size() - 1);} 
template<class T>
const ListCollection<T> ListCollection<T>::sort() {
    ListCollection<T> newList;
    ListNode *nodePtr = head;
    while (nodePtr) {
        newList.insertOrdred(nodePtr->value);
        nodePtr = nodePtr->next;
        } 
    return newList;
    } 
    
template<class T>int ListCollection<T>::size() {
    int count = 0;
    ListNode *nodePtr = head;
    while (nodePtr) {
        count++;nodePtr = nodePtr->next;
        } 
    return count;}
    
template<class T>
int ListCollection<T>::capacity() {
    return size();} 
    
template<class T>
void ListCollection<T>::pushFront(T elt) {ListNode *newNode = new ListNode(elt); if (!head)head = newNode;else {newNode->next = head;head = newNode;}} template<class T>void ListCollection<T>::pushBack(T elt) {ListNode *newNode = new ListNode(elt); if (!head)head = newNode;
8
COSC  Lab #7: Linked Lists— Solutions Fall 2else {ListNode *nodePtr = head;ListNode *previousNode = nullptr; while (nodePtr) {previousNode = nodePtr;nodePtr = nodePtr->next;}previousNode->next = newNode;}} template<class T>T ListCollection<T>::popFront() {T defaultret; if (!head)return defaultret; T retval = head->value; ListNode *nodePtr = head;head = nodePtr->next;delete nodePtr; return retval;} template<class T>T ListCollection<T>::popBack() {T defaultret; if (!head)return defaultret; ListNode *nodePtr = head;ListNode *previousNode = nullptr; while (nodePtr->next) {previousNode = nodePtr;nodePtr = nodePtr->next;} T retval = nodePtr->value; if (previousNode)previousNode->next = nullptr;elsehead = nullptr; delete nodePtr; return retval;} template<class T>void ListCollection<T>::insertOrdred(T elt) {ListNode *nodePtr = head;ListNode *previousNode = nullptr;ListNode *newNode = new ListNode(elt); if (!head)head = newNode;else {while (nodePtr && nodePtr->value < elt) {previousNode = nodePtr;nodePtr = nodePtr->next;}
newNode->next = nodePtr;
if (!previousNode) {head = newNode;} else {previousNode->next = newNode;}}} template<class T>void ListCollection<T>::removeElement(T elt) {ListNode *nodePtr = head;ListNode *previousNode = nullptr; while (nodePtr && nodePtr->value != elt) {previousNode = nodePtr;nodePtr = nodePtr->next;} if (!nodePtr)return;else if (!previousNode) {head = nodePtr->next;delete nodePtr;} else {previousNode->next = nodePtr->next;delete nodePtr;}} template<class T>void ListCollection<T>::insert(int pos, T elt) {int sz = size(); if (pos >= sz)pushBack(elt);else if (pos <= 0)pushFront(elt);else {ListNode *nodePtr = head;ListNode *previousNode = nullptr;ListNode *newNode = new ListNode(elt); for (int i = 0; i < pos; i++) {previousNode = nodePtr;nodePtr = nodePtr->next;} previousNode->next = newNode;newNode->next = nodePtr;}} template<class T>void ListCollection<T>::remove(int pos) {if (!isValid(pos))return; ListNode *nodePtr = head;ListNode *previousNode = nullptr; for (int i = 0; i < pos; i++) {previousNode = nodePtr;nodePtr = nodePtr->next;} previousNode->next = nodePtr->next;delete nodePtr;} template<class T>void ListCollection<T>::clear() {ListNode *nodePtr = head;ListNode *nextNode; while (nodePtr != nullptr) {nextNode = nodePtr->next;delete nodePtr;nodePtr = nextNode;}   head = nullptr;
}
#endif