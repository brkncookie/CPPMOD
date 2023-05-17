#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int			fxd_point_num;
		static const int	fraction = 8;
	public:
		Fixed(void);
		Fixed(const Fixed	&tocpy);
		Fixed(const int		le_int);
		Fixed(const float	le_float);
		~Fixed(void);
		Fixed	&operator=(const Fixed	&tocpy);
		int	getRawBits(void) const;
		void	setRawBits(const int	raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream	&operator<<(std::ostream &output, const Fixed &src);
