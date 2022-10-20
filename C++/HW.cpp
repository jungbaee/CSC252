#include<iostream>

//This is the abstraction of a gameboard
class Grid {

    private:
        //10x10 game board
        int board [10][10];

    public:
        //no-arg constructor initializing the board to '0's
        Grid () {
            for (int i = 0; i <10; i++) {
                for (int j = 0; j<10; j++) {
                    board[i][j] = 0;
                }
            }
        }

        //Accessors and mutators down below
        int getElement(int i, int j) {
            return board[i][j];
        }

        void setElement(int i, int j, int value) {
            board [i][j] = value;
        }
};

int main(){
   
    //Create a Grid object 'g'
    Grid g;

    g.setElement(3,5,100);

    //Print out the result from using the setter/getter method
    std::cout<< "The value at board[3][5] is: " << g.getElement(3,5) << std::endl;

}

