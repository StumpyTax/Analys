#include "Newton.h"
#include <iostream>

using namespace std;

double Newton::FindFirstDerivative(double x)
{
	return (pf(x+ cfg->h)-pf(x- cfg->h))/(2*cfg->h);
}

double Newton::FindSecondDerivative(double x)
{
	return (pf(x + cfg->h) - 2 * pf(x) + pf(x - cfg->h)) / (cfg->h * cfg->h);
}

bool Newton::FindLocal() {
	double a, b;
	a = cfg->minX;
	b = a + 2*cfg->h;

	while (b < cfg->maxX)
	{
		try {
			double d = a +cfg->h;
			double fa = pf(a);
			double fb = pf(b);
			if (fa > pf(d) && fb > pf(d))
				minSegments.push_back(new double[2] {a, b});
			else if (fa < pf(d) && fb < pf(d))
				maxSegments.push_back(new double[2] {a, b});
			a = d;
			b = a + 2*cfg->h;
		}
		catch (exception e) {
			a = a + cfg->h;
			b = a + 2*cfg->h;
		}
	}
	return !(minSegments.empty() && maxSegments.empty());
}

Newton::Newton(double(*pf)(double))
{
	this->pf = pf;
	this->cfg= new Config();
}

Newton::Newton(double(*pf)(double), Config* cfg)
{
	this->pf = pf;
	this->cfg = cfg;
}

Newton::Newton(Newton& A)
{
	this->cfg = A.cfg;
	this->pf = A.pf;
}

std::list<double> Newton::FindExtrems()
{
	list<double> res = FindMin();
	res.merge(FindMax());
	return res;
}

std::list<double> Newton::FindMin()
{
	if (minSegments.empty() && maxSegments.empty())
		if (!FindLocal() || minSegments.empty())
			return std::list<double>();
	std::list<double> res;
	for (auto i : minSegments) {
		double x = (i[0]+i[1])/2, x1;
		do {
			x1 = x;
			x = x - FindFirstDerivative(x) / FindSecondDerivative(x);
		} while (abs(x - x1) > cfg->eps);
		res.push_back(x);
	}
	return res;
}

std::list<double> Newton::FindMax()
{
	if (minSegments.empty() && maxSegments.empty())
		if (!FindLocal() || maxSegments.empty())
			return std::list<double>();

	std::list<double> res;
	for (auto i : maxSegments) {
		double x = (i[0] + i[1]) / 2, x1;
		do {
			x1 = x;
			x = x - FindFirstDerivative(x) / FindSecondDerivative(x);
		} while (abs(x - x1) > cfg->eps);
		res.push_back(x);
	}
	return res;
}

