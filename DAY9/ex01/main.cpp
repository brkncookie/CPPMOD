#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN	rpn;
	if (argc != 2)
	{
		std::cout << "./RPN 'rpn expression'" << std::endl;
		return (1);
	}
	rpn.rpn_magic(argv[1]);
	return (0);
}
