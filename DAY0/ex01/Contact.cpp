#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact Constructor Called !" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact Destructor Called !" << std::endl;
}

std::string	Contact::GetFN(void)
{
	return (this->fn);
}

std::string	Contact::GetLN(void)
{
	return (this->ln);
}


std::string	Contact::GetNN(void)
{
	return (this->nn);
}


std::string	Contact::GetPN(void)
{
	return (this->pn);
}


std::string	Contact::GetDS(void)
{
	return (this->ds);
}

void	Contact::SetFN(std::string str)
{
	this->fn = str;
}

void	Contact::SetLN(std::string str)
{
	this->ln = str;
}

void	Contact::SetNN(std::string str)
{
	this->nn = str;
}

void	Contact::SetPN(std::string str)
{
	this->pn = str;
}

void	Contact::SetDS(std::string str)
{
	this->ds = str;
}
