#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "MyException.h"
#include "MyDeliveredException.h"

using namespace std;

class Pair
{
private:
	int x;
	int y;

public:
	Pair();
	Pair(const int valueX, const int valueY) throw(invalid_argument);
	Pair(const Pair& p);
	~Pair() {}

	int GetX() const { return x; }
	int GetY() const { return y; }
	void SetX(int value) throw(invalid_argument);
	void SetY(int value) throw(invalid_argument);

	friend bool operator == (const Pair& p1, const Pair& p2);
	friend bool operator != (const Pair& p1, const Pair& p2);
	friend bool operator > (const Pair& p1, const Pair& p2);
	friend bool operator < (const Pair& p1, const Pair& p2);
	friend bool operator >= (const Pair& p1, const Pair& p2);
	friend bool operator <= (const Pair& p1, const Pair& p2);

	Pair& operator = (const Pair& p);
	operator string() const;
	friend ostream& operator << (ostream&, const Pair&);
	friend istream& operator >> (istream&, Pair&) throw (MyDeliveredException);
};