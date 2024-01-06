#include "../Lab3Methods/Gold.h"
#include "../Lab3Methods/Newton.h"
#include "../Lab3Methods/Dichotomy.h"
#include <iostream>

double f(double x) {
	int v = 5;
	return pow(x, 6) - v * pow(x, 5) + v * pow(x, 3) - 10 * pow(x, 2) + x;
}

double testf(double x)
{
	return (x - 2) * (x - 2);
}

int main(){
	int a;
	setlocale(LC_ALL, "");
	std::cout << "Введите номер метода(0- Золотое сечение; 1- Метод Ньютона; 2- Метод Дихотомии)"<<std::endl;
	std::cin >> a;
	std::vector<double> res;
	switch (a)
	{
	case 0:
		{
		Gold gold(f);
		 res = gold.FindExtrems();
		break;
		}
	case 1:
		{
		Newton newton(f);
		 res = newton.FindExtrems();
		break;
		}
	case 2:
		{
		Dichotomy poly(f);
		res = poly.FindExtrems();
		break;
		}
		default:
		{
			return 1;
		}
	}

	for (auto i:res)
	{
		printf("\nxextr=%f",i);
	}
	return 0;
}