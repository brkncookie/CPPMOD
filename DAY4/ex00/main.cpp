#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const WrongAnimal *wrng = new WrongCat();
	const Animal *j = new Dog();
	const Animal *i = new Cat();


	std::cout << wrng->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrng->makeSound();

	delete meta;
	delete wrng;
	delete j;
	delete i;
	return 0;
}
