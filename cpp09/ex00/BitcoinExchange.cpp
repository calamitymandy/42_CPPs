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

double BitcoinExchange::stringToDouble(const std::string &str) const {
    std::stringstream strstr ;
    double value;
    strstr << str; // Insert the string into the stringstream
    strstr >> value; // Extract the double value from the stringstream
    if (strstr.fail() || !strstr.eof())
        throw std::runtime_error("Error"); // If the conversion fails or there are extra characters, throw an error
    return value;
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _data.lower_bound(date); // Find the first element that is not less than the given date
    if (it == _data.end() || (it->first != date)) { // If the date is not found, we need to check the previous date
        if (it == _data.begin()) // If the date is before the first entry in the map, we cannot find an exchange rate
            throw std::runtime_error("Error: no valid date found.");
        --it; // Move the iterator back to the previous date, which is the closest date before the given date
    }
    return it->second; // Return the exchange rate for the found date
}

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

void BitcoinExchange::loadData(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // Skip header
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

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        // Process each line of the input file
        std::stringstream strstr(line);
        std::string date;
        std::string valueStr;
        if (!std::getline(strstr, date, '|') || !std::getline(strstr, valueStr)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue; // Skip malformed lines
        }
        // Trim whitespace
        if (!date.empty() && date[date.length() - 1] == ' ')
            date.erase(date.length() - 1);
        if (!valueStr.empty() && valueStr[0] == ' ')
            valueStr.erase(0, 1);

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
        catch (...) {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
}