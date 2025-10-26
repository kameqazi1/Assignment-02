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

Organizer::~Organizer() = default;

bool Organizer::modifyPassword(const std::string& newPassword){
	password = newPassword;

	return true;
}

void Organizer::displayProfile() {
	cout << *this;
}

bool Organizer::createEvent( std::shared_ptr<Event> event){
	return events.add(event);
}

void Organizer::displayEventK(const int& k) const {
	Node<std::shared_ptr<Event>>* nodePtr = events.findKthItem(k);

	if (nodePtr != nullptr) {
		std::shared_ptr<Event> e = nodePtr->getItem();  // getItem() returns Event*
		if (e != nullptr) {
			e->display();               // use -> since e is a pointer
		}
		else {
			cout << "Error: null event pointer at index " << k << "!\n";
		}
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only "
			<< events.getCurrentSize()
			<< " index scope (0, " << events.getCurrentSize() - 1 << ")\n";
	}
}

void Organizer::displayAllEvents() const {
	vector<std::shared_ptr<Event>> items = events.toVector();  // vector of pointers
	int counter = 0;

	cout << "Event List:\n" << endl;

	for (const auto& item : items) {          // each item is a pointer
		if (item != nullptr) {
			cout << "Event #" << counter << ":\n";
			item->display();                   // use -> since it's a pointer
			cout << endl;
		}
		else {
			cout << "Event #" << counter << ": [null pointer]\n\n";
		}
		counter++;
	}
}

bool Organizer::modifyEvent(const int& k) {
	Node<std::shared_ptr<Event>>* nodePtr = events.findKthItem(k);
	if (nodePtr != nullptr) {
		std::shared_ptr<Event> e = nodePtr->getItem();   // get pointer to original event
		if (e != nullptr) {
			e->modify();                 // modify the actual event
			cout << "Successfully modified event" << endl;
		}
		else {
			cout << "Error: null event pointer at index " << k << "!\n";
			return false;
		}
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only "
			<< events.getCurrentSize()
			<< " index scope (0, " << events.getCurrentSize() - 1 << ")\n";
		return false;
	}

	return true;
}

bool Organizer::sellTicket(const int& k, const int& quantity) {
	Node<std::shared_ptr<Event>>* nodePtr = events.findKthItem(k);
	if (nodePtr != nullptr) {
		std::shared_ptr<Event> e = nodePtr->getItem(); // copy
		e->sell(quantity);                    // modify copy
		nodePtr->setItem(e);
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only " << events.getCurrentSize() << " index scope (0, " << events.getCurrentSize() - 1 << ")\n";
	}

	return nodePtr != nullptr;
}

bool Organizer::deleteEvent(const int& k) {
	Node<std::shared_ptr<Event>>* nodePtr = events.findKthItem(k);
	if (nodePtr != nullptr) {
		events.remove(nodePtr->getItem()); // remove event
		cout << "Successfully removed event." << endl;
	}
	else {
		cout << "Error, no event at that index!\n";
		cout << "Event list size is only " << events.getCurrentSize() << " index scope (0, " << events.getCurrentSize() - 1 << ")\n";
	}

	return nodePtr != nullptr;
};

bool Organizer::reverseAppendEventK(std::shared_ptr<Event> newEvent, const int& k) {
	if (events.reverseAppendK(newEvent, k)) {    // calls LinkedBag�s function
		cout << "Successfully inserted event after " << k << "th-from-end.\n";
		return true;
	}
	else {
		cout << "Error: invalid index ("
			<< k << "). Bag size is " << events.getCurrentSize() << ".\n";
		return false;
	}
}


// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
	return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}

//Getters

LinkedBag<std::shared_ptr<Event>> Organizer::getEvents() {
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

// output overloading
std::ostream& operator<<(std::ostream& out, const Organizer& organizer) {
	out << "Username: " << organizer.username << endl;
	out << "Email: " << organizer.email << endl;
	out << "Bio: " << organizer.bio << endl;
	out << "Picture: " << organizer.profilePicture << endl;
	return out;
}

// input overloading
std::istream& operator>>(std::istream& in, Organizer& organizer) {
	cout << "Please enter a username: ";
	getline(in, organizer.username);
	cout << "Please enter your email: ";
	getline(in, organizer.email);
	cout << "Please enter your password (num only): ";
	getline(in, organizer.password);
	cout << "Please enter a bio: ";
	getline(in, organizer.bio);
	cout << "Please enter a link to your profile picture: ";
	getline(in, organizer.profilePicture);
	return in;
}

// Copy constructor (deep copy)
Organizer::Organizer(const Organizer& other)
    : username(other.username),
      email(other.email),
      password(other.password),
      bio(other.bio),
      profilePicture(other.profilePicture)
{
    for (auto& e : other.events.toVector()) {
        events.add(std::make_shared<Event>(*e)); 
    }
}

// Assignment operator (deep copy)
Organizer& Organizer::operator=(const Organizer& other) {
    if (this != &other) {
        username = other.username;
        email = other.email;
        password = other.password;
        bio = other.bio;
        profilePicture = other.profilePicture;
        events.clear();
        for (auto& e : other.events.toVector()) {
            events.add(std::make_shared<Event>(*e));
        }
    }
    return *this;
}
