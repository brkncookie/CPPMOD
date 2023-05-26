#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> ints;
		int shortestspan;
		int longestspan;
	public:
		~Span(void);
		Span(void);
		Span(unsigned int n);
		Span(const Span &obj);
		Span &operator=(const Span &obj);

		void	addNumber(int n);
		int	shortestSpan(void);
		int	longestSpan(void);
		void	addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		class SpanIsFull: public std::exception
		{
			const char *what(void) const throw();
		};
		class SpanIsEmpty: public std::exception
		{
			const char *what(void) const throw();
		};
};
