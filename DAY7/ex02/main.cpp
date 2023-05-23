#include "Array.hpp"

int main(void)
{
	{
		Array<int> ints0(5);

		std::cout << ints0.size() << std::endl;
		ints0[3] = 666;
		std::cout << ints0[3] << std::endl;

		Array<int> ints1(ints0);
		ints1[3] = 333;
		std::cout << ints1[3] << std::endl;
		std::cout << ints0[3] << std::endl;
	}
	{
		Array<int> ints1;
		try
		{
			std::cout << ints1[3] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
