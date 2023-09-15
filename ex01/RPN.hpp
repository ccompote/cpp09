#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>

class RPN
{
	private:

		std::string _expression;
		std::stack<int> _numbers;

	public:

		RPN(void);
		RPN(std::string &expression);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN(void);

		void evaluate();
		bool isOperator(std::string &token) const;

};