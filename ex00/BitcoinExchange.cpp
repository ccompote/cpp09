#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}
BitcoinExchange::~BitcoinExchange(void) {}

int BitcoinExchange::opencsv(std::string filename)
{
	const char *ffile = filename.c_str();
	std::ifstream rates(ffile);
	if (!rates)
	{
		std::cerr << "Error opening the csv file" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(rates, line))
	{
		std::string date;
		float value;
		std::istringstream iss(line);
		if (std::getline(iss, date, ',') && iss >> value)
		{
			_bitcoinPrices[date] = value;
		}
	}
	rates.close();
	return (0);
}

int BitcoinExchange::readinputfile(char *filename)
{
	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Error opening the input file" << std::endl;
		return 1;
	}
	inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    if (fileSize == 0) {
        std::cerr << "Error: input file is empty." << std::endl;
        inputFile.close();
        return 1;
    }

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string inputdate;
		float inputvalue;
		std::istringstream iss(line);
        if (line == "date | value")
			continue;
		if ((std::getline(iss, inputdate, '|') && iss >> inputvalue))
		{
			if (inputvalue < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			else if (inputvalue >= 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			std::map<std::string, float>::iterator it = _bitcoinPrices.lower_bound(inputdate);
			if (it == _bitcoinPrices.begin())
				std::cerr << "Error: no data available for date " << inputdate << std::endl;
			else
			{
				--it;
				float bitcoinPrice = it->second;
				float result = inputvalue * bitcoinPrice;
				std::cout << inputdate << " => " << inputvalue << " = " << result << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
            continue;
		}		
	}
	inputFile.close();
	return (0);
}