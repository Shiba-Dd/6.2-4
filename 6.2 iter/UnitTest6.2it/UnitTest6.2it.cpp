#include "pch.h"
#include "CppUnitTest.h"
#include "../6.2 iter/6.2iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62it
{
	TEST_CLASS(UnitTest62it)
	{
	public:
		
        TEST_METHOD(TestMethod_countOddElements)
        {
            int arr[] = { -9, 5, -8, 7, -6, 9, -4, -3, 10, 1 };
            int expected = 6;
            int actual = countOddElements(arr, 10);

            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod_createArrayRange)
        {
            const int size = 10;
            int a[size];
            int Low = -10;
            int High = 10;

            createArray(a, size, Low, High);

            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High);
            }
        }
	};
}
