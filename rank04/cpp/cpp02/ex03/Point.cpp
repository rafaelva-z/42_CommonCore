#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {}
Point::Point(const float &x, const float &y) : _x(x), _y(y) {}
Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}
Point &Point::operator=(const Point &copy) {
	(void)copy;
	return *this;
}
Point::~Point(void) {}

const Fixed	Point::getX(void) const  {
	return _x;
}

const Fixed	Point::getY(void) const {
	return _y;
}