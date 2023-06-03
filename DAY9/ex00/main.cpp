#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange market;

	if (argc != 2)
		return (market.throw_err(ARG_CNT, "NULL", 0), 1);
	market.calculate_input(argv[1]);
	return (0);
}
