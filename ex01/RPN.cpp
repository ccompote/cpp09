#include "RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN(void) {}

RPN::RPN(std::string &expression) : _expression(expression) {}


int RPN::evaluate() 
{
	std::istringstream iss(_expression);
	std::string token;

	while (iss >> token) 
	{
		if (!isOperator(token)) 
		{
			int num;
			if (std::istringstream(token) >> num) 
				_numbers.push(num);
			else
				return -1; // Invalid input token
		}
		else 
		{
			if (_numbers.size() < 2)
				return -1; // Insufficient operands for the operator
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
					return -1; // Division by zero
				_numbers.push(operand1 / operand2);
			}
		}
	}

	if (_numbers.size() != 1)
		return -1; // More than one number left on the stack
	return _numbers.top();
}

bool RPN::isOperator(std::string &token) const 
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}
