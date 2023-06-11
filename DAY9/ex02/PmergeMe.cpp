#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void): vec(), deq() {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj)
{
	this->vec = obj.vec;
	this->deq = obj.deq;
	return (*this);
}

void	PmergeMe::plotEm(int ac,  char **av)
{
	int	inx;
	int	num;
	if (ac < 2)
	{
		std::cout << "a list of numbers is needed" << std::endl;
		return ;
	}

	inx = 1;
	while(av[inx])
	{
		if (!std::isdigit(*av[inx]))
		{
			std::cout << "invalid integer is in the list" << std::endl;
			this->vec.resize(0);
			this->deq.resize(0);
			return ;
		}
		num = strtol(av[inx], NULL, 10);
		this->vec.push_back(num);
		this->deq.push_back(num);
		inx++;
	}
}

void	PmergeMe::sortEm(void)
{
	std::deque<int> before(this->deq);
	clock_t	vec_s;
	clock_t	vec_e;
	clock_t	deq_s;
	clock_t	deq_e;
	size_t	inx;

	if (this->deq.empty())
	{
		std::cout << "Array is empty, call plotEm() to plot it with numbers" << std::endl;
		return ;
	}
	vec_s = clock();
	this->sortVec();
	vec_e = clock();
	deq_s = std::clock();
	this->sortDeq();
	deq_e = std::clock();

	std::cout << "Before: " << std::endl;
	inx = 0;
	while (inx < before.size())
		std::cout << " " << before[inx++];
	std::cout << std::endl;
	std::cout << "After: " << std::endl;
	inx = 0;
	while (inx < this->deq.size())
		std::cout << " " << this->deq[inx++];
	std::cout << std::endl;
    	std::cout << "Time to process a range of " << this->deq.size() << " elements with std::vector :  " << ((double)(vec_e - vec_s) / 100000) << " us" << std::endl;
    	std::cout << "Time to process a range of " << this->deq.size() << " elements with std::deque :  " << ((double)(deq_e - deq_s) / 100000) << " us" << std::endl;
}

/* PRIVATE METHODS */

void	PmergeMe::sortVec(void)
{
	int	even;
	std::vector<std::pair<int, int> > vecof2;
	std::vector<int>::iterator itr;
	size_t	inx;

	even = this->vec.size() % 2 ? this->vec.back() : -1;
	this->vec.size() % 2 ? this->vec.pop_back() : (void)inx;

	inx = 0;
	while(inx < this->vec.size())
	{
		std::pair<int, int> two(this->vec[inx], this->vec[inx + 1]);
		if (two.first < two.second)
			std::swap(two.first, two.second);
		vecof2.push_back(two);
		inx += 2;
	}
	this->vec.resize(0);
	std::sort(vecof2.begin(), vecof2.end());
	inx = 0;
	while(inx < vecof2.size())
		this->vec.push_back(vecof2[inx++].first);
	inx = 0;
	while(inx < vecof2.size())
		(itr = std::upper_bound(this->vec.begin(), this->vec.end(), vecof2[inx].second), this->vec.insert(itr, vecof2[inx++].second));
	if (even != -1)
		(itr = std::upper_bound(this->vec.begin(), this->vec.end(), even), this->vec.insert(itr, even));
}

void	PmergeMe::sortDeq(void)
{
	int	even;
	std::deque<std::pair<int, int> > deqof2;
	std::deque<int>::iterator itr;
	size_t	inx;

	even = this->deq.size() % 2 ? this->deq.back() : -1;
	this->deq.size() % 2 ? this->deq.pop_back() : (void)inx;

	inx = 0;
	while(inx < this->deq.size())
	{
		std::pair<int, int> two(this->deq[inx], this->deq[inx + 1]);
		if (two.first < two.second)
			std::swap(two.first, two.second);
		deqof2.push_back(two);
		inx += 2;
	}
	this->deq.resize(0);
	std::sort(deqof2.begin(), deqof2.end());
	inx = 0;
	while(inx < deqof2.size())
		this->deq.push_back(deqof2[inx++].first);
	inx = 0;
	while(inx < deqof2.size())
		(itr = std::upper_bound(this->deq.begin(), this->deq.end(), deqof2[inx].second), this->deq.insert(itr, deqof2[inx++].second));
	if (even != -1)
		(itr = std::upper_bound(this->deq.begin(), this->deq.end(), even), this->deq.insert(itr, even));
}
