class Robot {
    private:
        int xlocation();
        int ylocation();
        bool cargoeBed ();
        char load ();
    public:
        Robot ();
        void setX(int);
        void setY(int);
        int getX();
        int getY();
        void setCargo(bool);
        bool getCargo();
        void setLoad(char);
        
};