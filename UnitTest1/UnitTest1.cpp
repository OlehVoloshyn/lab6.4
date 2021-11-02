#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			int i, j;
			int size = 100;
			int* arr = new int[size];
			t = product(arr, size, 0, 1);
		}
	};
}
