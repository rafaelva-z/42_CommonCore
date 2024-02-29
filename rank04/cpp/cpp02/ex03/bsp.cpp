#include "bsp.hpp"

Fixed	sideOfVector(Point point, Point vec)
{
	Fixed result(point.getX() * vec.getY() - point.getY() * vec.getX());
	std::cout << "side vector result: " << result << std::endl;
	if (result > 0)
		return (1);
	else if (result < 0)
		return (-1);
	else
		return (0);
}

Point	calculateVector(const Point& p1, const Point& p2)
{
	Point vec(p2.getX() - p1.getX(), p2.getY() - p1.getY());
	return vec;
}

Fixed	getPointBalance(Point *points, short a, short b, short &point_amount, bool &flag)
{
	Fixed balance;
	Fixed temp;

	std::cout << "a: " << a << " b: " << b << std::endl;
	for (int i = 0; i < point_amount; i++)
	{
		if (i != a && i != b)
		{
			temp = sideOfVector(calculateVector(points[a], points[i]), calculateVector(points[a], points[b]));
			if (temp == 0)
			{
				flag = true;
				return balance;
			}
			balance = balance + temp;
		}
	}
	return balance;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point triangle[3] = {a, b, c};
	Point points[4] = {a, b, c, point};
	short point_amount = 4;
	bool	flag = false;
	
	if (getPointBalance(points, 0, 1, point_amount, flag) == 0 || flag == true)
		return false;
	if (getPointBalance(points, 1, 2, point_amount, flag) == 0 || flag == true)
		return false;
	if (getPointBalance(points, 2, 0, point_amount, flag) == 0 || flag == true)
		return false;
	return true ;
}