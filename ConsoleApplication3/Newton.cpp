#include "Newton.h"
#include <iostream>

using namespace std;

double Newton::FindFirstDerivative(double x)
{
	return (pf(x+ cfg->eps)-pf(x- cfg->eps))/(2*cfg->eps);
}

double Newton::FindSecondDerivative(double x)
{
	return (pf(x + cfg->eps) - 2 * pf(x) + pf(x - cfg->eps)) / (cfg->eps * cfg->eps);
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
			if ((fa > pf(d) && fb > pf(d)) || (fa < pf(d) && fb < pf(d)))
				segments.push_back(new double[2] {a, b});
			a = d;
			b = a + 2*cfg->h;
		}
		catch (exception e) {
			a = a + cfg->h;
			b = a + 2*cfg->h;
		}
	}
	return !segments.empty();
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
	if (!FindLocal())
			return std::list<double>();
	std::list<double> res;
	for (auto i : segments) {
		double x = (i[0] + i[1]) / 2, x1;
		do {
			x1 = x;
			x = x - FindFirstDerivative(x) / FindSecondDerivative(x);
		} while (abs(x - x1) > cfg->eps);
		res.push_back(x);
	}
	return res;
}


