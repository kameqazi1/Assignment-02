// TO DO: #include all the standard libraries and your own libraries here
using namespace std;
#include <iostream>

// TO DO: function implementations
#include "Event.h"

Event::Event() {}

Event::Event(std::string& name, std::string& description, int& rating, int& soldTicketsCount) :
	name(name), description(description), rating(rating), soldTicketsCount(soldTicketsCount) {
}

Event::~Event() {}


void Event::display() const {
	cout << "Event Name: " << name << "\n"
	 << "Description: " << description << "\n"
	 << "Rating: " << rating << "\n"
	 << "Tickets Sold: " << soldTicketsCount << endl;
}

bool Event::modify() {
	string tempName = "", tempDescription = "";
	int newRating = 0, newSoldTicketsCount = 0;
	cout << "Enter new name: ";
	cin >> tempName;
	cout << "Enter new description: ";
	cin >> tempDescription;
	cout << "Enter new rating: ";
	cin >> newRating;
	cout << "Enter new ticket sold count: ";
	cin >> newSoldTicketsCount;
	
	name = tempName;
	description = tempDescription;
	rating = newRating;
	soldTicketsCount = newSoldTicketsCount;

	return true; 
}

bool Event::sell(const int& quantity){
	soldTicketsCount += quantity;
	return true; 
	}

// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}




