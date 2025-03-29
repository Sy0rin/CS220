// Travis Bailey   
// Problem 1 Circles code Lab 3
// Last updated on 2/14/23

#include <iostream>

using namespace std;

class Circle // Because most of these functions are Inline b/c arithmatic.
{
    public:

        Circle(){radius = 0.0;}
             // Function Default Constructor
        Circle(double r) {radius = r;}
             // Initialized Constructor
        void setRadius(double r) {if (r>=0.0){radius = r;};}
             // Function sets the user input to radius
        double getRadius() {return radius;}
             // Function returns the current radius
        double getArea() {return (pi*radius*radius);}
             // Arithmatic Function to find area of the circle
        double getDiameter() {return (2*radius);}
             // Arithmatic function to find diameter of the circle
        double getCircumference() {return (2*pi*radius);}
             // Arithmatic function to find circumference
    private:
        const double pi = 3.141592653358973;
        double radius;
};


int main()
{ 
    // Create Object
    Circle c1;
    // Create user input variable to be taken as an argument
    double radi;
    // Probe user response
    cout << "Please input a radius of the circle: " << endl;
    // Map resopnse into double variable
    cin >> radi;
    // Changing radius from 0.0 to user input
    c1.setRadius(radi);
    // Calling all the functions for output
    cout << "Area: " << c1.getArea() << endl << "Diameter: " << c1.getDiameter() << endl << "Circumference: " << c1.getCircumference();
}


