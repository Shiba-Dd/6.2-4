#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4iter/6.4iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64iter
{
	TEST_CLASS(UnitTest64iter)
	{
	public:
		
        TEST_METHOD(Test_findMinIndex)
        {
            double arr[] = { 2.5, -1.2, 0.5, -2.8, 1.1 };
            int expectedMinIndex = 3; 

            Assert::AreEqual(expectedMinIndex, findMinIndex(arr, 5));
        }

       
        TEST_METHOD(Test_sumBetweenFirstAndSecondNegative_Success)
        {
          
            double arr[] = { 1.0, -2.0, 0.5, 3.0, -1.5, 4.0 };
            double expectedSum = 3.5;
            double tolerance = 0.0001;

            Assert::AreEqual(expectedSum, sumBetweenFirstAndSecondNegative(arr, 6), tolerance);
        }

       
        TEST_METHOD(Test_sumBetweenFirstAndSecondNegative_NoElementsBetween)
        {
            
            double arr1[] = { 1.0, -2.0, -1.5, 3.0 };
            Assert::AreEqual(0.0, sumBetweenFirstAndSecondNegative(arr1, 4));

            double arr2[] = { 1.0, -2.0, 3.0, 4.0 };
            Assert::AreEqual(0.0, sumBetweenFirstAndSecondNegative(arr2, 4));
        }

        
        TEST_METHOD(Test_transformArray)
        {
            double arr[] = { 2.5, -0.5, 3.1, 0.8, -1.2, 0.0 };
         
            double expected[] = { -0.5, 0.8, 0.0, 2.5, 3.1, -1.2 };

            transformArray(arr, 6);

            for (int i = 0; i < 6; i++) {
                Assert::AreEqual(expected[i], arr[i], 0.0001);
            }
        }

   
        TEST_METHOD(Test_createArray_Range)
        {
            const int size = 20;
            double a[size];
            const double Low = -3.0;
            const double High = 3.0;

            createArray(a, size, Low, High);

            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High, L"Елемент виходить за межі [Low, High]");
            }
        }
	};
}
