#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <limits> // For std::numeric_limits, used to handle invalid input in searchContact()

class PhoneBook {
    private:
        Contact contacts[8]; // Fixed array (no dynamic allocation)
        int currentIndex; // Where to store the next contact (cycles 0–7)
        int nbOfContacts; // Total stored contacts (max 8)
    
    public:
        PhoneBook(); // Constructor
        ~PhoneBook(); // Destructor
        void    addContact(); // ADD command
        void    searchContact() const; // SEARCH command
};

#endif