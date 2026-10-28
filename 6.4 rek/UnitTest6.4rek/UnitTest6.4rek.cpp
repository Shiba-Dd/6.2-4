#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4 rek/6.4rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rek
{
	TEST_CLASS(UnitTest64rek)
	{
	public:
		
        TEST_METHOD(Test_findMinIndexRecursive)
        {
            double arr[] = { 2.5, -1.2, 0.5, -2.8, 1.1 };
            int expectedMinIndex = 3; 

            Assert::AreEqual(expectedMinIndex, findMinIndexRecursive(arr, 5));
        }

        
        TEST_METHOD(Test_sumBetweenFirstAndSecondNegativeRecursive_Success)
        {
        
            double arr[] = { 1.0, -2.0, 0.5, 3.0, -1.5, 4.0 };
            double expectedSum = 3.5;
            double tolerance = 0.0001;

            Assert::AreEqual(expectedSum, sumBetweenFirstAndSecondNegativeRecursive(arr, 6), tolerance);
        }

        
        TEST_METHOD(Test_sumBetweenFirstAndSecondNegativeRecursive_NoElementsBetween)
        {
         
            double arr1[] = { 1.0, -2.0, -1.5, 3.0 };
            Assert::AreEqual(0.0, sumBetweenFirstAndSecondNegativeRecursive(arr1, 4));

         
            double arr2[] = { 1.0, -2.0, 3.0, 4.0 };
            Assert::AreEqual(0.0, sumBetweenFirstAndSecondNegativeRecursive(arr2, 4));
        }

     
        TEST_METHOD(Test_transformArrayRecursive)
        {
            double arr[] = { 2.5, -0.5, 3.1, 0.8, -1.2, 0.0 };
            
            double expected[] = { -0.5, 0.8, 0.0, 2.5, 3.1, -1.2 };

            transformArrayRecursive(arr, 6);

            for (int i = 0; i < 6; i++) {
                Assert::AreEqual(expected[i], arr[i], 0.0001);
            }
        }

     
        TEST_METHOD(Test_createArrayRecursive_Range)
        {
            const int size = 20;
            double a[size];
            const double Low = -3.0;
            const double High = 3.0;

            createArrayRecursive(a, size, Low, High);

            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High, L"Елемент виходить за межі [Low, High]");
            }
        }
	};
}
