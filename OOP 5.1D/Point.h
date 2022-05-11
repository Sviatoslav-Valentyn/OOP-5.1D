#pragma once
#include"Pair.h"

class Point : public Pair
{
public:
	Point();
	Point(const int valueX, const int valueY);
	Point(const Point& p);
	~Point() {}

	Point& operator ++() throw(MyException);
	Point& operator --() throw(MyException);
	Point operator ++(int) throw(MyException);
	Point operator --(int) throw(MyException);

	double Angle();
	double Origin();
};