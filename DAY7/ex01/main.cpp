#include "iter.hpp"


int main(void)
{
	 std::string strs[] = {"welocome", "to", "heaven"};

	 int ints[] = {1, 2, 3, 4};

	iter(ints, 4, le_print);
	iter(strs, 3, le_print);
}
