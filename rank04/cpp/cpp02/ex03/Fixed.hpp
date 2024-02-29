#pragma once
#include "Fixed.hpp"
#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const &raw);

		// ex01
		Fixed(const int &n);
		Fixed(const float &n);
		float	toFloat(void) const;
		int		toInt(void) const;

		// ex02
		bool				operator>(const Fixed &f) const;
		bool				operator<(const Fixed &f) const;
		bool				operator>=(const Fixed &f) const;
		bool				operator<=(const Fixed &f) const;
		bool				operator==(const Fixed &f) const;
		bool				operator!=(const Fixed &f) const;
		Fixed				operator+(const Fixed &f) const;
		Fixed				operator-(const Fixed &f) const;
		Fixed				operator*(const Fixed &f) const;
		Fixed				operator/(const Fixed &f) const;
		Fixed				operator++(void);
		Fixed				operator++(int);
		Fixed				operator--(void);
		Fixed				operator--(int);
		static const Fixed	&max(const Fixed &f, const Fixed &f2);
		static Fixed		&max(Fixed &f, Fixed &f2);
		static const Fixed	&min(const Fixed &f, const Fixed &f2);
		static Fixed		&min(Fixed &f, Fixed &f2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);
