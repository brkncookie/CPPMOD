#pragma once

#include <iostream>

template <typename T> void iter(T *ptr, size_t sze, void (*fnc)(T &))
{
	size_t inx = 0;

	while (inx < sze)
	{
		fnc(ptr[inx]);
		inx++;
	}
}

template <typename T> void iter(const T *ptr, size_t sze, void (*fnc)(const T &))
{
	size_t inx = 0;

	while (inx < sze)
	{
		fnc(ptr[inx]);
		inx++;
	}
}

template <typename T> void le_print(T &elem)
{
	std::cout << elem << std::endl;
}
