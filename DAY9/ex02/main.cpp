#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
	{
	PmergeMe pmm;

	pmm.plotEm(argc, argv);
	pmm.sortEm();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
