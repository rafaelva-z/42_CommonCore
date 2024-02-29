#include "Fixed.hpp"
#include <cmath>

// ex03

//	Comparison operators
bool	Fixed::operator>(const Fixed &f) const
{
	std::cout << "Comparison operator called '>'" << std::endl;
	return (_fixedPointValue > f._fixedPointValue);
}

bool	Fixed::operator<(const Fixed &f) const
{
	std::cout << "Comparison operator called '<'" << std::endl;
	return (_fixedPointValue < f._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &f) const
{
	std::cout << "Comparison operator called '>='" << std::endl;
	return (_fixedPointValue >= f._fixedPointValue);
}

bool	Fixed::operator<=(const Fixed &f) const
{
	std::cout << "Comparison operator called '<='" << std::endl;
	return (_fixedPointValue <= f._fixedPointValue);
}

bool	Fixed::operator==(const Fixed &f) const
{
	std::cout << "Comparison operator called '=='" << std::endl;
	return (_fixedPointValue == f._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &f) const
{
	std::cout << "Comparison operator called '!='" << std::endl;
	return (_fixedPointValue != f._fixedPointValue);
}

//	Arithmetic operators
Fixed	Fixed::operator+(const Fixed &f) const
{
	std::cout << "Arithmetic operator called '+'" << std::endl;
	return (Fixed(toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	std::cout << "Arithmetic operator called '-'" << std::endl;
	return (Fixed(toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	std::cout << "Arithmetic operator called '*'" << std::endl;
	return (Fixed(toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	std::cout << "Arithmetic operator called '/'" << std::endl;
	return (Fixed(this->toFloat() / f.toFloat()));
}

// min max
const Fixed	&Fixed::max(const Fixed &f, const Fixed &f2)
{
	std::cout << "max member function called" << std::endl;
	return (f > f2 ? f : f2);
}

Fixed	&Fixed::max(Fixed &f, Fixed &f2)
{
	std::cout << "max member function called" << std::endl;
	return (f > f2 ? f : f2);
}

const Fixed	&Fixed::min(const Fixed &f, const Fixed &f2)
{
	std::cout << "min member function called" << std::endl;
	return (f < f2 ? f : f2);
}

Fixed	&Fixed::min(Fixed &f, Fixed &f2)
{
	std::cout << "min member function called" << std::endl;
	return (f < f2 ? f : f2);
}

//	Increment and decrement operators

Fixed	Fixed::operator++(void)
{
	std::cout << "Increment operator called '++this'" << std::endl;
	_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	std::cout << "Increment operator called 'this++'" << std::endl;
	Fixed tmp(*this);
	_fixedPointValue++;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	std::cout << "Decrement operator called '--this'" << std::endl;
	_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	std::cout << "Decrement operator called 'this--'" << std::endl;
	Fixed tmp(*this);
	_fixedPointValue--;
	return (tmp);
}

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
