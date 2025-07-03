#include "phonebook.hpp"
#include <limits> // For std::numeric_limits

PhoneBook::PhoneBook() {
    currentIndex = 0;
    contactCount = 0;
}

//add a new contact to the phonebook
void    PhoneBook::addContact() {
    Contact newContact;
    newContact.SetContact(); // Function to ask the user to fill in all contact fields

    // Check if all fields are filled (no empty strings):
    if (!newContact.isValid()) { 
        std::cout << "Error: Contact information cannot be empty!" << std::endl;
        return;
    }

    // Store the new contact in a rotating position (0 to 7). 
    // If currentIndex is 7 -> (7+1) % 8 = 0, so currentIndex will be 0 and 9th c
    contacts[currentIndex] = newContact;
    currentIndex = (currentIndex + 1) % 8;

    // only increases till 8, as there cannot be more than 8 contacts stored
    if (contactCount < 8)
        contactCount++;

//////////////////////////////////////////////// FOLLOW UP FROM HERE ////////////////////////////////////////////////
}

