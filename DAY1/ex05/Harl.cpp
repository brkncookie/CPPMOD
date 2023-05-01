#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
    std::cout << "#DEBUG#" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "#INFO#" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "#WARNING#" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "#ERROR#" << std::endl << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int inx = -1;

	ptr2method	pm[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvls[4] = {"debug", "info", "warning", "error"};

	while(++inx < int(level.length()))
		level[inx] = tolower(level[inx]);

	inx = 0;
	while(inx < 4 && lvls[inx] != level)
		inx++;
	if (inx < 4)
		(this->*pm[inx])();
	else
		std::cout << "We handle too many complaints already, i'mma just ignore this one for now" << std::endl;
}
