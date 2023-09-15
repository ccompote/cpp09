#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
	{
        std::cerr << "Wrong arguments" << std::endl;
        return 1;
    }
	try
	{

		std::string expression = argv[1];
		RPN calculator(expression);
		calculator.evaluate();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}