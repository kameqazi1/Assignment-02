#ifndef VENUEEVENT_H
#define VENUEEVENT_H

// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <iostream>
#include "Event.h"

// To DO: define the class Organizer with the necessary functions and data fields

class VenueEvent : public Event {

protected:
	std::string venue;
	std::string dateTime;
	int capacity;

public:

	VenueEvent();
	VenueEvent(std::string& name, std::string& description, int& rating, int& soldTicketsCount, int& capacity, std::string& venue, std::string& dateTime);
	~VenueEvent();

	void display() const;

	bool modify();

	bool sell(const int& qunantity);

	// functions for operator overloading
	friend std::ostream& operator<<(std::ostream& out, const VenueEvent& event);
	friend std::istream& operator>>(std::istream& in, VenueEvent& event);

};

#endif

