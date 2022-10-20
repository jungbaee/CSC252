#include "HotelRoom.h"
#include "GuestRoom.h"
#include "MeetingRoom.h"
#include <iostream>

using namespace std;

//e
void displayHotelRoom(HotelRoom* hr) {
    cout << "The bill for the HotelRoom is: $" <<hr->calculateBill() << "\n\n";
}


int main () {
    //cout<< "\nThis is the HotelRoom.h test block:\n";
    //HotelRoom* hr1 = new HotelRoom(101,-100);//exception
    //HotelRoom* hr2 = new HotelRoom(102,100);
    //cout<< hr2->toString() << "\n";
    //f. 1 HotelRoom Object
    //displayHotelRoom(hr2);

    //delete hr1;
    //delete hr2;

    cout<< "This is the GuestRoom.h test block:\n";
    //GuestRoom* gr1 = new GuestRoom(10,11,2);//exception
    GuestRoom* gr2 = new GuestRoom(15,11,3);
    cout<< gr2->toString() << "\n";
    //cout<< "The bill for gr2 is: $" <<gr2->calculateBill() << "\n\n";//3 days* $100 (the default)
    //f. 2 GuestRoom Object
    displayHotelRoom(gr2);
    //delete gr1;
    delete gr2;

    cout<< "This is the MeetingRoom.h test block:\n";
    MeetingRoom* mr1 = new MeetingRoom(10,0);
    cout << mr1->toString() << "\n";;
    //cout<< "The bill for mr1 is: $" <<mr1->calculateBill() << "\n\n";//10 seats*10 + 500 (default
    //f. 3 MeetingRoom Object
    displayHotelRoom(mr1);
    delete mr1;

}