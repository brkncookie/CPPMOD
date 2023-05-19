#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm(const std::string  &target);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		void	doAction(void) const;
};
