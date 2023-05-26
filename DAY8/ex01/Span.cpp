#include "Span.hpp"

Span::Span(void): N(0), ints(), shortestspan(-1), longestspan(-1) {}

Span::~Span(void) {}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span::Span(unsigned int n): N(n), ints(), shortestspan(-1), longestspan(-1) {}

Span	&Span::operator=(const Span &obj)
{
	this->N = obj.N;
	this->shortestspan = obj.shortestspan;
	this->longestspan = obj.longestspan;
	for (unsigned int inx = 0; inx < N; inx++)
		this->ints[inx] = obj.ints[inx];
	return (*this);
}

void	Span::addNumber(int num)
{
	if ((unsigned int)ints.size() < N)
		ints.push_back(num);
	else
		throw Span::SpanIsFull();
	if (ints.size() > 2)
	{
		std::vector<int> sorted = this->ints;
		std::sort(sorted.begin(), sorted.end());

		this->longestspan = sorted.back() - sorted.front();
		this->shortestspan = sorted[1] - sorted[0];
	}
}

void	Span::addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((unsigned int)ints.size() + (end - begin) > this->N)
		throw Span::SpanIsFull();
	while (begin != end)
		this->addNumber(*(begin++));
}

int	Span::shortestSpan(void)
{
	if (shortestspan == -1)
		throw Span::SpanIsEmpty();
	return (shortestspan);
}

int	Span::longestSpan(void)
{
	if (longestspan == -1)
		throw Span::SpanIsEmpty();
	return (longestspan);
}

const char * Span::SpanIsFull::what(void) const throw()
{
	return ("Span is full !");
}

const char * Span::SpanIsEmpty::what(void) const throw()
{
	return ("Span is empty !");
}
