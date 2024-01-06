#include "Newton.h"
#include "pch.h"

using namespace std;

double Newton::FindFirstDerivative(double x)
{
	return (pf(x+ cfg->eps)-pf(x- cfg->eps))/(2*cfg->eps);
}

double Newton::FindSecondDerivative(double x)
{
	double p1 = (pf(x + cfg->eps) - 2 * pf(x) + pf(x - cfg->eps));
	double p2 = (cfg->eps * cfg->eps);
	return  p1/p2 ;
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

std::vector<double> Newton::FindExtrems()
{

	std::vector<double> res;
	for (int i = 0; i < cfg->iter;i++) {
		double x = (rand() / (double)RAND_MAX) * (cfg->maxX - cfg->minX) + cfg->minX,x1;
		do {
			x1 = x;
			x = x - FindFirstDerivative(x) / FindSecondDerivative(x);
		} while (abs(x - x1) > cfg->eps);

		double tmp = trunc((x) * (1 / cfg->eps)) / (1 / cfg->eps);
		double p = pf(tmp);
		if (!isnan(p)&& !isinf(p) && !isnan(tmp) && !isinf(tmp))
		{
			bool inRes = false;
			for (auto i : res)
				if (abs(tmp - i) < cfg->eps) {
					inRes = true;
					break;
				}
			if(!inRes)
				res.push_back(tmp);
		}
	}
	return res;
}


