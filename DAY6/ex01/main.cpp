#include "Serializer.hpp"

int main(void)
{
	Data d = 
	{
		.x  = 'a'
	};

	std::cout << d.x << std::endl;
	std::cout << &d << std::endl;
	std::cout << "0x" << std::hex << Serializer::serialize(&d) << std::endl;
	std::cout << Serializer::deserialize(Serializer::serialize(&d))->x << std::endl;
}
