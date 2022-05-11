#include "Point.h"

Point::Point()
	:Pair(0, 0)
{}

Point::Point(const int valueX, const int valueY)
	: Pair(valueX, valueY)
{}

Point::Point(const Point& p)
	: Pair(p)
{}

double Point::Angle()
{
	double Pi = 4. * atan(1);
	if ((GetX() == 0) && (GetY() == 0))
		return -1;
	if (GetX() == 0)
		return ((GetY() > 0) ? 90 : 270);
	double theta = atan(GetY() / GetX());
	theta *= 360 / (2 * Pi);
	if (GetX() > 0)
	{
		return ((GetY() >= 0) ? theta : 360 + theta);
	}
	else
	{
		return (180 + theta);
	}
}

double Point::Origin()
{
	double z;
	z = sqrt((GetX() * GetX()) + (GetY() * GetY()));
	return z;
}

Point& Point::operator++() throw(MyException)
{
	if ((GetX() + 1) == 101)
		throw MyException("x > 100");
	SetX(GetX() + 1);
	return *this;
}

Point& Point::operator--() throw(MyException)
{
	if ((GetX() - 1) == -101)
		throw MyException("x < -100");
	SetX(GetX() - 1);
	return *this;
}

Point Point::operator++(int) throw(MyException)
{
	Point a(*this);
	if ((GetY() + 1) == 101)
		throw MyException("y > 100");
	SetY(GetY() + 1);
	return a;
}

Point Point::operator--(int) throw(MyException)
{
	Point a(*this);
	if ((GetY() - 1) == -101)
		throw MyException("y < -100");
	SetY(GetY() - 1);
	return a;
}