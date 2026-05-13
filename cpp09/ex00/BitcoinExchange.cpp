#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) { *this = copy; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy) {
        _data = copy._data;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}


// trim whitespace from a string
static void trim(std::string &s) {
    const char *whitespace = " \t\n\r";
    size_t start = s.find_first_not_of(whitespace);
    size_t end = s.find_last_not_of(whitespace);
    if (start == std::string::npos)
        s.clear();
    else
        s = s.substr(start, end - start + 1);
}

// Convert a string to a double, throwing an exception if the conversion fails
double BitcoinExchange::stringToDouble(const std::string &str) const {
    std::stringstream strstr;
    double value;
    strstr << str;
    strstr >> value;
    if (strstr.fail() || !strstr.eof())
        throw std::runtime_error("Error: bad input => " + str);
    return value;
}

// Get the exchange rate for a given date, throwing an exception if the date is not found
double BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
    if (it == _data.end() || (it->first != date)) {
        if (it == _data.begin())
            throw std::runtime_error("Error: no valid date found.");
        --it;
    }
    return it->second;
}

// Validate the date format (YYYY-MM-DD) and check if the year, month, and day are within valid ranges
bool BitcoinExchange::dateIsValid(const std::string &date) const {
    // Implement date validation logic (e.g., check format YYYY-MM-DD)
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    // Checks for valid year, month, day can be added here
    int year, month, day;

    // Extract year from the first 4 characters of the date string
    std::stringstream strstr(date.substr(0, 4)); // Substring replaces the contents of the existing std::stringstream with a new string built from date.substr(0, 4)
    strstr >> year; // Extract int year from string
    if (strstr.fail() || year < 0)
        return false;

    // Extract month from characters 5 and 6 of the date string
    strstr.clear(); // Clear the stringstream state
    strstr.str(date.substr(5, 2)); // Substring replaces the contents of the existing std::stringstream with a new string built from date.substr(5, 2)
    strstr >> month; // Extract int month from string
    if (strstr.fail() || month < 1 || month > 12)
        return false;

    // Extract day from characters 8 and 9 of the date string
    strstr.clear(); 
    strstr.str(date.substr(8, 2)); // Substring replaces the contents of the existing std::stringstream with a new string built from date.substr(8, 2)
    strstr >> day; // Extract int day from string
    if (strstr.fail() || day < 1 || day > 31)
        return false;
    return true;
}

// Load exchange rate data from a CSV file, storing it in the _data map
void BitcoinExchange::loadData(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    
    // Skip header
    if (!std::getline(file, line) || line != "date,exchange_rate")
    throw std::runtime_error("Error: bad database file.");

    while (std::getline(file, line)) {
        std::stringstream strstr(line);
        std::string date;
        std::string rateStr;
        if (!std::getline(strstr, date, ',') || !std::getline(strstr, rateStr))
            continue; // Skip malformed lines

        double rate = stringToDouble(rateStr);
        _data[date] = rate;
    }
}

// Process input from a file, validating the date and value, and calculating the exchange value based on the loaded data
void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str()); // c_str() converts the C++ string to a C-style string (const char*) which is required by the ifstream constructor
    if (!file.is_open()) // is_open() checks if the file was successfully opened. If it returns false, it means the file could not be opened (e.g., it doesn't exist, or there are permission issues).
        throw std::runtime_error("Error: could not open file.");

    std::string line;

    // Skip header
    if (!std::getline(file, line) || line != "date | value")
    throw std::runtime_error("Error: bad input file.");

    while (std::getline(file, line)) {
        std::string date;
        std::string valueStr;

        // Determine the delimiter (either '|' or ',') and split the line into date and value
        size_t delimPos = std::string::npos;
        char delim = '\0';
        if ((delimPos = line.find('|')) != std::string::npos)
            delim = '|';
        else if ((delimPos = line.find(',')) != std::string::npos)
            delim = ',';

        if (delim == '\0') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, delimPos);
        valueStr = line.substr(delimPos + 1);
        trim(date);
        trim(valueStr);

        if (!dateIsValid(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        try {
            double value = stringToDouble(valueStr);

            if (value < 0) {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (value > 1000) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }

            double rate = getExchangeRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } 
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}