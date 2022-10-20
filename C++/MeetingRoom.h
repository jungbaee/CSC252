#ifndef MEETINGROOM_H
#define MEETINGROOM_H
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//C
class MeetingRoom: public HotelRoom {
    private:
        int seats;//c.a.
        int status;//c.b.
    public:
        MeetingRoom();
        MeetingRoom(int se, int st);
        int getSeats();
        void setSeats(int se);
        int getStatus();
        void setStatus(int st);
        string toString();
        double calculateBill();
};

MeetingRoom::MeetingRoom() {
    this->seats = 0;
    this->status = 0;
}

MeetingRoom::MeetingRoom(int se, int st) {
    this->seats = se;
    this->status = st;
}

int MeetingRoom::getSeats() {
    return this->seats;
}

void MeetingRoom::setSeats(int se) {
    this->seats = se;
}

int MeetingRoom::getStatus() {
    return this->status;
}

void MeetingRoom::setStatus(int st) {
    this->status = st;
}
string MeetingRoom::toString() {
    stringstream ss;
    ss << "There are: " << this->getSeats() << " seats \n" << 
    "The status is: " << this->getStatus() << "\n";

    string s = ss.str();
    return s;
}
double MeetingRoom::calculateBill() {
    double bill = this->getSeats()*10 + 500;
    return bill;
}


#endif