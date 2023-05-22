#pragma once

#include <iostream>

template <typename T>
void	swap(T	&i,	T &j)
{
	T swp = i;
	i = j;
	j = swp;
}

template <typename T>
T	min(T	&i,	T &j)
{
	return (i < j ? i : j);
}

template <typename T>
T	max(T	&i,	T &j)
{
	return (i > j ? i : j);
}
