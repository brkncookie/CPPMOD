#include <iostream>

void	yell(char	**strs)
{
	int	inx;
	int	jnx;
	std::string	tmp;

	inx = -1;
	while (strs[++inx] && (jnx = -1))
	{
		tmp = strs[inx];
		while(tmp[++jnx])
			std::cout << (char)std::toupper(tmp[jnx]);
	}
}

int	main(int argc, char **argv)
{
	(argc < 2) ? (void)(std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *") : yell(&argv[1]);
	return(std::cout << std::endl, 0);
}
