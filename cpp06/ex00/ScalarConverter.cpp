#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

/* Detect the type from a string
 * Parse it correctly
 * Convert to all 4 types
 * Handle edge cases properly
 * Print EXACT format */

// Orthodox Canonical Form (empty because class is static-only)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// ---------- HELPERS ----------
/* Static utility that checks if a given string represents a 
special floating-point pseudo-literal, such as "nan" (Not a Number), 
"inf" (infinity), or their variants. */
static bool isPseudoLiteral(const std::string &str) {
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}

/* Static utility designed to determine if a given string represents 
a single character that is not a digit. It checks two conditions: 
first, that the string length is exactly 1 (ensuring it's a single character), 
and second, that the character is not a digit, then handles the case of + 
or - without single quotes */
static bool isChar(const std::string& str)
{
    if (str.length() != 1)
        return false;

    if (std::isdigit(str[0]))
        return false;

    if (str[0] == '+' || str[0] == '-')
        return false;

    return true;
}

/* Static utility that determines if a given string represents a valid integer, 
including optional leading signs. This is essential in scalar converters for 
distinguishing integers from floats or characters, ensuring accurate type 
detection during parsing. */
static bool isInt(const std::string &str) {
    size_t i = 0;
    if (str.empty())
        return false;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i >= str.length())
        return false;
    for (; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

/* checks whether a string matches the expected syntax for a float literal 
in this converter. It returns true for the special float pseudo-literals 
nanf, +inff, and -inff right away (valid float representations).
For normal numeric forms, it enforces that the string ends with the character f, 
which is the suffix used for single-precision float literals in C-style notation. 
If the last character is not f, it returns false. 
Then it scans the characters before the final f, allowing an optional leading + or - sign, 
and requires all remaining characters to be digits or a single decimal point. 
The local flag hasDot ensures that exactly one dot appears. */
static bool isFloat(const std::string& str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    if (str.length() < 2 || str[str.length() - 1] != 'f')
        return false;

    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i >= str.length() - 1)
        return false;
    for (; i < str.length() - 1; i++)
    {
        if (str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(str[i]))
            hasDigit = true;
        else
            return false;
    }
    return (hasDot && hasDigit);
}

/* static helper that checks whether a string represents a valid double literal 
in the converter’s simplified syntax. It treats the special values 
nan, +inf, and -inf as valid immediately, which matches their common textual 
forms for double values.
For ordinary numeric strings, it first allows an optional leading + or - sign. 
Then it scans every remaining character, requiring digits or a single decimal point. 
The local hasDot flag ensures only one dot is allowed.
*/
static bool isDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;

    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;

    if (str.empty())
        return false;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i >= str.length())
        return false;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(str[i]))
            hasDigit = true;
        else
            return false;
    }
    return (hasDot && hasDigit);
}

// ---------- PRINT FUNCTIONS ----------
/* Static utility that outputs the character representation of a given double value.
It checks if the value is invalid for character conversion: if it's NaN (Not a Number),
infinity, negative, or exceeds 127 (the maximum ASCII value). If any condition holds, 
it prints "impossible\n".
If valid, it casts the double to char using static_cast<char>(value) and checks if the 
result is printable with std::isprint. Printable characters include visible ASCII symbols, 
letters, and digits (excluding control characters like newline). If not printable, 
it outputs "Non displayable\n"; otherwise, it prints the character enclosed in single quotes, 
like "'a'\n". */
static void printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
    {
        std::cout << "impossible\n";
        return;
    }
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";
}

/* static utility that outputs the integer representation of a given double value. 
It checks if the value is invalid for integer conversion: if it's NaN (Not a Number), 
infinity, less than std::numeric_limits<int>::min(), or greater than std::numeric_limits<int>::max(). 
If any condition is true, it prints "impossible\n".
If valid, it casts the double to int using static_cast<int>(value) and prints the 
result followed by a newline. This handles truncation of fractional parts (e.g., 3.9 becomes 3), 
which is standard C++ behavior for narrowing conversions.*/
static void printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
    {
        std::cout << "impossible\n";
        return;
    }
    else
        std::cout << static_cast<int>(value) << "\n";
}

/* Static utility that outputs the float representation of a given double value. 
It casts the double to float using static_cast<float>(value), which may introduce 
precision loss.
It checks if the float is NaN (Not a Number) with std::isnan(f), printing "nanf\n" 
if true. If it's infinity, it uses std::isinf(f) and checks the sign with f > 0 
to print "+inff\n" or "-inff\n". For normal values, it prints the float directly, 
then appends ".0" if the value is a whole number (checked by comparing f to static_cast<int>(f))
ensuring output like "3.0f" instead of "3f" to mimic C++ float literals. 
Finally, it adds "f\n" to denote single-precision.

Float conversion is never "impossible". It always produces:
a valid number
OR +inf / -inf
OR nan*/
static void printFloat(double value)
{
    std::cout << "float: ";

    if (std::isnan(value))
    {
        std::cout << "nanf\n";
        return;
    }

    if (value > std::numeric_limits<float>::max())
    {
        std::cout << "+inff\n";
        return;
    }

    if (value < -std::numeric_limits<float>::max())
    {
        std::cout << "-inff\n";
        return;
    }

    float f = static_cast<float>(value);
    std::cout << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f\n";
}
/* Static utility that outputs the double representation of a given double value. 
It checks if the value is NaN (Not a Number) with std::isnan(value), 
outputting "nan\n" if true. If it's infinity, it uses std::isinf(value) 
and checks the sign with value > 0 to print "+inf\n" or "-inf\n".
For normal values, it prints the double directly, then appends ".0" if the value 
is a whole number (checked by comparing value to static_cast<int>(value)), 
ensuring output like "3.0" instead of "3" to mimic C++ double literals. 
Finally, it adds "\n" for formatting. */
static void printDouble(double value) {
    std::cout << "double: ";

    if (std::isnan(value))
        std::cout << "nan\n";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf\n" : "-inf\n");
    else
    {
        std::cout << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << "\n";
    }
}

// ---------- MAIN CONVERT FUNCTION ----------
void ScalarConverter::convert(const std::string &input) {
    double value = 0.0;

    if (isChar(input))
        value = static_cast<double>(input[0]);
    else if (isInt(input) || isFloat(input) || isDouble(input) || isPseudoLiteral(input))
        value = std::strtod(input.c_str(), NULL);
    else {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}