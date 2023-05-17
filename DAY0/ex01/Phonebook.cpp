#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->inx = 0;
	this->is_max_inx = 0;
	std::cout << "Phonebook Constructor Called !" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook Destructor Called !" << std::endl;
}

void	Phonebook::Add(void)
{
	std::string	tmp;

	std::cout << "First Name: ";
	std::cin >> tmp;
	if (std::cin.eof())
		exit(0);
	this->contacts[this->inx].SetFN(tmp);
	std::cout << "Last Name: ";
	std::cin >> tmp;
	if (std::cin.eof())
		exit(0);
	this->contacts[this->inx].SetLN(tmp);
	std::cout << "Nickname: ";
	std::cin >> tmp;
	if (std::cin.eof())
		exit(0);
	this->contacts[this->inx].SetNN(tmp);
	std::cout << "Phone Number: ";
	std::cin >> tmp;
	if (std::cin.eof())
		exit(0);
	this->contacts[this->inx].SetPN(tmp);
	std::cout << "Darkest Secret: ";
	std::cin >> tmp;
	if (std::cin.eof())
		exit(0);
	this->contacts[this->inx].SetDS(tmp);
	this->inx++;
	if (this->inx == MAX)
	{
		this->inx = 0;
		this->is_max_inx = 1;
	}

}

void	Phonebook::FormatNPut(std::string str)
{
	if (str.length() > 10)
		std::cout << "|" << std::right << std::setw(10) << str.substr(0, 10).replace(9, 10, ".");
	else
		std::cout << "|" << std::right << std::setw(10) << str;
}

void	Phonebook::Search(void)
{
	int	inx;
	std::string	headers[4] = {"Index", "First Name", "Last Name", "Nickname"};

	inx = 0;
	while (inx < 4)
		std::cout << "|" << std::right << std::setw(10) << headers[inx++];
	std::cout << std::endl;

	inx = 0;
	while (inx < ((this->is_max_inx) ? MAX : this->inx))
	{
		std::cout << "|" << std::right << std::setw(10) << inx;
		FormatNPut(this->contacts[inx].GetFN());
		FormatNPut(this->contacts[inx].GetLN());
		FormatNPut(this->contacts[inx].GetNN());
		std::cout << std::endl;
		inx++;
	}
	std::cout << "Enter An Index: ";
	if (!(std::cin >> inx) || inx < 0 || inx > ((this->is_max_inx) ? (MAX - 1) : (this->inx - 1)) || (!inx && !this->inx))
	{
		if (std::cin.eof())
			exit(0);
		std::cout << "Invalid index" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	else
	{
		std::cout << "First name: " << this->contacts[inx].GetFN() << std::endl;
		std::cout << "Last name: " << this->contacts[inx].GetLN() << std::endl;
		std::cout << "Nickname: " << this->contacts[inx].GetNN() << std::endl;
		std::cout << "Phone number: " << this->contacts[inx].GetPN() << std::endl;
		std::cout << "Darkest secret: " << this->contacts[inx].GetDS() << std::endl;
	}
}

void	Phonebook::Exit(void)
{
	std::cout << "Bye !" << std::endl;
	exit(0);
}
