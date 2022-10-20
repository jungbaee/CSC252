#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cmath>

//Circle class from the docx file
class Circle
{
    private :
       double radius;

    public :
       inline Circle() { radius = 1; }
       inline Circle( double r ) { radius = r ; }
       inline void setRadius( double r ) { radius = r ; }
       inline double getRadius() const { return radius; }
       inline double area() const { return 3.14 * pow(radius, 2.0); }
       inline void print() const
       {
              std::cout << "Radius = " << radius << "  area = " << area() << std::endl;
       }
};

class Shape {
    private:
        Circle* circles;
        int numberOfCircles;
        int capacity;

    public:
        Shape (int capacity);
        ~Shape();
        void addCricle(Circle c);
        Circle* getCircles() const;
        int getNumberOfCircles() const;
        Shape (const Shape &RHS);
        void print() const;
};

#endif