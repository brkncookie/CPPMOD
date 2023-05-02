#pragma once

#include <iostream>
#include <string>

class Fixed
{
	private:
		int			fxd_point_num;
		static const int	fraction = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &tocpy);
		~Fixed(void);
		void operator=(const Fixed &tocpy);
		int getRawBits(void) const;
		void setRawBits(const int raw);
};
