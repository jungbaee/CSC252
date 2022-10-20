#ifndef HOTELROOM_H
#define HOTELROOM_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//a
class HotelRoom {
    private:
        int number;
        double rate;
    public:
        HotelRoom();
        HotelRoom(int n, double r);
        int getNumber();
        void setNumber(int n);
        double getRate();
        void setRate(double r);
        //e. Polymorphism toString() and calculateBill()
        virtual string toString() {
            stringstream ss;
            ss << "The HotelRoom number is: #" << this->getNumber() << "\n"
            << "The HotelRoom rate is: $" << this->getRate() << "\n";
            string s = ss.str();
            return s;
        }
        //g. with this, now the HotelRoom class is abstract
        virtual double calculateBill() = 0;

};

HotelRoom::HotelRoom() {
    this->number = 100;
    this->rate = 100.0;
}

HotelRoom::HotelRoom(int n, double r) {
    try {
        if (n < 0 || r < 0.0) {
            throw invalid_argument("");
        }
        this->number = n;
        this->rate = r;
    } catch (invalid_argument& ex) {
        cout<< "Negative Parameter\n\n";
    }
}

int HotelRoom::getNumber() {
    return this->number;
}

void HotelRoom::setNumber(int n) {
    try {
        if (n < 0) {
            throw invalid_argument("");
        }
        this->number = n;
    } catch (invalid_argument& ex) {
        cout<< "Negative Parameter\n\n";
    }
}

double HotelRoom::getRate() {
    return this->rate;
}

void HotelRoom::setRate(double r) {
    try {
        if (r < 0) {
            throw invalid_argument("");
        }
        this->rate = r;
    } catch (invalid_argument& ex) {
        cout<< "Negative Parameter\n\n";
    }
}

#endif