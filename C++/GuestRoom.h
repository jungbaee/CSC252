
#ifndef GUESTROOM_H
#define GUESTROOM_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
//b
class GuestRoom: public HotelRoom {
    private:
        int capacity;//b.a.
        int status;//b.b.
        int days;//b.c.
    public:
        GuestRoom();//b.d.
        GuestRoom(int c, int s, int d);
        int getCapacity();
        void setCapacity(int c);
        int getStatus();
        void setStatus(int s);
        int getDays();
        void setDays(int d);
        double calculateBill();//b.e
        string toString(); //b.f
};

GuestRoom::GuestRoom() {
    this->capacity = 4;
    this->status = 0;
    this->days = 7;
}

GuestRoom::GuestRoom(int c, int s, int d) {
    try {
        if (s > c) {
            throw out_of_range("");
        }
        this->capacity = c;
        this->status = s;
        this->days = d;
    } catch (out_of_range& ex) {
        cout<< "out_of_range exception\n\n";
    }
}

int GuestRoom::getCapacity() {
    return this->capacity;
}
void GuestRoom::setCapacity(int c) {
    this->capacity = c;
}

int GuestRoom::getStatus() {
    return this->status;
}

void GuestRoom::setStatus(int s) {
    try {
        if (s > this->capacity) {
            throw out_of_range("");
        }
        this->status = s;
    } catch (out_of_range& ex) {
        cout<< "out_of_range exception\n\n";
    }
}

int GuestRoom::getDays() {
    return this->days;
}

void GuestRoom::setDays(int d) {
    this->days = d;
}

//b.e
double GuestRoom::calculateBill() {
    double bill = (this->getDays())*(this->getRate());
    return bill;
}

string GuestRoom::toString() {
    stringstream ss;
    ss << "The capacity is: " << this->getCapacity() << "\n" << 
    "The status is: " << this->getStatus() << "\n" << 
    "The amount of days is: " << this->getDays() << "\n";
    string s = ss.str();
    return s;
}

#endif