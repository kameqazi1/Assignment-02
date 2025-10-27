#ifndef EVENT_H
#define EVENT_H

// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <iostream>

// To DO: define the class Organizer with the necessary functions and data fields

class Event{

protected:
	std::string name;
	std::string description;
	int rating;
	int soldTicketsCount;

public:

	Event();
	Event(std::string& name, std::string& description, int& rating, int& soldTicketsCount);
	~Event();
    Event(const Event& other);
    Event& operator=(const Event& other);

	virtual void display() const;
	
	virtual bool modify();

	virtual bool sell(const int& quantity);

	// This is a function that allows you to compare two organizers based on their username and email address.  
	// You may directly include it in your class definition. 
	// You don't need to modify it but will have to put it inside your class. 
	// Operator == overloading function prototype:
	bool operator==(const Event& otherEvent) const;

	// functions for operator overloading
	friend std::ostream& operator<<(std::ostream& out, const Event& event);
	friend std::istream& operator>>(std::istream& in, Event& event);
};

#endif

