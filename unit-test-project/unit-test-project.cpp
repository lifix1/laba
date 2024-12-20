#include "pch.h"
#include "CppUnitTest.h"
#include "../labacode/tarif.h"
#include "../labacode/processing.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Call testik[3];
			int n = 3;
			testik[0].cost = 2; // 6
			testik[0].duration = 123;
			testik[1].cost = 3; // 6
			testik[1].duration = 97;
			testik[2].cost = 1.5; // 3
			testik[2].duration = 100;
			Assert::AreEqual(0.046875, test_avg(testik, n));
		}
		TEST_METHOD(TestMethod2)
		{
			Call testik[3];
			int n = 3;
			testik[0].cost = 10; // 60
			testik[0].duration = 320;
			testik[1].cost = 3; // 3
			testik[1].duration = 54;
			testik[2].cost = 7; // 7
			testik[2].duration = 26;
			Assert::AreEqual(0.175, test_avg(testik, n));
		}
		TEST_METHOD(TestMethod3)
		{
			Call testik[3];
			int n = 3;
			testik[0].cost = 20; // 220
			testik[0].duration = 640;
			testik[1].cost = 8; // 16
			testik[1].duration = 108;
			testik[2].cost = 14; // 14
			testik[2].duration = 52;
			Assert::AreEqual(0.3125, test_avg(testik, n));
		}
		TEST_METHOD(TestMethod4)
		{
			Call testik[4];
			int n = 4;
			testik[0].cost = 2; // 4
			testik[0].duration = 120;
			testik[1].cost = 3; // 3
			testik[1].duration = 50;
			testik[2].cost = 3; // 3
			testik[2].duration = 30;
			testik[3].cost = 4; // 0
			testik[3].duration = 0;
			Assert::AreEqual(0.05, test_avg(testik, n));
		}
		TEST_METHOD(TestMethod5)
		{
			Call testik[3];
			int n = 3;
			testik[0].cost = 9; // 36
			testik[0].duration = 240;
			testik[1].cost = 10; // 40
			testik[1].duration = 236;
			testik[2].cost = 11; // 11
			testik[2].duration = 24;
			Assert::AreEqual(0.174, test_avg(testik, n));
		}
	};
}
