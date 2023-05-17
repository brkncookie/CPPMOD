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

		bool	operator>(const Fixed	&obj) const;
		bool	operator<(const Fixed	&obj) const;
		bool	operator<=(const Fixed	&obj) const;
		bool	operator>=(const Fixed	&obj) const;
		bool	operator==(const Fixed	&obj) const;
		bool	operator!=(const Fixed	&obj) const;

		Fixed	&operator=(const Fixed	&tocpy);
		Fixed	operator+(const Fixed	&obj) const;
		Fixed	operator-(const Fixed	&obj) const;
		Fixed	operator/(const Fixed	&obj) const;
		Fixed	operator*(const Fixed	&obj) const;

		Fixed	operator++(int	i);
		Fixed	operator++(void);

		Fixed	operator--(int	i);
		Fixed	operator--(void);

		int	getRawBits(void) const;
		void	setRawBits(const int	raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static const Fixed	&max(const Fixed	&obj1, const Fixed	&obj2);
		static Fixed		&max(Fixed	&obj1, Fixed	&obj2);
		static const Fixed	&min(const Fixed	&obj1, const Fixed	&obj2);
		static Fixed		&min(Fixed	&obj1, Fixed	&obj2);
};

std::ostream	&operator<<(std::ostream &output, const Fixed &src);
