/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:50:09 by amdemuyn          #+#    #+#             */
/*   Updated: 2025/08/11 18:38:49 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip> // For std::setw()

/*
 *private: contact fields of the contact
 *public:
    - setContact: Fill contact fields from user input
    - displayShort: Show summarized info in table format
    - displayFull: Show full info for one contact
    - isValid: Check if all fields are filled
*/
class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    
    public:
        void    setContact();
        void    displayShort(int index) const;
        void    displayFull() const;
        bool    isValid() const;
};

#endif