#include "phonebook.hpp"
#include <limits> // For std::numeric_limits, used to handle invalid input in searchContact()

// Constructor: initializes the phone book with no contacts
PhoneBook::PhoneBook() {
    currentIndex = 0; // Position where the next contact will be stored
    contactCount = 0; // Number of contacts currently stored
}

/*add a new contact to the phonebook */
void    PhoneBook::addContact() {
    Contact newContact;
    newContact.SetContact(); // Function to ask the user to fill in all contact fields

    // Check if all fields are filled (no empty strings):
    if (!newContact.isValid()) { 
        std::cout << "Error: Contact information cannot be empty!" << std::endl;
        return;
    }

    // Store the new contact in a rotating position (0 to 7). 
    contacts[currentIndex] = newContact;
    // Move to the next position, wrapping back to 0 after index 7:
    // If currentIndex is 7 -> (7+1) % 8 = 0, so currentIndex will be 0 and 9th contact
    // will be stored in 1st position (0)
    currentIndex = (currentIndex + 1) % 8;

    // only increases till 8, as there cannot be more than 8 contacts stored
    if (contactCount < 8)
        contactCount++;
}

/* Display all contacts in a table format, then allow viewing details by index */
void    PhoneBook::searchContact() const {
    if (contactCount == 0) {  // If no contacts, inform the user
        std::cout << "No contacts in phonebook!" << std::endl;
        return;
    }

    // Print the table header
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    
    // Loop through stored contacts and display short version
    for (int i = 0; i < contactCount; i++) {
        contacts[i].displayShort(i);
    }

    // Ask the user to choose an index
    std::cout << "Enter index";
    int index;
    std::cin >> index;

    // Validate input: must be a number and within range
    if (std::cin.fail() || index < 0 || index >= contactCount) {
        std::cin.clear(); // Reset error state
        std::cin.ignore(std::numeric_limits<std:streamsize::max(), '\n'); // Discard bad input
        std::cout << "Invalid index" << std::endl;
        return;
    }
    // Display full contact details for the chosen index
    contacts[index].displayFull();
    // Remove the newline left in the input buffer for the next getline()
    std::cin.ignore();
}

//////////////////////////////////////////////// FOLLOW UP FROM HERE ////////////////////////////////////////////////