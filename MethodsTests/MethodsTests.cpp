#include "pch.h"
#include <CppUnitTest.h>
#include <stdlib.h>
#include "..\Lab3Methods\Gold.h"
#include "..\Lab3Methods\Dichotomy.h"
#include "..\Lab3Methods\Newton.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MethodsTests
{
	double x_(double x) {
		return x;
	}
	double xIsZero(double x) {
		return 0;
	}
	double x2(double x) {
		return (x) * (x);
	}
	double minusX2(double x)
	{
		return -pow(x, 2);
	}

	double x2plus2(double x) {
		return (x) * (x)+2;
	}
	double one_div_x(double x) {
		return 1 / x;
	}
	double ePowX2(double x)
	{
		return pow(2.71828, pow(x, 2));
	}
	TEST_CLASS(Tests)
	{

	public:
		
		TEST_METHOD(Test_x2)
		{
			Gold gold(x2);
			Newton newton(x2);
			Dichotomy dichotomy(x2);
			Assert::IsTrue(abs(*gold.FindExtrems().begin()) < 1e-5 &&
				abs(*newton.FindExtrems().begin()) < 1e-5 && 
				abs(*dichotomy.FindExtrems().begin()) < 1e-5);
		}
		TEST_METHOD(Test_1_div_x)
		{
			Gold gold(one_div_x);
			Newton newton(one_div_x);
			Dichotomy dichotomy(one_div_x);
			Assert::IsTrue(gold.FindExtrems().empty() &&
				newton.FindExtrems().empty() &&
				dichotomy.FindExtrems().empty());
		}
		TEST_METHOD(Testx2Plus2)
		{
			Gold gold(x2plus2);
			Newton newton(x2plus2);
			Dichotomy dichotomy(x2plus2);
			Assert::IsTrue(abs(*gold.FindExtrems().begin()) < 1e-5 &&
				abs(*newton.FindExtrems().begin()) < 1e-5 &&
				abs(*dichotomy.FindExtrems().begin()) < 1e-5);
		}
		TEST_METHOD(TestX)
		{
			Gold gold(x_);
			Newton newton(x_);
			Dichotomy dichotomy(x_);
			Assert::IsTrue(gold.FindExtrems().empty() &&
				newton.FindExtrems().empty() &&
				dichotomy.FindExtrems().empty());
		}
		TEST_METHOD(TestEPowX2)
		{
			Gold gold(ePowX2);
			Newton newton(ePowX2);
			Dichotomy dichotomy(ePowX2);
			Assert::IsTrue(abs(*gold.FindExtrems().begin()) < 1e-5 &&
				abs(*newton.FindExtrems().begin()) < 1e-5 &&
				abs(*dichotomy.FindExtrems().begin()) < 1e-5);
		}
		TEST_METHOD(TestXIsZero)
		{
			Gold gold(xIsZero);
			Newton newton(xIsZero);
			Dichotomy dichotomy(xIsZero);
			Assert::IsTrue(gold.FindExtrems().empty() &&
				newton.FindExtrems().empty() &&
				dichotomy.FindExtrems().empty());
		}
		
	};
}
