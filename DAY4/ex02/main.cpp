#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define SIZE 10

int main()
{
	std::cout << "---------TEST ALPHA---------" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete j;
	delete i;
	std::cout << "---------TEST BETA---------" << std::endl;
	Animal	*animals[SIZE];
	int inx;

	for (inx = 0; inx < (SIZE / 2); inx++)
		animals[inx] = new Cat;
	for (; inx < SIZE; inx++)
		animals[inx] = new Dog;

	for (inx = 0; inx < SIZE; inx++)
		animals[inx]->makeSound();

	for (inx = 0; inx < SIZE; inx++)
		delete animals[inx];
	std::cout << "---------TEST THETA---------" << std::endl;
	Cat	jim;
	Cat	kim;

	jim = kim;
	kim.makeSound();
	jim.makeSound();
	return 0;
}
