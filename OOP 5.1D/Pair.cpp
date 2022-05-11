#include "Pair.h"

Pair::Pair()
{
	x = 0;
	y = 0;
}

Pair::Pair(const int valueX, const int valueY) throw(invalid_argument)
{
	if (abs(valueX) > 100 || abs(valueY) > 100)
		throw invalid_argument("value > 100 || value < 100");
	x = valueX;
	y = valueY;
}

Pair::Pair(const Pair& p)
{
	x = p.x;
	y = p.y;
}

void Pair::SetX(int value) throw(invalid_argument)
{
	if (abs(value) > 100)
		throw invalid_argument("value > 100 || value < 100");
	x = value;
}

void Pair::SetY(int value) throw(invalid_argument)
{
	if (abs(value) > 100)
		throw invalid_argument("value > 100 || value < 100");
	y = value;
}

Pair& Pair::operator=(const Pair& p)
{
	x = p.x;
	y = p.y;
	return *this;
}

Pair::operator string() const
{
	stringstream ss;
	ss << "x = " << x << endl;
	ss << "y = " << y << endl;
	return ss.str();
}

bool operator==(const Pair& p1, const Pair& p2)
{
	return ((p1.x == p2.x) && (p1.y == p2.y));
}

bool operator!=(const Pair& p1, const Pair& p2)
{
	return !(p1 == p2);
}

bool operator>(const Pair& p1, const Pair& p2)
{
	return ((p1.x > p2.x) || ((p1.x == p2.x) && (p1.y > p2.y)));
}

bool operator<(const Pair& p1, const Pair& p2)
{
	return ((p1.x < p2.x) || ((p1.x == p2.x) && (p1.y < p2.y)));
}

bool operator>=(const Pair& p1, const Pair& p2)
{
	return !(p1 < p2);
}

bool operator<=(const Pair& p1, const Pair& p2)
{
	return !(p1 > p2);
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << string(p);
	return out;
}

istream& operator >> (istream& input, Pair& m) throw (MyDeliveredException)
{
	cout << " x = "; input >> m.x;
	cout << " y = "; input >> m.y;
	cout << endl;

	if (abs(m.x) > 100 || abs(m.y) > 100)
		throw new MyDeliveredException();


	return input;
}