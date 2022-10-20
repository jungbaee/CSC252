#include "RectangularCube.h"
#include <iostream>

using namespace std;

//Constructors with definition
RectangularCube::RectangularCube(): l(1), w(1), h(1) {}
RectangularCube::RectangularCube (int length, int width, int height): l(length), w(width), h(height) { }

int RectangularCube::getLength () {return l;}
int RectangularCube::getWidth() {return w;}
int RectangularCube::getHeight() {return h;}

void RectangularCube::setLength (int length) {l = length;}
void RectangularCube::setWidth (int width) {w = width;}
void RectangularCube::setHeight (int height) {h = height;}

int RectangularCube::volume() {return l*w*h;}
int RectangularCube::surfaceArea() {
    return 2*l*w + 2*l*h + 2*w*h;
}

//(e
int main() {
    
    RectangularCube rc1;
    RectangularCube rc2(5,10,6);
    RectangularCube rc3(1,2,3);

    //<< operator overloaded
    cout << "rc1: " << rc1 <<"\n"; 
    cout << "rc2: " << rc2 << "\n"; 
    cout << "rc3: " << rc3 << "\n";

    //< operator overloaded
    cout<< "Example of < operator overloaded: ";
    if (rc2 < rc3) {
        cout<< "rc2 is greater\n";
    } else {
        cout<< "rc3 is greater\n";
    }

    //+operator overloaded
    RectangularCube rc4 = rc2+rc3;
    cout<< rc4 << "\n";

    cout<< "Example of [] operator overloaded" << "\n";
    cout<< "Rc2's 0| length is: " << rc2[0] << "\n";
    cout<< "Rc2's 1| width is: " << rc2[1] << "\n";
    cout<< "Rc2's 2| height is: " << rc2[2] << "\n";
    
}