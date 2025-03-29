// Travis Bailey
// Project 1 Problem 2 Course Header
// 3/13/23

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

class Course 
{
private:
    int code;
    string name;
    float* testsScores;

public:
    // Default Constructor
    Course();

    // Constructor
    Course(int c, string n, float* ts);

    // Copy Constructor
    Course(const Course& other);

    // Overloading = operator
    Course& operator=(const Course& other);

    // setters and getters for each member variable
    void setCode(int c);
    int getCode();
    void setName(string n);
    string getName();
    void setTestsScores(float* ts);
    float* getTestsScores();

    // Overloading << operator as a friend function
    friend ostream& operator<<(ostream& os, const Course& c);

    // Destructor
    ~Course();
};

class Student 
{
private:
    int id;
    string name;
    Course* courses;
    int numCourses;

public:
    // Default Constructor
    Student();

    // Constructor
    Student(int id, string name);

    // Copy Constructor
    Student(const Student& other);

    // Overloading = operator
    Student& operator=(const Student& other);

    // setters and getters for each member variable
    void setId(int id);
    int getId();
    void setName(string name);
    string getName();

    // addCourse function
    void addCourse(Course c);

    // deleteCourse function
    void deleteCourse(Course c);

    // Overloading << operator as a friend function
    friend ostream& operator<<(ostream& os, const Student& s);

    // Destructor
    ~Student();
};
#endif