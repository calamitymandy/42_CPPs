#ifndef BASE_HPP
#define BASE_HPP

// Virtual destructor is mandatory, needed for polymorphism and safe deletion

class Base {
    public: 
        virtual ~Base();
};

#endif