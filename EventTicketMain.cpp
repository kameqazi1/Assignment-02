#include <iostream> 
#include <string>
#include <memory>


// TO DO: #include any other libraries you need
#include "EventTicket340.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Organizer
 * @param organizer object to interact with
 * 
 * */
void displayOrganizerMenu(Organizer& organizer){
	int organizerChoice = 0;
	do {
		cout << "\n Hi, "<< organizer.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Event\n"
		<< "4. Display All Events\n"
		<< "5. Display Kth Event\n"
		<< "6. Modify Event\n"
		<< "7. Sell Tickets\n"
		<< "8. Delete Event\n"
		<< "9. Reverse Append Event K\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> organizerChoice;
		cout << endl;

		switch (organizerChoice) {
			case 1:{ //Display Profile
				// TO DO: display organizer's profile information
				organizer.displayProfile();
				break;
			}
			case 2: { //Modify Password
				// TO DO: ask for new password and update organizer's password
				string password = "";
				cout << "New Password: ";
				cin >> password;
				organizer.modifyPassword(password);
				break;
			}
			case 3: { //Create Event
				// TO DO: ask organizer to choose event type, then ask them to input event details.
				// Create the event and add it to the organizer's events
				string name = "", description = "", venue = "", dateTime = "", streamLink = "", audience = "";
				int rating = 0, soldTicketsCount = 0, capacity = 0, eventChoice = 0, k = 0;

				cout << "Which type of Event:  \n"
					<< "1. Virtual Event \n"
					<< "2. Venue Event \n"
					<< "Choice: ";
				
				while (!(cin >> eventChoice)) {        // try to read a number
					cout << "Invalid input. Please enter an integer: ";
					cin.clear();                  // clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
				}
				cout << endl;
				switch(eventChoice) {
					case 1: {
						cin.ignore();
						cout << "Name: ";
						getline(cin, name);
						cout << "Description: ";
						getline(cin, description);
						cout << "Rating: ";
						while (!(cin >> rating)) {        // try to read a number
							cout << "Invalid input. Please enter a number rating: ";
							cin.clear();                  // clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
						}
						cout << "Tickets sold: ";
						while (!(cin >> soldTicketsCount)) {        // try to read a number
							cout << "Invalid input. Please enter a number ticket count: ";
							cin.clear();                  // clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
						}
						cout << "Enter new stream link: ";
						cin.ignore();
						getline(cin, streamLink);
						cout << "Enter new audience: ";
						getline(cin, audience);
						std::shared_ptr<Event> virtualEPtr = std::make_shared<VirtualEvent>(name, description, rating, soldTicketsCount, streamLink, audience);

						organizer.createEvent(virtualEPtr);
						break;
					}
					case 2: {
						cin.ignore();
						cout << "Name: ";
						getline(cin, name);
						cout << "Description: ";
						getline(cin, description);

						cout << "Rating: ";
						while (!(cin >> rating)) {        // try to read a number
							cout << "Invalid input. Please enter a number Rating: ";
							cin.clear();                  // clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
						}

						cout << "Tickets sold: ";
						while (!(cin >> soldTicketsCount)) {        // try to read a number
							cout << "Invalid input. Please enter a number ticket count: ";
							cin.clear();                  // clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
						}

						cout << "Capacity: ";
						while (!(cin >> capacity)) {        // try to read a number
							cout << "Invalid input. Please enter a number capacity: ";
							cin.clear();                  // clear the error flag
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
						}

						cout << "Venue: ";
						cin.ignore();
						getline(cin, venue);
						cout << "Date and Time: ";
						getline(cin, dateTime);

						std::shared_ptr<Event> venueEPtr = std::make_shared<VenueEvent>(name, description, rating, soldTicketsCount, capacity, venue, dateTime);

						organizer.createEvent(venueEPtr);
						break;
					}
					default: {
						cout << "Invalid choice, exiting to menu." << endl;

						break;
					}
				}
				
				break;
			}
			case 4:{ //Display All Events
				// TO DO: display all organizer's events
				//        You may re-use code from class demo
				organizer.displayAllEvents();
				break;
			}
			case 5: { //Display kth Event
				// TO DO: ask the organizer for a value k
				// Find the Kth event, if k > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				int k = 0;
				cout << "Enter Event Index: ";
				cin >> k;
				organizer.displayEventK(k);

				break;
			}
			case 6: { //Modify Event
				// TO DO: ask the organizer for the index of the event they want to modify.
				// Find the event, then prompt them for the new name and description.
				// Modify the event accordingly. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag

				int k = 0;
				cout << "Enter Event Index: ";
				cin >> k;
				organizer.modifyEvent(k);

				break;
			}
			case 7: { // Sell Ticket to Kth Event
				// TO DO: ask the organizer for the index of the event 
				// Find the event, then sell the tickets. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag

				int k = 0, q=0;
				cout << "Enter Event Index: ";
				cin >> k;
				cout << "Enter how many tickets you want to sell: ";
				cin >> q;

				organizer.sellTicket(k, q);

				break;
			}
			case 8:{ //Delete Kth Event
				// TO DO: ask the organizer for the index of the event they want to delete 
				// Find the event, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag

				int k = 0;
				cout << "Enter index k: ";
				cin >> k;
				organizer.deleteEvent(k);

				break;
			}
			case 9: {
				string name = "", description = "", venue = "", dateTime = "", streamLink = "", audience = "";
				int rating = 0, soldTicketsCount = 0, capacity = 0, eventChoice = 0, k = 0;
				cout << "which index K would you like to reverse append from: ";
				cin >> k;

				cout << "Which type of Event:  \n"
					<< "1. Virtual Event \n"
					<< "2. Venue Event \n"
					<< "Choice: ";
				while (!(cin >> eventChoice)) {        // try to read a number
					cout << "Invalid input. Please enter a number rating: ";
					cin.clear();                  // clear the error flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
				}
				cout << endl;
				switch (eventChoice) {
				case 1: {
					cin.ignore();
					cout << "Name: ";
					getline(cin, name);
					cout << "Description: ";
					getline(cin, description);
					cout << "Rating: ";
					while (!(cin >> rating)) {        // try to read a number
						cout << "Invalid input. Please enter a number rating: ";
						cin.clear();                  // clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
					}
					cout << "Tickets sold: ";
					while (!(cin >> soldTicketsCount)) {        // try to read a number
						cout << "Invalid input. Please enter a number ticket count: ";
						cin.clear();                  // clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
					}
					cout << "Enter new stream link: ";
					cin.ignore();
					getline(cin, streamLink);
					cout << "Enter new audience: ";
					getline(cin, audience);
					std::shared_ptr<Event> virtualEPtr = std::make_shared<VirtualEvent>(name, description, rating, soldTicketsCount, streamLink, audience);

					organizer.reverseAppendEventK(virtualEPtr, k);
					break;
				}
				case 2: {
					cin.ignore();
					cout << "Name: ";
					getline(cin, name);
					cout << "Description: ";
					getline(cin, description);

					cout << "Rating: ";
					while (!(cin >> rating)) {        // try to read a number
						cout << "Invalid input. Please enter a number Rating: ";
						cin.clear();                  // clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
					}

					cout << "Tickets sold: ";
					while (!(cin >> soldTicketsCount)) {        // try to read a number
						cout << "Invalid input. Please enter a number ticket count: ";
						cin.clear();                  // clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
					}

					cout << "Capacity: ";
					while (!(cin >> capacity)) {        // try to read a number
						cout << "Invalid input. Please enter a number capacity: ";
						cin.clear();                  // clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
					}

					cout << "Venue: ";
					cin.ignore();
					getline(cin, venue);
					cout << "Date and Time: ";
					getline(cin, dateTime);

					std::shared_ptr<Event> venueEPtr = std::make_shared<VenueEvent>(name, description, rating, soldTicketsCount, capacity, venue, dateTime);

					organizer.reverseAppendEventK(venueEPtr, k);
					break;
				}
				default: {
					cout << "Invalid choice";

					break;
				}
				}
				break;
			}
			case 0: { //Logout
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (organizerChoice != 0);
}


int main() {
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one organizer
	EventTicket340 eventTicket340;

	cout << "\n" << eventTicket340 << endl;
	// TO DO: Ask the organizer to enter their information 
	//        Instantiate a new Organizer object


	// call eventTicket340 createOrganizer function 
	// replace /*...*/ with the right parameters
	eventTicket340.createOrganizer();

	// Retrieve the organizer 
	Organizer currentOrganizer = eventTicket340.getOrganizer();

	// Display the main menu
	displayOrganizerMenu(currentOrganizer);

	return 0;
};