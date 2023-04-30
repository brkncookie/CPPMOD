#include <iostream>

void	yell(char	**strs)
{
	int	inx;
	int	jnx;

	inx = -1;
	while (strs[++inx] && (jnx = -1))
		while(strs[inx][++jnx])
			std::cout << (char)std::toupper(strs[inx][jnx]);
}
int	main(int argc, char **argv)
{
	(argc < 2) ? (void)(std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *") : yell(&argv[1]);
	return(std::cout << std::endl, 0);
}
