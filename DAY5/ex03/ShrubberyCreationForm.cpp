#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm(145, 137, "ShrubberyCreationForm"), target("defacto")
{
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(145, 137, "ShrubberyCreationForm"), target(target)
{
	std::cout << "ShrubberyCreationForm Target Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj), target(obj.target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	this->target = obj.target;
	std::cout << "ShrubberyCreationForm Copy Assignment Operator Called" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::doAction(void) const
{
	std::ofstream file_out;
	file_out.open((this->target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	if (!file_out.is_open())
		throw std::ofstream::failure("Failed To Open");
	file_out << "              ,@@@@@@@,\n";
	file_out << "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file_out << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file_out << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file_out << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file_out << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file_out << "  `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file_out << "      |o|        | |         | |\n";
	file_out << "      |.|        | |         | |\n";
	file_out << "   \\\\/ ._\\//_/__/  ,\\\\_//__\\\\/.  \\_//__/_\n";
	file_out.close();
}
