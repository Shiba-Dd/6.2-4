#include "pch.h"
#include "CppUnitTest.h"
#include "../6.3 rek/6.3rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63rek
{
	TEST_CLASS(UnitTest63rek)
	{
	public:
		
        TEST_METHOD(Test_sumElementsRecursive_Int)
        {
            int arr[] = { -5, 10, 3, -2, 7, 0 };
            int expectedSum = 13; 
            Assert::AreEqual(expectedSum, sumElementsRecursive(arr, 6));
        }

      
        TEST_METHOD(Test_sumElementsRecursiveTemplate_Int)
        {
            int arr[] = { 1, 2, 3, 4, 5 };
            int expectedSum = 15;
            Assert::AreEqual(expectedSum, sumElementsRecursiveTemplate<int>(arr, 5));
        }

        TEST_METHOD(Test_sumElementsRecursiveTemplate_Double)
        {
            double arr[] = { 1.5, -2.5, 3.0, 4.2 };
            double expectedSum = 6.2; 
            double tolerance = 0.0001; 

            Assert::AreEqual(expectedSum, sumElementsRecursiveTemplate<double>(arr, 4), tolerance);
        }

     
        TEST_METHOD(Test_createArrayRecursive_Range)
        {
            const int size = 20;
            int a[size];
            const int Low = -10;
            const int High = 10;

            createArrayRecursive(a, size, Low, High);

            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High, L"Елемент вийшов за межі заданого діапазону");
            }
        }

        TEST_METHOD(Test_sumElementsRecursive_ZeroSize)
        {
            int arr[] = { 10, 20, 30 };
            Assert::AreEqual(0, sumElementsRecursive(arr, 0));
        }
	};
}
