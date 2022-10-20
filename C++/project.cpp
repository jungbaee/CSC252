#include <iostream>
#include "Robot.h"
using namespace std;

//h.
char grid [10][10];

//g.
void print2D() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j] << " ";
        } cout << "\n";
    } cout << "\n\n";
}

//m.
void clear(char g[10][10]) {
    Robot* r3;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (g[i][j] != '.') {
                r3 = new Robot(i,j, true, g[i][j]);
                r3->pickUp(i,j);
                g[i][j] = '.';
            }
            
        }
    }
    delete r3;
}

int main () {
    //h
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 10; j++) {
            grid[i][j] = '.';
        }
    }
    //h
    grid[3][8] = 'B';
    grid[2][6] = 'C';

    //i 
    cout<< "Placing robots in random locations" << "\n";
    Robot R1;
    Robot R2(5, 5, false, '.');
    cout << R1;
    cout << R2;
    //print the board
    print2D();

    //j
    R1.moveTo(9,2);
    R2.moveTo(3,4);
    cout<< "Placing R1 in (9,2) and R2 in (3,4)" << "\n";
    cout << R1;
    cout << R2;
    //print the board
    print2D();

    //k
    cout<< "Picking up R1 from (3,8) and then dropping off on (9,9)" << "\n";
    R1.pickUp(3,8);
    cout << R1;
    R1.dropOff(9,9);
    cout << R1;
    print2D();

    cout<< "Picking up R1 from (2,6) and then dropping off on (0,0)" << "\n";
    R2.pickUp(2,6);
    cout << R2;
    R2.dropOff(0,0);
    cout << R2;
    print2D();

    cout<< "Clearing the grid" << "\n";
    clear(grid);
    print2D();
}