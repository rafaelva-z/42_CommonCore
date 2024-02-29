#include "Fixed.hpp"

// ex02


Fixed::Fixed(const int &n)
{
	std::cout << "Int constructor called " << "i: " << n << std::endl;
	_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float &n)
{
	std::cout << "Float constructor called " << "i: " << n << std::endl;
	_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (_fixedPointValue / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	return (os << f.toFloat());
}

//ex01

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = copy._fixedPointValue;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedPointValue = copy._fixedPointValue;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const &raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}
