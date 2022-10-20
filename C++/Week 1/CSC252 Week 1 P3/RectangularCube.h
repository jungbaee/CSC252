#ifndef RECTANGULARCUBE_H
#define RECTANGULARCUBE_H

class RectangularCube {
    private:
        int l;//length
        int w;//width
        int h;//height
    
    public:

        //Accessors
        int getLength();
        int getWidth();
        int getHeight();

        //Mutators
        void setLength (int);
        void setWidth (int);
        void setHeight (int);

        //Return the volume for the rectangular solid: l*w*h
        int volume();

        //Return the surface area for the rectangular solid: 2lw + 2lh + 2wh
        int surfaceArea();

};


#endif