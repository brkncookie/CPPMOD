#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T> typename T::iterator easyfind(T &container, int content)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), content);

	if (itr == container.end())
			throw std::out_of_range("element not found !");
	return (itr);
}
