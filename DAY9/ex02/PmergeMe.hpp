#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <algorithm>


class PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		void	plotEm(int ac, char **av);
		void	sortEm(void);
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		void	sortDeq(void);
		void	sortVec(void);
};
