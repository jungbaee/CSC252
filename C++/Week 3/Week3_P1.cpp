#include "Robot.h"
#include <iostream>

using namespace std;

Robot::Robot() {
        this->xlocation = 0;
        this->ylocation = 0;
        this->cargoBed = false;
        this->load = '0';
    };
    void Robot::setX(int x) {
        this->xlocation = x;
    }

    void Robot::setY(int y) {
        this->ylocation = y;
    }

    int Robot::getX() {
        return xlocation;
    }

    int Robot::getY(){
        return ylocation;
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

    bool Robot::moveTo(int x, int y) {
        int currentXLocation = getX();
        int currentYLocation = getY();

        if (x > currentXLocation) {
            for (int i = currentXLocation; i <= x; i++) {
                setX(i);
            }
        } else if (x < currentXLocation) {
            for (int i = currentXLocation; i >= x; i--) {
                setX(i);
            }
        }

        if (y > currentYLocation) {
            for (int i = currentYLocation; i <= y; i++) {
                setY(i);
            }
        } else if (y < currentYLocation) {
            for (int i = currentYLocation; i >= y; i--) {
                setY(i);
            }
        }
        return true;
    }

    void Robot::printRobot() {
        cout << "X: " << getX() << "| Y: " << getY() << ". \n";
        cout << "The cargobed is: " << getCargo() << "| the load is: " << getLoad() << ". \n\n";
    }

int main () {
    Robot* r = new Robot[3];
    
    cout<< "These are the initial positions"<<endl;
    //The initial set up
    r[0].printRobot();
    r[1].printRobot();
    r[2].printRobot();
    
    //setting different loads
    r[0].setLoad('a');
    r[1].setLoad('b');
    r[2].setLoad('c');

    //moving them around
    r[0].moveTo(1,2);
    r[1].moveTo(5,9);
    r[2].moveTo(3,8);

    cout<< "These are the new positions"<<endl;
    //Print their new locations
    r[0].printRobot();
    r[1].printRobot();
    r[2].printRobot();

    delete []r;


}