#include "PhoneBook.hpp"

// Constructor: initializes the phone book with no contacts
PhoneBook::PhoneBook() {
    currentIndex = 0; // Position where the next contact will be stored
    nbOfContacts = 0; // Number of contacts currently stored
}

/*add a new contact to the phonebook:
    1 - SetContact() Function to ask the user to fill in all contact fields
    2 - if (!newContact.isValid()) Check if all fields are filled (no empty strings)
    3 - contacts[currentIndex] = newContact: Store the new contact in a rotating position (0 to 7).
    4 - currentIndex = (currentIndex + 1) % 8: 
                Move to the next position, wrapping back to 0 after index 7
                If currentIndex is 7 -> (7+1) % 8 = 0, so currentIndex will be 0 and 9th contact
                will be stored in 1st position (0)
    5 - if (nbOfContacts < 8) only increases till 8, as there cannot be more than 8 contacts stored
*/
void    PhoneBook::addContact() {
    Contact newContact;
    newContact.setContact();

    if (!newContact.isValid()) { 
        std::cout << "Error: Contact information cannot be empty!" << std::endl;
        return;
    }

    contacts[currentIndex] = newContact;
    currentIndex = (currentIndex + 1) % 8;

    if (nbOfContacts < 8)
        nbOfContacts++;
}

/* Display all contacts in a table format, then allow viewing details by index:
    1 - If no contacts, inform the user
    2 - Print the table header
    3 - Loop through stored contacts and display short version
    4 - Ask the user to choose an index
    5 - Clear if incorrect input:
        Input must be a number and within range, if it's not an int or pb reading value
        std::cin.fail() returns true OR if index < 0 or index > number of contacts:
            std::cin.clear() resets all error flags making std::cin usable again.
            std::cin.ignore() flushes the remaining junk in the input buffer up to the next newline \n.
            std::numeric_limits<std::streamsize>::max() is just a huge number (largest possible streamsize), 
            ensuring we throw away everything until the newline.
    6 - Display full contact details for the chosen index
    7 - Remove the newline left in the input buffer for the next getline()
    */
void    PhoneBook::searchContact() const {
    if (nbOfContacts == 0) { 
        std::cout << "No contacts in phonebook!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < nbOfContacts; i++) {
        contacts[i].displayShort(i);
    }

    std::cout << "Enter index: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= nbOfContacts) { 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index" << std::endl;
        return;
    }
    contacts[index].displayFull();
    std::cin.ignore();
}
