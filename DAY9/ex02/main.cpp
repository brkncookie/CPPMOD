#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe pmm;

	pmm.plotEm(argc, argv);
	pmm.sortEm();
	return (0);
}
