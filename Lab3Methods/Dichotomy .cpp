#include "pch.h"
#include "Dichotomy.h"


using namespace std;

Dichotomy::Dichotomy(double (*pf)(double))
{
	this->pf = pf;
	this->cfg_ = new Config();
}

Dichotomy::Dichotomy(double (*pf)(double), Config* cfg)
{
	this->pf = pf;
	this->cfg_ = cfg;
}


double  Dichotomy::FindFirstDerivative(const double x) const
{
	return (pf(x + cfg_->eps) - pf(x - cfg_->eps)) / (2 * cfg_->eps);
}

bool Dichotomy::FindLocal()
{
	double a, b;
	a = cfg_->minX;
	b = a + 2 * cfg_->h;

	while (b < cfg_->maxX)
	{
		try {
			const double d = a + cfg_->h;
			const double fa = pf(a);
			const double fb = pf(b);
			if ((fa > pf(d) && fb > pf(d)) || (fa < pf(d) && fb < pf(d)))
				segments_.push_back(new double[2]{ a, b });
			a = d;
			b = a + 2 * cfg_->h;
		}
		catch (std::exception e) {
			a = a + cfg_->h;
			b = a + 2 * cfg_->h;
		}
	}
	return !segments_.empty();
}
std::vector<double> Dichotomy::FindExtrems()
{
	if (!FindLocal())
		return std::vector<double>{};

	std::vector<double> res;
	for (auto i : segments_) {
		double a = i[0], b = i[1];
		while (abs(a - b) / 2 > cfg_->eps)
		{
			double p = (a + b) / 2.0;
			if (fabs(FindFirstDerivative(p)) < cfg_->eps)
			{
				a = p;
				b = p;
				break;
			}
			if (FindFirstDerivative(p) * FindFirstDerivative(a) < 0)
				b = p;
			else a = p;
		}
		res.push_back((a + b) / 2);
	}
	return res;
}