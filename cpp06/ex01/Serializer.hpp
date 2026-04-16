#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h> // For uintptr_t

/* uintptr_t -> Unsigned integer type guaranteed to:
    - store a pointer safely
    - be large enough to hold an address
uintptr_t is defined to store pointer values without loss of information.”*/

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &copy);
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif