#include "pch.h"
#include "CppUnitTest.h"
#include "../6.2 rek/6.2rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rek
{
	TEST_CLASS(UnitTest62rek)
	{
	public:
		
        TEST_METHOD(Test_countOddElementsRecursive)
        {
            
            int arr1[] = { -9, 5, -8, 7, -6, 9, -4, -3, 10, 1 };
            int expected1 = 6; 
            Assert::AreEqual(expected1, countOddElementsRecursive(arr1, 10));

        
            int arr2[] = { 2, -4, 6, 8, 0 };
            int expected2 = 0;
            Assert::AreEqual(expected2, countOddElementsRecursive(arr2, 5));

           
            int arr3[] = { -1, 3, -5, 7, 9 };
            int expected3 = 5;
            Assert::AreEqual(expected3, countOddElementsRecursive(arr3, 5));
        }

        
        TEST_METHOD(Test_countOddElementsRecursive_ZeroSize)
        {
            int arr[] = { 1, 3, 5 };
            Assert::AreEqual(0, countOddElementsRecursive(arr, 0));
        }

      
        TEST_METHOD(Test_createArrayRecursive_Range)
        {
            const int size = 15;
            int a[size];
            const int Low = -10;
            const int High = 10;

            createArrayRecursive(a, size, Low, High);

            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High, L"Елемент виходить за межі заданого діапазону");
            }
        }
	};
}
