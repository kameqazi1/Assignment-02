#include "LinkedBagDS/LinkedBag.h"
#include <string>
using namespace std;
// TO DO include necessary libraries

 

// This class only contains a single organizer
class EventTicket340 {
	private:
		Organizer organizer;
		string username;
		string email;
		string password;
		string bio;
		string profilePicture;

	public:
		EventTicket340();
		~EventTicket340();

		// Create a new organizer profile
		void createOrganizer(const string& username, const string& email, const string& password, const string& bio, const string& profilePicture);

		// Retrieve the organizer object
		Organizer getOrganizer() const;
};