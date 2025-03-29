#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class ListCollection {
    private:
        T *list; // Pointer to the array.
        int numElements; // Number of elements.
        int numCapacity; // Maximum number of elements.
        bool isValid(int) const; // Validates subscripts.
        void resize(int); // Resizes list, moved to private.
    public:
        ListCollection(int sz = 10); // Constructor
        ~ListCollection(); // Destructor
        void setElement(T, int); // Sets an element to a value
        T getElement(int) const; // Returns an element
        void displayList(bool nl = false) const; // Display list

        ListCollection(const ListCollection &obj);
        const ListCollection operator=(const ListCollection &right);

        // Updated functions
        const ListCollection operator+(const ListCollection &right);

        // New functions
        int size();
        int capacity();
        void pushBack(T);
        void pushFront(T);
        T popBack();
        T popFront();
        void update();
};

//  Constructor based on size
template<class T>
ListCollection<T>::ListCollection(int size)
{
    list = new T[size];
    numCapacity = size;
    numElements = 0;
}

//  Delete List, deallocate memory
template<class T>
ListCollection<T>::~ListCollection()
{
    delete [] list;
}

//  List copy constructor
template<class T>
ListCollection<T>::ListCollection(const ListCollection &obj)
{
    numCapacity = obj.numCapacity;
    for (int i = 0; i < numCapacity; i++)
        list[i] = obj.list[i];
}

//  Update size of the capacity of the array when total capacity is reached
template<class T>
void ListCollection<T>::update(){
    if (numElements >= numCapacity) numCapacity=numCapacity*2;
    resize(numCapacity);
}

//  Overloading copy by assignment operator
template<class T>
const ListCollection<T> ListCollection<T>::operator=(const  ListCollection &right)
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
template <class T>
const ListCollection<T> ListCollection<T>::operator+(const ListCollection &right)
{
    int* temp = new int[numCapacity+right.numCapacity];
    for (int i = 0; i < numCapacity; ++i) temp[i] = list[i];
    for (int j = 0; j < right.numCapacity; ++j) temp[j+numCapacity] = right.list[j];
    return *temp;
}

//  Resize function to remake list with updated capacity
template<class T>
void ListCollection<T>::resize(int sz)
{
    T* temp = new T[sz];
    for (int i = 0; i < numCapacity; ++i) temp[i] = 0;
    for (int i = 0; i < numCapacity; ++i) temp[i] = list[i];
    delete [] list;
    numCapacity = sz;
    list = temp;

}

//  Checks whether or not the element is in the array
template<class T>
bool ListCollection<T>::isValid(int element) const
{
    bool status;

    if (element < 0 || element >= numElements)
        status = false;
    else
        status = true;
    return status;
}

//  Sets the element for the value
template<class T>
void ListCollection<T>::setElement(T value,int element)
{
    if (isValid(element))
        list[element] = value;
}

//  Rturns the position of the index.
template<class T>
T ListCollection<T>::getElement(int element) const
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
template<class T>
void ListCollection<T>::displayList(bool a) const
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
template<class T>
int ListCollection<T>::size(){
    return numElements;
}

//  Returns the capacity of the array
template<class T>
int ListCollection<T>::capacity(){
    return numCapacity;
}

//  appends a value to the end of the array
template<class T>
void ListCollection<T>::pushBack(T a){
    update();
    list[numElements]=a;
    numElements++;
}

//  Appends a value to the front of the array
template<class T>
void ListCollection<T>::pushFront(T a){
    T* temp = new T[numCapacity];
    for (int i = 0; i < numElements; ++i) temp[i+1] = list[i];
    numElements++;
    update();
    temp[0]=a;
    delete[] list;
    list = temp;
}

//  Returns and removes the last element of the array
template<class T>
T ListCollection<T>::popBack(){
    T retval = list[numElements+1];
    T* temp = new T[numCapacity];
    for (int i = 0; i < numElements-1; ++i) temp[i] = list[i];
    numElements--;
    delete [] list;
    list = temp;
    return retval;
}

//  Returns and removes the first element of the array
template<class T>
T ListCollection<T>::popFront(){
    T retval=list[0];
    T* temp = new T[numCapacity];
    for (int i = 1; i < numElements; ++i) temp[i-1] = list[i];
    numElements--;
    delete [] list;
    list = temp;
    return retval;
}


#endif