#include "RectangularCube.h"
#include <iostream>

//Constructors with definition
RectangularCube::RectangularCube(): l(1), w(1), h(1) {}
RectangularCube::RectangularCube (int length, int width, int height): l(length), w(width), h(height) { }

//at least one inline function below
inline int RectangularCube::getLength () {return l;}
inline int RectangularCube::getWidth() {return w;}
inline int RectangularCube::getHeight() {return h;}

void RectangularCube::setLength (int length) {l = length;}
void RectangularCube::setWidth (int width) {w = width;}
void RectangularCube::setHeight (int height) {h = height;}

int RectangularCube::volume() {return l*w*h;}
int RectangularCube::surfaceArea() {
    return 2*l*w + 2*l*h + 2*w*h;
}

int main() {
    //c) a. No arg object
    RectangularCube rc1;
    //invoking the contructor with the parameters
    RectangularCube rc2(2,3,5);

    //c) b.Invoke volume() and surfaceArea() functions and display value for rc1 and rc2
    //1*1*1 = 1
    std::cout << "Volume for rc1 is: " << rc1.volume() << std::endl;
    //2*1*1+2*1*1+2*1*1 = 6
    std::cout << "Surface area for rc1 is: " << rc1.surfaceArea() << std::endl;
    //2*3*5 = 30
    std::cout << "Volume for rc2 is: " << rc2.volume() << std::endl;
    //2*2*3+2*3*5+2*2*5 = 62
    std::cout << "Surface area for rc2 is: " << rc2.surfaceArea() << std::endl;

    //c) c. invoking a set function on rc2.. now 
    rc2.setLength(10);

    //c) d. invoking volume and surface area for
    //10*3*5 = 150
    std::cout << "\nVolume for rc2 after the change is: " << rc2.volume() << std::endl;
    //2*10*3+2*3*5+2*10*5 = 190
    std::cout << "Surface area for rc2 after the change is: " << rc2.surfaceArea() << std::endl;

    //Assign an anonymous Object to rc2
    RectangularCube()= rc2; 
    std::cout << "\nVolume for the object from part (c) is: " << rc2.volume() << std::endl;
    std::cout << "Surface area for tthe object from part (c) is: " << rc2.surfaceArea() << std::endl;

}