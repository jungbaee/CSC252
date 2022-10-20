#include <iostream>
#include <string>


using namespace std;

class Sample {
    public:
        Sample();
        Sample(int, int);
        Sample operator+(Sample);
        int get_x();
        int get_y();
    private:
    int x;
    int y;
};

Sample::Sample() {

}

Sample::Sample(int a, int b) {
    x = a;
    y = b;
}

Sample Sample::operator+(Sample param){
    Sample temp;
    temp.x = x+ param.x;
    temp.y = y+param.y;
    return temp;
}

int Sample::get_x() {
    return x;
}
int Sample::get_y() {
    return y;
}

int main () {
    Sample a(4,1);
    Sample b(3,2);
    Sample c;
    c = a+b;
    cout << c.get_y() << "." << c.get_x();
    return 0;
}