#include "Robot.h"
#include <iostream>

using namespace std;

Robot::Robot() {
    this->xLocation = 0;
    this->yLocation = 0;
    this->cargoBed = false;
    this->load = '.';
};

Robot::Robot(int x, int y, bool cb, char l) {
    this->xLocation = x;
    this->yLocation = y;
    this->cargoBed = cb;
    this->load = l;
};

void Robot::setX(int x) {
    this->xLocation = x;
}

void Robot::setY(int y) {
    this->yLocation = y;
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

    if (lx > 10 || 
        ly > 10 || 
        lx < 0 || 
        ly < 0) {
        return false;
    }

    if (x > currentXLocation) {
        for (int i = currentXLocation; i <= lx; i++) {
            setX(i);
        }
    } else if (x < currentXLocation) {
        for (int i = currentXLocation; i >= lx; i--) {
            setX(i);
        }
    }

    if (y > currentYLocation) {
        for (int i = currentYLocation; i <= ly; i++) {
            setY(i);
        }
    } else if (y < currentYLocation) {
        for (int i = currentYLocation; i >= ly; i--) {
            setY(i);
        }
    }
        return true;
}

//d
bool Robot::pickUp (int lx, int ly) {
    if (load == '.' || cargoBed == true) {
        return false;
    }

    moveTo(lx, ly);
    load = grid[lx][ly];
    grid[lx][ly] = '.';
    cargoBed = true;
    return true;
}

bool Robot::dropOff(int lx, int ly) {
    if (grid[lx][ly] != '.' || cargoBed == false {
        return false;
    }

    moveTo(lx, ly);
    grid[lx][ly] = load;
    load = '.';
    cargoBed = false;
    return true;

}

friend ostream& operator<<(ostream& out, Robot& r) {
    out << "(" << r.getX << ", " << r.getY << ") :" << r.load << "\n";
    return out;
}

void Robot::printRobot() {
    cout << "X: " << getX() << "| Y: " << getY() << ". \n";
    cout << "The cargobed is: " << getCargo() << "| the load is: " << getLoad() << ". \n\n";
}
