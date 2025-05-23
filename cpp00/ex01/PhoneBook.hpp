#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8]; // Fixed array (no dynamic allocation)
        int indexNewContact; // Where to store the next contact (cycles 0–7)
        int nbOfContacts; // Total stored contacts (max 8)
    
    public:
        PhoneBook(); // Constructor
        void    addContact(); // ADD command
        void    searchContact() const; // SEARCH command
};

#endif