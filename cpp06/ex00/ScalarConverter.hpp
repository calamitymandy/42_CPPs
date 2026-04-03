#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

/*
 * Orthodox Canonical Form
 * Non-instantiable
 * No implementation inside
*/

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();
    
    public:
        static void convert(const std::string &input);
};

#endif