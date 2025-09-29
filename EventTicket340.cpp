// TO DO: Implementation of EventTicket340 functions
#include <iostream>
#include <string>
#include "EventTicket340.h"
using namespace std;

// TO DO: implement constructor
EventTicket340::EventTicket340(){
	this.organizer = organizer;
};

// TO DO: implement destructor
EventTicket340::~EventTicket340(){
	clear();
};

void EventTicket340::createOrganizer(const string& username, const string& email, const string& password, const string& bio, const string& profilePicture){
	// TO DO: implement function
	cout << "Please enter a username: " << endl;
	cin >> organizer.username;

	cout << "Please enter your email: " << endl;
	cin >> organizer.email;

	cout << "Please enter your password (num only): " <<endl;
	cin >> organizer.password;

	cout << "Please enter a bio: " <<endl;
	cin >> organizer.bio;

	cout<< "Please enter a link to your profile picture: " <<endl;
	cin >> organizer.profilePicture;


}

Organizer EventTicket340::getOrganizer() const{
	// TO DO: implement function
	return organizer;

}