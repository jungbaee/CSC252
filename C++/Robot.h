#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
using namespace std;

extern char grid[10][10];

class Robot {
    private:
        int xLocation;//a
        int yLocation;//b
        bool cargoBed;//c
        char load;//d
    public:
        Robot ();
        Robot (int, int, bool, char);//a
        void setX(int);//b
        void setY(int);//b
        int getX();//b
        int getY();//b
        void setCargo(bool);//b
        bool getCargo();//b
        void setLoad(char);//b
        char getLoad();//b
        bool moveTo(int lx, int ly);//c
        bool pickUp(int lx, int ly);//d
        bool dropOff(int lx, int ly);//e
        friend ostream& operator<<(ostream& out, Robot& r);//f
        void printRobot();//b
};


Robot::Robot() {
    this->xLocation = 0;
    this->yLocation = 0;
    this->cargoBed = false;
    this->load = '.';
};

Robot::Robot(int lx, int ly, bool cb, char l) {
    this->xLocation = lx;
    this->yLocation = ly;
    this->cargoBed = cb;
    this->load = l;
};

void Robot::setX(int lx) {
    this->xLocation = lx;
}

void Robot::setY(int ly) {
    this->yLocation = ly;
}

int Robot::getX() {
    return xLocation;
}

int Robot::getY(){
    return yLocation;
}

void Robot::setCargo(bool b) {
    this->cargoBed = b;
}

bool Robot::getCargo(){
    return cargoBed;
}

void Robot::setLoad(char l){
    this->load = l;
}

char Robot::getLoad() {
    return load;
}
//c
bool Robot::moveTo(int lx, int ly) {
    int currentXLocation = getX();
    int currentYLocation = getY();

    //This function checks to see whether the location (lx, ly) 
    //is within the boundary of the grid, if not returns false.
    if (lx > 10 || 
        ly > 10 || 
        lx < 0 || 
        ly < 0) {
        return false;
    }

    //Otherwise, the function checks the current position of the robot object at (xLocation, yLocation) 
    //then using loops moves the robot object (one cell at a time) to the new location given by parameters lx and ly. 
    if (lx > currentXLocation) {
        for (int i = currentXLocation; i <= lx; i++) {
            setX(i);
        }
    } else if (lx < currentXLocation) {
        for (int i = currentXLocation; i >= lx; i--) {
            setX(i);
        }
    }

    if (ly > currentYLocation) {
        for (int i = currentYLocation; i <= ly; i++) {
            setY(i);
        }
    } else if (ly < currentYLocation) {
        for (int i = currentYLocation; i >= ly; i--) {
            setY(i);
        }
    }
        return true;
}

//d
bool Robot::pickUp (int lx, int ly) {
    if (load == '.' && cargoBed == false && grid[lx][ly] != '.') {
        moveTo(lx, ly);
        load = grid[lx][ly];
        grid[lx][ly] = '.';
        cargoBed = true;
        return true;
    }
    return false;  
}

    

bool Robot::dropOff(int lx, int ly) {
    if (grid[lx][ly] == '.' && load != '.' && cargoBed == true) {
        moveTo(lx, ly);
        grid[lx][ly] = load;
        load = '.';
        cargoBed = false;
        return true;
    }

    return false;
}

//f.	Overload the operator “<<” for the Robot class to print the location 
//of the robot on the grid as well as its load, 
ostream& operator<<(ostream& out, Robot& r) {
    out << "(" << r.getX() << ", " << r.getY() << ") :" << r.getLoad() << "\n";
    return out;
}

#endif
    