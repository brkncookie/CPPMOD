#include <stack>
#include <iostream>

class RPN
{
	private:
			std::stack<int> oprnds;
			bool			parse(std::string &exp);
			void			push_oprnd(char	c);
			void			exec_operator(char c);
	public:
			RPN(void);
			~RPN(void);
			RPN(const RPN &obj);
			RPN	&operator=(const RPN &obj);

			void	rpn_magic(std::string exp);
};
