#include "RPN.hpp"

RPN::RPN(void){}

RPN::~RPN(void){}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN	&RPN::operator=(const RPN &obj)
{
	this->oprnds = obj.oprnds;
	return (*this);
}

void	RPN::rpn_magic(std::string	exp)
{
	size_t inx;
	if (!this->parse(exp))
	{
		std::cout << "Error." << std::endl;
		return ;
	}

	inx = 0;
	while(inx < exp.length())
	{
		if (std::isdigit(exp[inx]))
			this->push_oprnd(exp[inx]);
		else if (exp[inx] == '*' || exp[inx] == '+' || exp[inx] == '-' || exp[inx] == '/')
			this->exec_operator(exp[inx]);
		inx++;
	}

	if (this->oprnds.size() != 1)
	{
		std::cout << "Error." << std::endl;
		return ;
	}
	else if(!this->oprnds.empty())
		std::cout << this->oprnds.top() << std::endl;
}

/* private methods */

bool	RPN::parse(std::string	&exp)
{
	size_t	inx;
	int	n_oprnds;
	int	n_oprtrs;

	inx = 0;
	n_oprnds = 0;
	n_oprtrs = 0;
	while(inx < exp.length() && std::isspace(exp[inx]))
		inx++;

	if (exp[inx] == '*' || exp[inx] == '+' || exp[inx] == '-' || exp[inx] == '/')
		return (false);

	while(inx < exp.length())
	{
		if (std::isspace(exp[inx]))
		{
			inx++;
			continue;
		}
		else if (!std::isdigit(exp[inx]) && \
				!(exp[inx] == '*' || exp[inx] == '+' || exp[inx] == '-' || exp[inx] == '/'))
			return (false);
		else if ((((inx + 1) < exp.length()) && !std::isspace(exp[inx + 1])) \
				|| (inx != 0 && !std::isspace(exp[inx - 1])))
			return (false);
		if (exp[inx] == '*' || exp[inx] == '+' || exp[inx] == '-' || exp[inx] == '/')
			n_oprtrs++;
		else if (std::isdigit(exp[inx]))
			n_oprnds++;
		inx++;
	}

	if ((n_oprnds == 1 && n_oprtrs) || (!n_oprnds && n_oprtrs))
		return (false);
	return (true);
}

void	RPN::push_oprnd(char c)
{
		int num = c - 48;

		this->oprnds.push(num);
}

void	RPN::exec_operator(char c)
{
	int oprnd1;
	int oprnd2;
	
	if (this->oprnds.size() < 2)
		return ;
	oprnd1 = this->oprnds.top();
	this->oprnds.pop();
	oprnd2 = this->oprnds.top();
	this->oprnds.pop();
	if (c == '*')
		this->oprnds.push(oprnd1 * oprnd2);
	else if (c == '+')
		this->oprnds.push(oprnd1 + oprnd2);
	else if (c == '-')
		this->oprnds.push(oprnd2 - oprnd1);
	else if (c == '/')
		this->oprnds.push(oprnd2 / oprnd1);
}
