#ifndef VIRTUALEVENT_H
#define VIRTUALEVENT_H

// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include "Event.h"

// To DO: define the class Organizer with the necessary functions and data fields

class VirtualEvent : public Event {

protected:
	std::string streamLink;
	std::string audience;

public:

	VirtualEvent();
	VirtualEvent(std::string& name, std::string& description, int& rating, int& soldTicketsCount, std::string& streamLink, std::string& audience);
	~VirtualEvent();

	void display() const;

	bool modify();

	bool sell(const int& qunantity);
};

#endif

