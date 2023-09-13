#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
	private:

		std::map<std::string, float> _bitcoinPrices;

	public:

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange(void);

		int opencsv(std::string filename);
		int readinputfile(char *filename);
};