#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	harl.complain("extrem");
	harl.complain("extrem");

	harl.complain("DEBUG");
	harl.complain("info");

	harl.complain("debug");
	harl.complain("INFO");

	harl.complain("ERROR");
	harl.complain("warning");

	harl.complain("error");
	harl.complain("WARNING");

	return (0);
}
