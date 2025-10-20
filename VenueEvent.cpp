#include <iostream> 
#include <string>


// TO DO: #include any other libraries you need
#include "VenueEvent.h"

using namespace std;


VenueEvent::VenueEvent() {}
VenueEvent::VenueEvent(std::string& name, std::string& description, int& rating, int& soldTicketsCount, int& capacity, std::string& venue, std::string& dateTime) :
	Event(name, description, rating, soldTicketsCount), capacity(capacity), venue(venue), dateTime(dateTime) {
}
VenueEvent::~VenueEvent() {}

void VenueEvent::display() const {
	cout << "Event Name: " << name << "\n"
		<< "Description: " << description << "\n"
		<< "Rating: " << rating << "\n"
		<< "Tickets Sold: " << soldTicketsCount << "\n"
		<< "Capacity: " << capacity << "\n"
		<< "Venue: " << venue << "\n"
		<< "Date and Time: " << dateTime << endl;
}

bool VenueEvent::modify() {
	string tempName = "", tempDescription = "", newVenue ="", newDateTime ="";
	int newRating = 0, newSoldTicketsCount = 0, newCapacity = 0;
	cout << "Enter new name: ";
	cin >> tempName;
	cout << "Enter new description: ";
	cin >> tempDescription;
	cout << "Enter new rating: ";
	cin >> newRating;
	cout << "Enter new ticket sold count: ";
	cin >> newSoldTicketsCount;
	cout << "Enter new ticket capacity: ";
	cin >> newCapacity;
	cout << "Enter new venue: ";
	cin >> newVenue;
	cout << "Enter date and time: ";
	cin >> newDateTime;

	name = tempName;
	description = tempDescription;
	rating = newRating;
	soldTicketsCount = newSoldTicketsCount;
	capacity = newCapacity;
	venue = newVenue;
	dateTime = newDateTime;



	return true;
}

bool VenueEvent::sell(const int& quantity) {
	if ((soldTicketsCount + quantity) <= capacity) {
		soldTicketsCount += quantity;
	}
	else {
		cout << "Event Sold Out!" << endl;
	}
	
	return true;
}

// output overloading
std::ostream& operator<<(std::ostream& out, const VenueEvent& event) {
	out << "Event Name: " << event.name << "\n"
		<< "Description: " << event.description << "\n"
		<< "Rating: " << event.rating << "\n"
		<< "Tickets Sold: " << event.soldTicketsCount << "\n"
		<< "Capacity: " << event.capacity << "\n"
		<< "Venue: " << event.venue << "\n"
		<< "Date and Time: " << event.dateTime << endl;
	return out;
}

// input overloading
std::istream& operator>>(std::istream& in, VenueEvent& event) {
	cout << "Enter new name: ";
	in >> event.name;
	cout << "Enter new description: ";
	in >> event.description;
	cout << "Enter new rating: ";
	in >> event.rating;
	cout << "Enter new ticket sold count: ";
	in >> event.soldTicketsCount;
	cout << "Enter new ticket capacity: ";
	in >> event.capacity;
	cout << "Enter new venue: ";
	in >> event.venue;
	cout << "Enter date and time: ";
	in >> event.dateTime;
	return in;
}
