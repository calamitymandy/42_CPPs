#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

/* 
 *Detect the type from a string
 * Parse it correctly
 * Convert to all 4 types
 * Handle edge cases properly
 * Print EXACT format 
 */

// Orthodox Canonical Form (empty because class is static-only)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// ---------- HELPERS ----------
static bool isPseudoLiteral(const std::string &str) {}
static bool isChar(const std::string &str) {}
static bool isInt(const std::string &str) {}
static bool isFloat(const std::string &str) {}
static bool isDouble(const std::string &str) {}

// ---------- PRINT FUNCTIONS ----------

static void printChar(double value) {}
static void printInt(double value) {}
static void printFloat(double value) {}
static void printDouble(double value) {}

// ---------- MAIN CONVERT FUNCTION ----------
void ScalarConverter::convert(const std::string &input) {
    double value = 0.0;

    if (isChar(input))
        value = static_cast<double>(input[0]);
    else if (isPseudoLiteral(input) || isInt(input) || isFloat(input) || isDouble(input))
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