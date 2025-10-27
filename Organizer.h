#ifndef ORGANIZER_H
#define ORGANIZER_H

// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <iostream>
#include <memory>
#include "Event.h"
#include "VirtualEvent.h"
#include "VenueEvent.h"
#include "LinkedBagDS/LinkedBag.h"

// To DO: define the class Organizer with the necessary functions and data fields

class Organizer {

protected:
	std::string username;
	std::string email;
	std::string password;
	std::string bio;
	std::string profilePicture;
	LinkedBag<std::shared_ptr<Event>> events;

public:

	Organizer();
	Organizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
	~Organizer(); 								  // Destructor
	Organizer(const Organizer& other);            // Copy constructor
    Organizer& operator=(const Organizer& other); // Copy assignment operator

	void displayProfile();

	bool modifyPassword(const std::string& newPassword);

	bool createEvent( std::shared_ptr<Event> event);

	void displayEventK(const int& k) const;

	void displayAllEvents() const;

	bool modifyEvent(const int& k);

	bool sellTicket(const int& k, const int& quantity);

	bool deleteEvent(const int& k);

	bool reverseAppendEventK(std::shared_ptr<Event> newEvent, const int& k);


	//Added Getters
	LinkedBag<std::shared_ptr<Event>> getEvents();
	int getEventListSize();
	std::string getUsername();
	Organizer getOrganizer();

	// This is a function that allows you to compare two organizers based on their username and email address.  
	// You may directly include it in your class definition. 
	// You don't need to modify it but will have to put it inside your class. 
	// Operator == overloading function prototype:
	bool operator==(const Organizer& otherOrganizer) const;

	//functions for operator overloading
	friend std::ostream& operator<<(std::ostream& out, const Organizer& organizer);
	friend std::istream& operator>>(std::istream& in, Organizer& organizer);

};
#endif