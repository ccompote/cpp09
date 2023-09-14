#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
	{
        std::cerr << "Wrong arguments" << std::endl;
        return 1;
    }
	std::string expression = argv[1];
    RPN calculator(expression);
    int result = calculator.evaluate();

    if (result != -1)
        std::cout << result << std::endl;
    else
        std::cerr << "Error" << std::endl;
    return 0;
}