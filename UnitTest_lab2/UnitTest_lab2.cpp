#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/algorithms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab2
{
	TEST_CLASS(UnitTestlab2)
	{
	public:
		int A[10] = { 2,0,-1,10,-7,21,11,-3,24,-34 };
		char B[10] = { 'f','s','d','s','a','d','u','z','k','l' };
		int C[10] = { -3,-2,-1,0,1,2,3,4,5,6 };
		TEST_METHOD(CorrectTest1)
		{
			Assert::IsTrue(correct(C,10));
		}
		TEST_METHOD(CorrectTest2)
		{
			int control[] = { 1,2,-3 };
			Assert::IsFalse(correct(control, 3));
		}

		TEST_METHOD(BinarySearchTest1)
		{
			Assert::IsTrue(BinarySearch(C, 10, 3) == 6);
		}
		TEST_METHOD(BinarySearchTest2)
		{
			try
			{
				int control = BinarySearch(A, 10, 3);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Array is not sorted.");
			}
		}
		TEST_METHOD(BinarySearchTest3)
		{
			try
			{
				int control = BinarySearch(A, -10, 3);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect data");
			}
		}
		TEST_METHOD(BubbleSortTest1)
		{
			BubbleSort(A, 10);
			Assert::IsTrue(A[0] == -34, L"Assert 1");
			Assert::IsTrue(A[9] == 24, L"Assert 2");
		}
		TEST_METHOD(BubbleSortTest2)
		{
			BubbleSort(C, 10);
			Assert::IsTrue(C[0] == -3, L"Assert 1");
			Assert::IsTrue(C[9] == 6, L"Assert 2");
		}
		TEST_METHOD(BubbleSortTest3)
		{
			
			try
			{
				BubbleSort(A, -10);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect data");
			}
		}
		TEST_METHOD(QuickSortTest1)
		{
			QuickSort(A, 0, 9);
			Assert::IsTrue(A[0] == -34, L"Assert 1");
			Assert::IsTrue(A[9] == 24, L"Assert 2");
		}
		TEST_METHOD(QuickSortTest2)
		{
			QuickSort(C, 0, 9);
			Assert::IsTrue(C[0] == -3, L"Assert 1");
			Assert::IsTrue(C[9] == 6, L"Assert 2");
		}
		TEST_METHOD(BogoSortTest1)
		{
			BogoSort(A, 10);
			Assert::IsTrue(A[0] == -34, L"Assert 1");
			Assert::IsTrue(A[9] == 24, L"Assert 2");
		}
		TEST_METHOD(BogoSortTest2)
		{
			BogoSort(C, 10);
			Assert::IsTrue(C[0] == -3, L"Assert 1");
			Assert::IsTrue(C[9] == 6, L"Assert 2");
		}
		TEST_METHOD(BogoSortTest3)
		{

			try
			{
				BogoSort(A, -10);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect data");
			}
		}
		TEST_METHOD(CountingSortTest1)
		{
			CountingSort(B, 10);
			Assert::IsTrue(B[0] == 'a', L"Assert 1");
			Assert::IsTrue(B[9] == 'z', L"Assert 2");
		}
		TEST_METHOD(CountingSortTest2)
		{
			try
			{
				CountingSort(B, -10);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Incorrect data");
			}
		}
	};
}
