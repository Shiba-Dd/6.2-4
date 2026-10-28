#include "pch.h"
#include "CppUnitTest.h"
#include "../6.3it/6.3iter.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63iter
{
	TEST_CLASS(UnitTest63iter)
	{
	public:
		
        TEST_METHOD(Test_sumElements_Int)
        {
            int arr[] = { -5, 10, 3, -2, 7, 0 };
            int expectedSum = 13; 
            Assert::AreEqual(expectedSum, sumElements(arr, 6));
        }

        TEST_METHOD(Test_sumElementsTemplate_Int)
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            int expectedSum = 15;
            Assert::AreEqual(expectedSum, sumElementsTemplate<int>(arr, 5));
        }

      
        TEST_METHOD(Test_sumElementsTemplate_Double)
        {
            double arr[] = { 1.5, -2.5, 3.0, 4.2 };
            double expectedSum = 6.2; 
            double tolerance = 0.0001; 

            Assert::AreEqual(expectedSum, sumElementsTemplate<double>(arr, 4), tolerance);
        }

     
        TEST_METHOD(Test_createArray_Range)
        {
            const int size = 20;
            int a[size];
            const int Low = -10;
            const int High = 10;

            createArray(a, size, Low, High);

            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High, L"Елемент вийшов за межі заданого діапазону");
            }
        }

     
        TEST_METHOD(Test_sumElements_ZeroSize)
        {
            int arr[] = { 10, 20, 30 };
            Assert::AreEqual(0, sumElements(arr, 0));
        }
	};
}
