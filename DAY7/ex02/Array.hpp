#pragma once

#include <iostream>
#include <cstdlib>

template <typename T> class Array
{
	private:
		T	*ptr;
		size_t	sze;
	public:
		Array(void): ptr(NULL), sze(0) {}

		Array(unsigned int n)
		{
			unsigned int	inx;

			this->sze = n;
			ptr = new T[sze];
			inx = 0;
			while (inx < n)
				ptr[inx++] = T();
		}

		Array(const Array<T> &obj): ptr(NULL), sze(0)
		{
			*this = obj;
		}

		Array	&operator=(const Array<T> &obj)
		{
			size_t inx;

			if (this->ptr)
				delete[] this->ptr;
			this->sze = obj.sze;
			if (!sze)
				return (*this);
			ptr = new T[this->sze];

			inx = 0;
			while(inx < this->sze)
			{
				this->ptr[inx] = obj.ptr[inx];
				inx++;
			}
			return (*this);
		}

		T	&operator[](size_t inx)
		{
			if (inx > sze)
				throw std::out_of_range("stay in da range dummmy");
			return (this->ptr[inx]);
		}
		~Array(void)
		{
			if (this->ptr)
				delete[] this->ptr;
		}

		size_t	size(void) const
		{
			return (this->sze);
		}
};
