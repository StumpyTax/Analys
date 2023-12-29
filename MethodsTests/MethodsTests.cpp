#include "pch.h"
#include <CppUnitTest.h>
#include <stdlib.h>
#include "..\Lab3Methods\Gold.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MethodsTests
{
	double x2(double x) {
		return x * x;
	}
	TEST_CLASS(Tests)
	{

	public:
		
		TEST_METHOD(Testx2)
		{
			Gold gold(x2);
			Assert::IsTrue(abs(*gold.FindExtrems().begin()) < 1e-5);
		}
	};
}
