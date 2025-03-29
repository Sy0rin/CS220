#ifndef LISTCOLLECTION_H
#define LISTCOLLECTION_H
#include <iostream>
#include <cstdlib>

class ListCollection {
    private:
        int *list; // Pointer to the array.
        int numElements; // Number of elements.
        int numCapacity; // Maximum number of elements.
        bool isValid(int) const; // Validates subscripts.
        void resize(int); // Resizes list, moved to private.
    public:
        ListCollection(int sz = 10); // Constructor
        ~ListCollection(); // Destructor
        void setElement(int, int); // Sets an element to a value
        int getElement(int) const; // Returns an element
        void displayList(bool nl = false) const; // Display list

        ListCollection(const ListCollection &obj);
        const ListCollection operator=(const ListCollection &right);

        // Updated functions
        const ListCollection operator+(const ListCollection &right);

        // New functions
        int size();
        int capacity();
        void pushBack(int a);
        void pushFront(int a);
        int popBack();
        int popFront();
        void update();
};
#endif