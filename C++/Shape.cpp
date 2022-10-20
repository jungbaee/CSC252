#include "Shape.h"
#include <iostream>

/* a) Constructor of the Shape class initializing 'capacity' 
and allocating memory for the requested capacity...*/
Shape::Shape(int capacity) {
    this->capacity = capacity;
    this->circles = new Circle[capacity];
    this->numberOfCircles = 0;
}

// b) Destructor
Shape::~Shape() {
    delete [] circles;
}

// b) Copy constructor
Shape::Shape(const Shape &RHS) {
    this->capacity=RHS.capacity;
    this->circles = new Circle[capacity];
    this->numberOfCircles=RHS.numberOfCircles;
    for (int i = 0; i < numberOfCircles; i++) {
        circles[i]=RHS.circles[i];
    }


    std::cout<<"Copy constructor executing\n";
}

// c) implementing the rest of the functions
void Shape::addCricle(Circle c) {
    if (numberOfCircles < capacity) {
        this->circles[numberOfCircles++] = c;  
    }
}

Circle* Shape::getCircles() const {
    return circles;
}

int Shape::getNumberOfCircles() const {
    return numberOfCircles;
}

void Shape::print() const {
    int i = 0;
    while (i < numberOfCircles) {
        std::cout<< "Circle Object " << i+1 << std::endl;
        circles[i].print();
        std::cout<< std::endl;
        i++;
    }
    std::cout<< "-----------------------------------------" << std::endl;

}



int main () {

    //d) a. Creat a Shape object s1
    std::cout<< "Shape object s1: " << std::endl;
    Shape s1(2);
    Circle c1;
    Circle c2(2);
    s1.addCricle(c1);
    s1.addCricle(c2);
    s1.print();

    //d) b.
    std::cout<< "Shape object s2: " << std::endl;
    Shape s2(4);
    Circle c3(3);
    Circle c4(4);
    Circle c5(5);
    s2.addCricle(c3);
    s2.addCricle(c4);
    s2.addCricle(c5);
    s2.print();

    //d) c. 
    std::cout<< "Shape object s3 (copy constructor invoked): " << std::endl;
    Shape s3(s2);
    s3.print();

    //d) d.	Add a new Circle object to s2
    Circle c6(6);
    s2.addCricle(c6);

    //Print s2 and s3...compare s2 and s3
    std::cout<< "Compare s2 and s3: " << std::endl;
    std::cout<< "s2: " << std::endl;
    s2.print();
    std::cout<< "s3: " << std::endl;
    s3.print();
    std::cout<< "s3 has not changed " << std::endl;

}





