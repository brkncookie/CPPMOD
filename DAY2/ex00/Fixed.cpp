#include "Fixed.hpp"

Fixed::Fixed(void): fxd_point_num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &tocpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = tocpy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &tocpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fxd_point_num = tocpy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fxd_point_num);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fxd_point_num = raw;
}
