#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || !(*argv[1]))
		return (std::cout << "Usage: " << argv[0] << " scalartype" << std::endl, 1);
	std::string str(argv[1]);
	ScalarConverter scalarconverter;
	scalarconverter.convert(str);
	std::cout << INT_MAX << std::endl;
	return (0);
}
