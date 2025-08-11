#include "Contact.hpp"
#include <iomanip> // For std::setw()

/* Ask the user to fill in all contact fields */
void    Contact::setContact() {
    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
}

/* Print summarized info for SEARCH command
   std::setw(fieldWith) -> sets the width parameter of the stream out or in to exactly `fieldWith`.
   std::endl -> Inserts a newline character into the output sequence 
*/

void    Contact::displayShort(int index) const {
    std::cout << std::setw(10) << index << "|"; // write the index

    if (firstName.length() > 10)
        std::cout << std::setw(10) << firstName.substr(0, 9) + "." << "|"; // write the first name - truncate & align
    else 
        std::cout << std::setw(10) << firstName << "|";

    if (lastName.length() > 10)
        std::cout << std::setw(10) << lastName.substr(0, 9) + "." << "|"; // write the last name - truncate & align
    else 
        std::cout << std::setw(10) << lastName << "|";

    if (nickname.length() > 10)
        std::cout << std::setw(10) << nickname.substr(0, 9) + "." << std::endl; // write the nickname - truncate & align
    else 
        std::cout << std::setw(10) << nickname << std::endl;
}

// Show full details of the selected contact
void    Contact::displayFull() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;

}

// Check if all fields are filled (no empty strings)
bool    Contact::isValid() const {
    return !firstName.empty() && !lastName.empty() && !nickname.empty() 
        && !phoneNumber.empty() && !darkestSecret.empty();
}