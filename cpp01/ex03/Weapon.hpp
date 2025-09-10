#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

/* Use const & when you don’t want unnecessary copies and you don’t want to allow modification of the original.
 * getType() → I’ll give you read-only access to my internal string without copying.
 * setType() → Give me your string (by reference so I don’t copy it), and I promise I won’t modify the one you pass.
 * 
 */
class Weapon {
    private:
        std::string _type;

    public:
        Weapon(std::string type);
        ~Weapon(void);

        const std::string &getType(void) const; // returns a const reference to avoid copies.
        void setType(std::string &type); // change the weapon's type
};

#endif