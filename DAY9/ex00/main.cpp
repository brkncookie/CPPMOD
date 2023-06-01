#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange market;

	try
	{
		if (argc != 2)
			market.throw_err(ARG_CNT, NULL, 0);
		market.calculate_input(argv[1]);
	}
	catch (const char *err)
	{
		std::cout << err << std::endl;
	}
}
