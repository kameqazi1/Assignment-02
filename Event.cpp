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

// output operator overloading
std::ostream& operator<<(std::ostream& out, const Event& event) {
	out << "Event Name: " << event.name << "\n"
	 << "Description: " << event.description << "\n"
	 << "Rating: " << event.rating << "\n"
	 << "Tickets Sold: " << event.soldTicketsCount << endl;
	return out;
}

// input operator overloading
std::istream& operator>>(std::istream& in, Event& event) {
	cout << "Enter new name: ";
	in >> event.name;
	cout << "Enter new description: ";
	in >> event.description;
	cout << "Enter new rating: ";
	in >> event.rating;
	cout << "Enter new ticket sold count: ";
	in >> event.soldTicketsCount;
	return in;
}




