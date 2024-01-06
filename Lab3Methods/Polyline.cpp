#include "Polyline.h"
#include "pch.h"

double Polyline::FindFirstDerivative(double x)
{
	return (pf(x + cfg->eps) - pf(x - cfg->eps)) / (2 * cfg->eps);
}

bool Polyline::FindLocal()
{
	double a, b;
	a = cfg->minX;
	b = a + 2 * cfg->h;

	while (b < cfg->maxX)
	{
		try {
			double d = a + cfg->h;
			double fa = pf(a);
			double fb = pf(b);
			if ((fa > pf(d) && fb > pf(d)) || (fa < pf(d) && fb < pf(d)))
				segments.push_back(new double[2] {a, b});
			a = d;
			b = a + 2 * cfg->h;
		}
		catch (std::exception e) {
			a = a + cfg->h;
			b = a + 2 * cfg->h;
		}
	}
	return !segments.empty();
}

std::vector<double> Polyline::FindExtr()
{
	if (!FindLocal())
		return std::vector<double>();

	std::vector<double> res;
	for (auto i : segments) {
		//
	}
	return res;
}


Polyline::Polyline(double(*pf)(double), Config* cfg)
{
	this->pf = pf;
	this->cfg = cfg;
}

Polyline::Polyline(double(*pf)(double))
{
	this->pf = pf;
	this->cfg = new Config();
}

Polyline::Polyline(Polyline& A)
{
	this->cfg = A.cfg;
	this->pf = A.pf;
}
