#include "RectangularCube.h"
#include <iostream>
#include <random>
#include <ctime>

//Getters
inline int RectangularCube::getLength () {return l;}
inline int RectangularCube::getWidth() {return w;}
inline int RectangularCube::getHeight() {return h;}

//Setters
void RectangularCube::setLength (int length) {l = length;}
void RectangularCube::setWidth (int width) {w = width;}
void RectangularCube::setHeight (int height) {h = height;}

//Volume length*width*height
int RectangularCube::volume() {return l*w*h;}
//surface area equation
int RectangularCube::surfaceArea() {
    return 2*l*w + 2*l*h + 2*w*h;
}

//Will print out the length, width, height, volume and surface area of all objects
void printCube (RectangularCube rc) {
    std::cout << "L = " << rc.getLength() << ", ";
    std::cout << "W = " << rc.getWidth() << ", ";
    std::cout << "H = " << rc.getHeight() << ", ";
    std::cout << "V = " << rc.volume() << ", ";
    std::cout << "A = " << rc.surfaceArea() << std::endl;
}

int main() {

    //Constant for the number of objects we will create
    const int SIZE = 5;
    //Create 5 array objects
    RectangularCube rc[SIZE];

    //initializing random seed
    srand(time(NULL));

    //For loop to assign random, length, width and height
    for(int i=0; i< SIZE; i++){
        rc[i].setLength(rand()%10+1);
        rc[i].setWidth(rand()%10+1);
        rc[i].setHeight(rand()%10+1);
    }

    //Print out all 5 array objects
    for (int i = 0; i < SIZE; i++) {
        printCube(rc[i]);
    }

}