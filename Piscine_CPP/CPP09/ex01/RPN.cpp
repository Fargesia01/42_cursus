#include "RPN.hpp"

int	compute(std::string argv)
{
	std::stack<int>		stack;
	std::istringstream	iss(argv);
	std::string		word;
	int			tmp;

	while (std::getline(iss, word, ' '))
	{
		if (!checkWord(word))
			exit(1);
		if (std::isdigit(word[0]))
			stack.push(std::atoi(word.c_str()));
		else
		{
			if (stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				exit(1);
			}
			tmp = stack.top();
			stack.pop();
			if (word[0] == '+')
				tmp += stack.top();
			else if (word[0] == '-')
				tmp = stack.top() - tmp;
			else if (word[0] == '*')
				tmp *= stack.top();
			else if (word[0] == '/')
				tmp = stack.top() / tmp;
			stack.pop();
			stack.push(tmp);
		}
	}
	if (stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	return (stack.top());
}

bool	checkWord(std::string word)
{
	if (word.length() != 1)
	{
		std::cout << "Error" << std::endl;
		return (false);
	}
	if (!std::isdigit(word[0]) && word[0] != '+' && word[0] != '-' && word[0] != '*' && word[0] != '/')
	{
		std::cout << "Error" << std::endl;
		return (false);
	}
	return (true);
}
