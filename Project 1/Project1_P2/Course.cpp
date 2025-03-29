// Travis Bailey
// Project 1 Problem 2 Definitions
// 3/13/23

#include "Course.h"
// Default Constructor for Course
Course::Course(){
    code = 120;
    name = "CS1";
    testsScores = new float[3]{0.0, 0.0, 0.0};
}

// Constructor for Course
Course::Course(int c, string n, float* ts){
    code = c;
    name = n;
    testsScores = new float[3];
    for (int i = 0; i < 3; i++){
        testsScores[i] = ts[i];
    }
}

// Copy Constructor for Course
Course::Course(const Course& other){
    code = other.code;
    name = other.name;
    testsScores = new float[3];
    for (int i = 0; i < 3; i++){
        testsScores[i] = other.testsScores[i];
    }
}

// Overloading = operator for Course
Course& Course::operator=(const Course& other){
    if (this != &other){
        code = other.code;
        name = other.name;
        delete[] testsScores;
        testsScores = new float[3];
        for (int i = 0; i < 3; i++){
            testsScores[i] = other.testsScores[i];
        }
    }
    return *this;
}

// setters and getters for Course
void Course::setCode(int c){
    code = c;
}
int Course::getCode(){
    return code;
}
void Course::setName(string n){
    name = n;
}
string Course::getName(){
    return name;
}
void Course::setTestsScores(float* ts){
    for (int i = 0; i < 3; i++){
        testsScores[i] = ts[i];
    }
}
float* Course::getTestsScores(){
    return testsScores;
}

// Overloading << operator for Course
ostream& operator<<(ostream& os, const Course& c){
    os << "Code: " << c.code << ", Name: " << c.name << ", Test Scores: [";
    for (int i = 0; i < 2; i++){
        os << c.testsScores[i] << ", ";
    }
    os << c.testsScores[2] << "]";
    return os;
}

// Destructor for Course
Course::~Course(){
    delete[] testsScores;
}

// Default Constructor for Student
Student::Student(){
    id = 0;
    name = "";
    courses = nullptr;
    numCourses = 0;
}

// Constructor for Student
Student::Student(int i, string n){
    id = i;
    name = n;
    courses = new Course[1];
    numCourses = 0;
}

// Copy Constructor for Student
Student::Student(const Student& other){
    id = other.id;
    name = other.name;
    courses = new Course[other.numCourses];
    numCourses = other.numCourses;
    for (int i = 0; i < numCourses; i++){
        courses[i] = other.courses[i];
    }
}

// Setter and Getters
void Student::setId(int id){
    id = id;
}
int Student::getId(){
    return id;
}
void Student::setName(string name){
    name = name;
}
string Student::getName(){
    return name;
}
// Overloading = operator for Student
Student& Student::operator=(const Student& other){
    if (this != &other){
        id = other.id;
        name = other.name;
        delete[] courses;
        courses = new Course[other.numCourses];
        numCourses = other.numCourses;
        for (int i = 0; i < numCourses; i++){
            courses[i] = other.courses[i];
        }
    }
    return *this;
}

// Overloading << operator for Student
ostream& operator<<(ostream& os, const Student& s){
    os << "ID: " << s.id << ", Name: " << s.name << ", Courses: [";
    for (int i = 0; i < s.numCourses; i++){
        os << s.courses[i] << " ";
    }
    os << "]";
    return os;
}

//  Add Course Function
void Student::addCourse(Course c){
    Course* newCourses = new Course[numCourses + 1];
    for (int i = 0; i < numCourses; i++){
        newCourses[i] = courses[i];
    }
    newCourses[numCourses] = c;
    numCourses++;
    delete[] courses;
    courses = newCourses;
}

//  Delete Course Function
void Student::deleteCourse(Course c){
    int index = -1;
    for (int i = 0; i < numCourses; i++){
        if ((courses[i].getCode() == c.getCode())&&(courses[i].getName() == c.getName())){
            index = i;
            break;
        }
    }
    if (index != -1){
        Course* newCourses = new Course[numCourses - 1];
        for (int i = 0; i < index; i++){
            newCourses[i] = courses[i];
        }
        for (int i = index + 1; i < numCourses; i++){
            newCourses[i - 1] = courses[i];
        }
        numCourses--;
        delete[] courses;
        courses = newCourses;
    }
}

Student::~Student(){
    delete[] courses;
}