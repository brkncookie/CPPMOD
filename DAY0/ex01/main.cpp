#include "Phonebook.hpp"

int	main(void)
{
	Phonebook pb;
	std::string inp;


	std::cout << "CMDS:" << std::endl;
	std::cout << "ADD	" << "Adds A Contact " << std::endl;
	std::cout << "SEARCH	" << "Search Through Contacts" << std::endl;
	std::cout << "EXIT	" << "Says Bye And Exit" << std::endl;

	while(true)
	{
		std::cout << "Enter a CMD:";
		std::cin >> inp;
		if (std::cin.eof())
			exit(0);
		if (inp == "ADD")
			pb.Add();
		else if (inp == "SEARCH")
			pb.Search();
		else if (inp == "EXIT")
			pb.Exit();
		else
		{
			std::cout << "Invalid CMD" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
	return (0);
}
