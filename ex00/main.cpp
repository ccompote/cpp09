#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange btc;
		btc.opencsv("data.csv");
		btc.readinputfile(argv[1]);
		return (0);
	}
	std::cerr << "Invalid arguments" << std::endl;
	return (1);
}