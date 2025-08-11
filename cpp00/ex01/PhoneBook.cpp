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

    /* Validate input: must be a number and within range
        if input is not an int or pb reading value std::cin.fail() returns true
        OR if index < 0 or index > number of contacts:
        std::cin.clear() resets all error flags making std::cin usable again.
        std::cin.ignore() flushes the remaining junk in the input buffer up to the next newline \n.
        std::numeric_limits<std::streamsize>::max() is just a huge number (largest possible streamsize), 
        ensuring we throw away everything until the newline.
    */
    if (std::cin.fail() || index < 0 || index >= contactCount) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std:streamsize::max(), '\n');
        std::cout << "Invalid index" << std::endl;
        return;
    }
    // Display full contact details for the chosen index
    contacts[index].displayFull();
    // Remove the newline left in the input buffer for the next getline()
    std::cin.ignore();
}
