#pragma once

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &obj);
		const Brain	&operator=(const Brain &obj);
};
