
#ifndef EVENTTICKET340_H
#define EVENTTICKET340_H


#include <string>
// TO DO include necessary libraries
#include "Organizer.h"
 

// This class only contains a single organizer
class EventTicket340 {
	private:
		Organizer organizer;
		std::string username;
		std::string email;
		std::string password;
		std::string bio;
		std::string profilePicture;

	public:
		EventTicket340();
		~EventTicket340();

		// Create a new organizer profile
		void createOrganizer();

		// Retrieve the organizer object
		Organizer getOrganizer() const;
};
#endif