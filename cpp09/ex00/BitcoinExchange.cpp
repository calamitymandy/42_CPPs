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

void BitcoinExchange::loadData(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open database file: " + filename);

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::stringstream strstr(line);
        std::string date;
        std::string rateStr;
        if (!std::getline(strstr, date, ',') || !std::getline(strstr, rateStr))
            continue; // Skip malformed lines

            double rate = std::atof(rateStr.c_str());
            _data[date] = rate;
    }
}