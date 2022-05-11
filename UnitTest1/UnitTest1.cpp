#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 5.1D/Pair.h"
#include "../OOP 5.1D/Pair.cpp"
#include "../OOP 5.1D/Point.h"
#include "../OOP 5.1D/Point.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Point test(2, 3);
			test++;
			Assert::AreEqual(4, test.GetY());
		}
	};
}