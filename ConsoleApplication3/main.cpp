#include "../Lab3Methods/Gold.h"
#include "../Lab3Methods/Newton.h"
#include <iostream>

double f(double x) {
	int v = 5;
	return pow(x, 6) - v * pow(x, 5) + v * pow(x, 3) - 10 * pow(x, 2) + x;
}

double testf(double x)
{
	return x*x-2*x;
}

int main(){
	Gold gold(f);
	auto res = gold.FindExtrems();
	//Newton newton(f);
	//auto res = newton.FindExtrems();
	//Polyline poly(f);
	//auto res = poly.FindExtr();
	for (auto i:res)
	{
		printf("\nxextr=%f",i);
	}
	return 0;
}