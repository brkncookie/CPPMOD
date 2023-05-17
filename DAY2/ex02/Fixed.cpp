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

Fixed::Fixed(const int le_int): fxd_point_num(le_int << fraction)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float le_float): fxd_point_num(roundf(le_float * (float)(1 << fraction)))
{
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (this->fxd_point_num >> this->fraction);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fxd_point_num / (float)(1 << this->fraction));
}

bool	Fixed::operator>(const Fixed	&obj) const
{
	return (this->toFloat() > obj.toFloat());
}


bool	Fixed::operator<(const Fixed	&obj) const
{
	return (this->toFloat() < obj.toFloat());
}


bool	Fixed::operator<=(const Fixed	&obj) const
{
	return (this->toFloat() <= obj.toFloat());
}

bool	Fixed::operator>=(const Fixed	&obj) const
{
	return (this->toFloat() >= obj.toFloat());
}


bool	Fixed::operator!=(const Fixed	&obj) const
{
	return (this->toFloat() != obj.toFloat());
}


bool	Fixed::operator==(const Fixed	&obj) const
{
	return (this->toFloat() == obj.toFloat());
}

Fixed	Fixed::operator+(const Fixed	&obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator-(const Fixed	&obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}


Fixed	Fixed::operator/(const Fixed	&obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}


Fixed	Fixed::operator*(const Fixed	&obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator++(void)
{
	return (this->fxd_point_num++, *this);
}

Fixed	Fixed::operator++(int i)
{
	(void) i;
	Fixed old(*this);
	return (this->fxd_point_num++, old);
}

Fixed	Fixed::operator--(void)
{
	return (this->fxd_point_num--, *this);
}

Fixed	Fixed::operator--(int i)
{
	(void) i;
	Fixed old(*this);
	return (this->fxd_point_num--, old);
}

const Fixed	&Fixed::max(const Fixed	&obj1, const Fixed	&obj2)
{
	return (obj1 >= obj2 ? obj1 : obj2);
}

Fixed	&Fixed::max(Fixed	&obj1, Fixed	&obj2)
{
	return (obj1 >= obj2 ? obj1 : obj2);
}

const Fixed	&Fixed::min(const Fixed	&obj1, const Fixed	&obj2)
{
	return (obj1 <= obj2 ? obj1 : obj2);
}

Fixed	&Fixed::min(Fixed	&obj1, Fixed	&obj2)
{
	return (obj1 <= obj2 ? obj1 : obj2);
}

std::ostream	&operator<<(std::ostream &output, const Fixed &src)
{
	return(output << src.toFloat());
}
