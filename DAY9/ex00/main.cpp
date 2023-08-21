#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
	BitcoinExchange market;

	if (argc != 2)
		return (market.throw_err(ARG_CNT, "NULL", 0), 1);
	market.calculate_input(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
