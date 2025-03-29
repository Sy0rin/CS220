//  Travis Bailey
//  Project 1 Problem 2 Main Function
//  3/13/23

#include <iostream>
#include "Course.h"

using namespace std;

int main() {
    // Initialized variables for name and id for user input
    string name;
    int id;
    //  Function declarations are easier with array so we will recycle this through all classes.
    float ts[] = { 80.0, 90.0, 85.0 };
    //  Make course objects with the names of "Math and Science".
    Course c1(123, "Math", ts);
    Course c2(456, "Science", ts);
    //  User input for a name.
    cout << "Give me a name: ";
    cin >> name;
    cout << "Give me the student ID: ";
    cin >> id;
    //  Create the student object with the given information
    Student s1(id,name);
    //  Add the courses to the student object.
    s1.addCourse(c1);
    s1.addCourse(c2);
    //  Call the overloaded ostream to put out all the names of the classes in the student classes.
    cout << s1 << endl;
    //  Create the second Student object using the overloaded assignment operator.
    Student s2 = s1;
    //  Output the second student object
    cout << s2 << endl;
    //  Deleting the first course within the array.
    s2.deleteCourse(c1);
    //  Creating the 3rd student class using the copy constructor
    Student s3(s2);
    //  Outputing the 3rd student class after it has been copied from the 2nd student object after the .deleteCourse() function.
    cout << s3 << endl;
}