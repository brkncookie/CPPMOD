#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class NoEelement: public std::exception
{
	const char	*what(void) const throw();
};

template <typename T> typename T::iterator easyfind(T &container, int content)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), content);

	if (itr == container.end())
		throw NoEelement();
	return (itr);
}
