// TO DO: #include needed standard libraries and your own libraries here
using namespace std;
#include <iostream>
#include <vector>

// TO DO: function implementations
#include "Organizer.h"


Organizer::Organizer() {}

Organizer::Organizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture) :
	username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {
}

Organizer::~Organizer() {}

bool Organizer::modifyPassword(const std::string& newPassword){
	password = newPassword;

	return true;
}

void Organizer::displayProfile() {
	cout << "Username: " << username << endl;
	cout << "Email: " << email << endl;
	cout << "Bio: " << bio << endl;
	cout << "Picture: " << profilePicture << endl;
}

bool Organizer::createEvent(const Event& event){
	events.add(event);
	return true;
}

void Organizer::displayEventK(const int& k) const {
	Node<Event>* nodePtr = events.findKthItem(k);

	if (nodePtr != nullptr) {
		Event e = nodePtr->getItem();
		e.display();
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only " << events.getCurrentSize() << " index scope (0, " << events.getCurrentSize()-1 << ")\n";
	}
}

void Organizer::displayAllEvents() const {
	vector<Event> items = events.toVector();
	int counter = 0;
	cout << "Event List: \n" << endl;
	for (const Event& item : items) {
		cout << "Event #" << counter << ":" << endl;
		item.display();
		cout << endl;
		counter++;
	}
}

bool Organizer::modifyEvent(const int& k) {
	Node<Event>* nodePtr = events.findKthItem(k);
	if (nodePtr != nullptr) {
		Event e = nodePtr->getItem(); // copy
		e.modify();                    // modify copy
		nodePtr->setItem(e);
		cout << "Successfully modified event" << endl;
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only " << events.getCurrentSize() << " index scope (0, " << events.getCurrentSize() - 1 << ")\n";
	}

	return nodePtr != nullptr;
}

bool Organizer::sellTicket(const int& k, const int& quantity) {
	Node<Event>* nodePtr = events.findKthItem(k);
	if (nodePtr != nullptr) {
		Event e = nodePtr->getItem(); // copy
		e.sell(quantity);                    // modify copy
		nodePtr->setItem(e);
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only " << events.getCurrentSize() << " index scope (0, " << events.getCurrentSize() - 1 << ")\n";
	}

	return nodePtr != nullptr;
}

bool Organizer::deleteEvent(const int& k) {
	Node<Event>* nodePtr = events.findKthItem(k);
	if (nodePtr != nullptr) {
		events.remove(nodePtr->getItem()); // remove event
		cout << "Successfully removed event." << endl;
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only " << events.getCurrentSize() << " index scope (0, " << events.getCurrentSize() - 1 << ")\n";
	}

	return nodePtr != nullptr;
}


// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
	return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}

//Getters

LinkedBag<Event> Organizer::getEvents() {
	return events;
}

int Organizer::getEventListSize() {
	return events.getCurrentSize();
}

std::string Organizer::getUsername() {
	return username;
}
Organizer Organizer::getOrganizer() {
	return *(this);
}