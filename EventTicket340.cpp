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
	cin >> organizer;
}

Organizer EventTicket340::getOrganizer() const{
	// TO DO: implement function
    return organizer;

}

// output overloading
std::ostream& operator<<(std::ostream& out, const EventTicket340& ticket) {
	out << " Welcome to EventTicket340:";
	return out;
}