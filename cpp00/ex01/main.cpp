/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:00:22 by amdemuyn          #+#    #+#             */
/*   Updated: 2025/03/14 18:13:31 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook   phoneBook; // Create a phone book instance
    std::string command; // Store user command (ADD, SEARCH, EXIT)

    while (true) {
        // Prompt the user for a command
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        // Add a new contact
        if (command == "ADD") {
            phoneBook.addContact();
        }
        // Search for an existing contact
        else if (command == "SEARCH") {
            phoneBook.searchContact();
        }
        // Exit the program
        else if (command == "EXIT") {
            break;
        }
        // Ignore any invalid commands
    }
    return (0);
}
