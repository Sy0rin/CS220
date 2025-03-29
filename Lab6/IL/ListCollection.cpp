#include "ListCollection.h"

using namespace std;

//  Constructor based on size
ListCollection::ListCollection(int size)
{
    list = new int[size];
    numCapacity = size;
    numElements = 0;
}

//  Delete List, deallocate memory
ListCollection::~ListCollection()
{
    delete [] list;
}

//  List copy constructor
ListCollection::ListCollection(const ListCollection &obj)
{
    numCapacity = obj.numCapacity;
    for (int i = 0; i < numCapacity; i++)
        list[i] = obj.list[i];
}

//  Update size of the capacity of the array when total capacity is reached
void ListCollection::update(){
    if (numElements >= numCapacity) numCapacity=numCapacity*2;
    resize(numCapacity);
}

//  Overloading copy by assignment operator
const ListCollection ListCollection::operator=(const  ListCollection &right)
{
    delete [] list;
    numCapacity = right.numCapacity;
    numElements = right.numElements;
    list = new int[numCapacity];
    for (int i = 0; i < numCapacity; i++)
        list[i] = right.list[i];

    return *this;
}

//  Overloading concating array operator
const ListCollection ListCollection::operator+(const ListCollection &right)
{
    int* temp = new int[numCapacity+right.numCapacity];
    for (int i = 0; i < numCapacity; ++i) temp[i] = list[i];
    for (int j = 0; j < right.numCapacity; ++j) temp[j+numCapacity] = right.list[j];
    return *temp;
}

//  Resize function to remake list with updated capacity
void ListCollection::resize(int sz)
{
    int* temp = new int[sz];
    for (int i = 0; i < numCapacity; ++i) temp[i] = 0;
    for (int i = 0; i < numCapacity; ++i) temp[i] = list[i];
    delete [] list;
    numCapacity = sz;
    list = temp;

}

//  Checks whether or not the element is in the array
bool ListCollection::isValid(int element) const
{
    bool status;

    if (element < 0 || element >= numElements)
        status = false;
    else
        status = true;
    return status;
}

//  Sets the element for the value
void ListCollection::setElement(int element, int value)
{
    if (isValid(element))
        list[element] = value;
}

//  Rturns the position of the index.
int ListCollection::getElement(int element) const
{
    if (isValid(element))
        return list[element];
    else if (element < 0)
    {
        return list[0];
    }
    else
    {
        return list[numElements-1];
    }
}

//  Display the list
void ListCollection::displayList(bool a) const
{
    if (a){
        for (int i = 0; i < numElements; ++i){
            cout << list[i];
            cout << endl;
        }
    }
    else{
        for (int i = 0; i < numElements; ++i){
            cout << list[i] << " ";
        }
    }
    cout << endl;
}

//  Returns the number of elements in the array or the size.
int ListCollection::size(){
    return numElements;
}

//  Returns the capacity of the array
int ListCollection::capacity(){
    return numCapacity;
}

//  appends a value to the end of the array
void ListCollection::pushBack(int a){
    update();
    list[numElements]=a;
    numElements++;
}

//  Appends a value to the front of the array
void ListCollection::pushFront(int a){
    int* temp = new int[numCapacity];
    for (int i = 0; i < numElements; ++i) temp[i+1] = list[i];
    numElements++;
    update();
    temp[0]=a;
    delete[] list;
    list = temp;
}

//  Returns and removes the last element of the array
int ListCollection::popBack(){
    int retval = list[numElements+1];
    int* temp = new int[numCapacity];
    for (int i = 0; i < numElements-1; ++i) temp[i] = list[i];
    numElements--;
    delete [] list;
    list = temp;
    return retval;
}

//  Returns and removes the first element of the array
int ListCollection::popFront(){
    int retval=list[0];
    int* temp = new int[numCapacity];
    for (int i = 1; i < numElements; ++i) temp[i-1] = list[i];
    numElements--;
    delete [] list;
    list = temp;
    return retval;
}

