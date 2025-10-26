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

// Copy constructor
EventTicket340::EventTicket340(const EventTicket340& other)
	: organizer(other.organizer),
	  username(other.username),
	  email(other.email),
	  password(other.password),
	  bio(other.bio),
	  profilePicture(other.profilePicture)
{}

// Assignment operator
EventTicket340& EventTicket340::operator=(const EventTicket340& other){
	if(this != &other){
			organizer = other.organizer;
			username = other.username;
			email = other.email;
			password = other.password;
			bio = other.bio;
			profilePicture = other.profilePicture;
		}	
	return *this;
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