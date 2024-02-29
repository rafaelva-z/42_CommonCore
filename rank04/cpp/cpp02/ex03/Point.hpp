#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(const Point &copy);
		Point(const float &x, const float &y);
		Point(const Fixed &x, const Fixed &y);
		Point &operator=(const Point &copy);
		~Point(void);
		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
};