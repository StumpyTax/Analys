#include "Gold.h"
#include "Newton.h"
#include "Polyline.h"
#include <iostream>

double mainf(double x) {
	int v = 5;
	return pow(x, 6) - v * pow(x, 5) + v * pow(x, 3) - 10 * pow(x, 2) + x;
}

double testf(double x)
{
	return x*x-2*x;
}

int main(){
	//Gold gold(mainf);
	//auto res = gold.FindExtrems();
	//Newton newton(mainf);
	//auto res = newton.FindExtrems();
	Polyline poly(mainf);
	auto res = poly.FindExtr();
	for (auto i:res)
	{
		printf("\nxextr=%f",i);
	}
	return 0;
}