#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	int	inx;

	if (argc != 4 || !(*argv[2]))
		return (std::cerr << "Usage: " << argv[0] << " filename s1 s2" << std::endl, 1);
	std::string	file(argv[1]);
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	std::string	buff;
	std::string	replc;

	std::ifstream input;
	input.open(file.c_str());
	if (input.fail())
		return (std::cerr << "Failed to open " << file << std::endl, 1);

	std::ofstream output;
	output.open((file + ".replace").c_str());
	if (output.fail())
		return (std::cerr << "Failed to open " << file << ".replace" << std::endl, 1);

	std::getline(input, buff, '\0');
	input.close();

	inx = 0;
	while (inx < int(buff.length()))
	{
		if (buff.substr(inx, s1.length()) == s1)
		{
			replc += s2;
			inx  += s1.length();
		}
		else
		{
			replc += buff[inx];
			inx++;
		}
	}

	output << replc;
	output.close();
}
