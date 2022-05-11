#include"Point.h"
#include <Windows.h>

using namespace std;

void _unexpected_to_bad()
{
	cerr << "bad_exception" << endl;
	throw;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	set_unexpected(_unexpected_to_bad);
	set_terminate(_unexpected_to_bad);

	Point a, b;

	try
	{
		cout << "A:\n";
		cin >> a;
		cout << "Angle = " << a.Angle() << endl;
		cout << "Origin = " << a.Origin() << endl;
	}
	catch (MyDeliveredException x)
	{
		cerr << x.What() << endl;
	}

	cout << "============================================" << endl;

	try
	{
		cout << "B:\n";
		cin >> b;
		cout << "Angle = " << b.Angle() << endl;
		cout << "Origin = " << b.Origin() << endl;
		if (a == b)
		{
			cout << "Äâà îáºêòè º ð³âí³\n";
		}
		if (a != b)
		{
			cout << "Äâà îáºêòè íå º ð³âí³\n";
		}
	}
	catch (MyDeliveredException* a)
	{
		cerr << a->What();
	}
	catch (MyException a)
	{
		cerr << a.What() << endl;
	}
	catch (MyDeliveredException& x)
	{
		cerr << x.What() << endl;
	}


	return 0;
}