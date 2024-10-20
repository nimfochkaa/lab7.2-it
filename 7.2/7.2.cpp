#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2 іт/7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My72
{
	TEST_CLASS(My72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int k = 3;
			const int n = 3;
			const int Low = 7;
			const int High = 65;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			Create(a, k, n, Low, High);

			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < n; j++)
				{
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High, L"Value out of range");
				}
			}

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
