
#include "VirtualEvent.h"
#include <iostream> 
#include <string>


// TO DO: #include any other libraries you need

using namespace std;


VirtualEvent::VirtualEvent() {}
VirtualEvent::VirtualEvent(std::string& name, std::string& description, int& rating, int& soldTicketsCount, std::string& streamLink, std::string& audience) :
	Event(name, description, rating, soldTicketsCount), streamLink(streamLink), audience(audience) {
}
VirtualEvent::~VirtualEvent() {}

void VirtualEvent::display() const {
	cout << "Event Name: " << name << "\n"
		<< "Description: " << description << "\n"
		<< "Rating: " << rating << "\n"
		<< "Tickets Sold: " << soldTicketsCount << "\n"
		<< "Stream Link: " << streamLink << "\n"
		<< "Audience: " << audience << endl;
}

bool VirtualEvent::modify() {
	string tempName = "", tempDescription = "", newAudience = "", newStreamLink = "";
	int newRating = 0, newSoldTicketsCount = 0, newCapacity = 0;
	cout << "Enter new name: ";
	cin >> tempName;
	cout << "Enter new description: ";
	cin >> tempDescription;
	cout << "Enter new rating: ";
	cin >> newRating;
	cout << "Enter new ticket sold count: ";
	cin >> newSoldTicketsCount;
	cout << "Enter new stream link: ";
	cin >> newStreamLink;
	cout << "Enter new audience: ";
	cin >> newAudience;

	name = tempName;
	description = tempDescription;
	rating = newRating;
	soldTicketsCount = newSoldTicketsCount;
	audience = newAudience;
	streamLink = newStreamLink;



	return true;
}

bool VirtualEvent::sell(const int& quantity) {
	soldTicketsCount += quantity;
	cout << "Thank you, stream event here: " << streamLink << endl;

	return true;
}

// output overloading
std::ostream& operator<<(std::ostream& out, const VirtualEvent& event) {
	out << "Event Name: " << event.name << "\n"
		<< "Description: " << event.description << "\n"
		<< "Rating: " << event.rating << "\n"
		<< "Tickets Sold: " << event.soldTicketsCount << "\n"
		<< "Stream Link: " << event.streamLink << "\n"
		<< "Audience: " << event.audience << endl;
	return out;
}

// input overloading
std::istream& operator>>(std::istream& in, VirtualEvent& event) {
	cout << "Enter new name: ";
	in >> event.name;
	cout << "Enter new description: ";
	in >> event.description;
	cout << "Enter new rating: ";
	in >> event.rating;
	cout << "Enter new ticket sold count: ";
	in >> event.soldTicketsCount;
	cout << "Enter new stream link: ";
	in >> event.streamLink;
	cout << "Enter new audience: ";
	in >> event.audience;
	return in;
}

