#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    if (argc < 2) 
	{
        std::cerr << "Error: Wrong arguments" << std::endl;
        return 1;
    }
	std::vector<int> input;
    for (int i = 1; i < argc; i++)
	{
        int num = std::atoi(argv[i]);
		if (num < 0)
		{
			std::cerr << "Error: Integers must be positive" << std::endl;
			return (1);
		}
        input.push_back(num);
    }
	try
	{
		Pmerge sorter(input);
		sorter.result();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
    return 0;
}