#include "RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN(void) {}

RPN::RPN(std::string &expression) : _expression(expression) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

void RPN::evaluate() 
{
	std::istringstream iss(_expression);
	std::string token;

	while (iss >> token) 
	{
		if (!isOperator(token)) 
		{
			int num;
			if (std::istringstream(token) >> num && num < 10) 
				_numbers.push(num);
			else
				throw std::runtime_error("Error: wrong expression format"); 
		}
		else 
		{
			if (_numbers.size() < 2)
				throw std::runtime_error("Error: wrong expression format");  
			int operand2 = _numbers.top();
			_numbers.pop();
			int operand1 = _numbers.top();
			_numbers.pop();

			if (token == "+")
				_numbers.push(operand1 + operand2);
			else if (token == "-")
				_numbers.push(operand1 - operand2);
			else if (token == "*")
				_numbers.push(operand1 * operand2);
			else if (token == "/") 
			{
				if (operand2 == 0)
					throw std::runtime_error("Error: / by zero");
				_numbers.push(operand1 / operand2);
			}
		}
	}

	if (_numbers.size() != 1)
		throw std::runtime_error("Error: wrong expression format");
	std::cout << _numbers.top() << std::endl;
}

bool RPN::isOperator(std::string &token) const 
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}
