#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double> _data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void loadData(const std::string &filename);
        void processInput(const std::string &filename);

    private:
        bool dateIsValid(const std::string &date) const;
        bool valueIsValid(const std::string &value) const;
        double stringToDouble(const std::string &str) const;
        double getExchangeRate(const std::string &date) const;
};

#endif