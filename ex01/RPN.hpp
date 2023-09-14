#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN
{
	private:

		std::string _expression;
		std::stack<int> _numbers;

	public:

		RPN(void);
		RPN(std::string &expression);
		~RPN(void);
		int evaluate();
		bool isOperator(std::string &token) const;

};