#include "Base.hpp"

Base	*generate(void)
{
	std::srand(std::time(0));
	int	destiny = std::rand() % 12;

	if (destiny / 1 == destiny % 2)
		return (new A);
	else if (destiny * 2 > 10) 
		return (new B);

	return (new C);
}
	

void	identify(Base *p)
{
	if (!p)
		return ;
	if (dynamic_cast<A *>(p))
		std::cout << "Class Type is: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class Type is: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class Type is: C" << std::endl;
	else
		std::cout << "Unknown Type !" << std::endl;
}


void	identify(Base &p)
{
	Base	r;
	try 
	{
		r = dynamic_cast<A &>(p);
		std::cout << "Class Type is: A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{

	}

	try 
	{
		r = dynamic_cast<B &>(p);
		std::cout << "Class Type is: B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{

	}

	try 
	{
		r = dynamic_cast<C &>(p);
		std::cout << "Class Type is: C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << "Unknown Type !" << std::endl;
	}
}
