// TO DO: Implementation of EventTicket340 functions
#include <iostream>
#include <string>
#include "EventTicket340.h"
#include "Organizer.h"
using namespace std;

// TO DO: implement constructor
EventTicket340::EventTicket340() {
}

// TO DO: implement destructor
EventTicket340::~EventTicket340(){
    organizer.getEvents().clear();
}

void EventTicket340::createOrganizer(){
	// TO DO: implement function
    string uname, mail, pw, b, pic;

    cout << "Please enter a username: ";
    cin >> uname;
    cout << "Please enter your email: ";
    cin >> mail;
    cout << "Please enter your password (num only): ";
    cin >> pw;
    cout << "Please enter a bio: ";
    cin >> b;
    cout << "Please enter a link to your profile picture: ";
    cin >> pic;

    organizer =  Organizer(uname, mail, pw, b, pic);
}

Organizer EventTicket340::getOrganizer() const{
	// TO DO: implement function
    return organizer;

}