#pragma once

#include "Contact.hpp"

#define MAX 8

class Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
		void	Add(void);
		void	Search(void);
		void	Exit(void);
	private:
		Contact contacts[MAX];
		void	FormatNPut(std::string str);
		int	inx;
		int	is_max_inx;
};
