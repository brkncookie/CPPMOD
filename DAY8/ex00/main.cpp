#include "easyfind.hpp"

int main(void)
{
	int	ints[] = {1, 3, 6, 0};

	std::vector<int> v_ints(ints, ints + 4);

	std::vector<int>::iterator itr = easyfind(v_ints, 3);
	std::cout << *itr << std::endl;
	try
	{
		std::vector<int>::iterator itr = easyfind(v_ints, 7);
		itr++;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
