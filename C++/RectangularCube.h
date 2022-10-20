#include <iostream>
using namespace std;

#ifndef RECTANGULARCUBE_H
#define RECTANGULARCUBE_H

class RectangularCube {
    private:
        int l; //length
        int w; //width
        int h; //height
    
    public:
        
        RectangularCube(); //no arg constructor initializng all sides to '1'
        RectangularCube (int, int, int); //constructor with parameters length, width and height

        int getLength ();
        int getWidth ();
        int getHeight ();

        void setLength (int);
        void setWidth (int);
        void setHeight (int);

        //Return the volume for the rectangular solid: l*w*h
        int volume();

        //Return the surface area for the rectangular solid: 2lw + 2lh + 2wh
        int surfaceArea();


        //(a).. friend functions when you need to access private members of the class
        friend ostream& operator<<(ostream& out, RectangularCube& rc) {
            out << "Length: " << rc.l << " ";
            out << "Width: " << rc.w << " ";
            out << "Height: " << rc.h << " ";
            out << "Volume: " <<rc.volume() << " ";
            out << "SurfaceArea: " <<rc.surfaceArea() << endl;
            return out;
        }

        //(b)
        friend bool operator<(RectangularCube& rc1, RectangularCube& rc2) {
            return rc1.volume() < rc2.volume();
        }

        //(c)
        RectangularCube operator+(RectangularCube &rc){
            RectangularCube rce;
            rce.l = this->l+rc.l;
            rce.w = this->w+rc.w;
            rce.h = this->h+rc.h;
            return rc;
        }

        //(d)
        int operator[](int i){
            if(i==0) {
                return l;
            } else if (i==1) {
                return w;
            } else if (i==2) {
                return h;
            } else {
                return -1;
            }
       }
};



#endif