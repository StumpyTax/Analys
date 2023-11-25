#include <iostream>
#include "Gold.h"

using namespace std;

Gold::Gold(double (*pf)(double))
	{
		this->pf = pf;
		this->cfg = new Config();
	}
Gold::Gold(double (*pf)(double), Config* cfg)
	{
		this->pf = pf;
		this->cfg = cfg;
	}
Gold::Gold(Gold& A)
	{
		pf = A.pf;
		cfg = A.cfg;
	}
list<double> Gold::FindExtrems() {
		list<double> res= FindMin();
		res.merge(FindMax());
		return res;
	}
list<double> Gold::FindMin() {
		if (maxSegments.empty() && minSegments.empty())
			if (!FindLocal())
				return list<double>();

		list<double> res;
		for (double* i : minSegments) {
			double* a = &i[0];
			double* b = &i[1];
			double d = *a + lambdagold * (*b - *a);
			double c = *a+ *b - d;
			bool error = false;
			while (fabs(*b - *a) > cfg->eps) {
				d = *a + lambdagold * (*b - *a);
				c = *a + *b - d;
				if (pf(*a) > pf(c) && pf(d) > pf(c))
				{
					*b = d;
				}
				else if (pf(c) > pf(d) && pf(*b) > pf(d))
				{
					*a = c;
				}
				else
				{
					printf("\nerror");
					printf("\na=%f, b=%f", *a, *b);
					error = true;
					break;
				}
			}
			if (!error) {
				double tmp = trunc(((*a + *b) / 2) * (1 / cfg->eps)) / (1 / cfg->eps);
				double p = pf(tmp);
				double j = 1, n = 0, l = -1;
				if (abs(p) != j / n && p != sqrt(l))
				{
					res.push_back(tmp);
				}
			}
		}
		return res;
	}
list<double> Gold::FindMax() {
		if(maxSegments.empty() && minSegments.empty())
			if (!FindLocal())
				return list<double>();

		list<double> res;
		for (double* i : maxSegments) {

			double* a = &i[0];
			double* b = &i[1];
			double d = *a + lambdagold * (*b - *a);
			double c = *a + *b - d;
			bool error = false;

			while (fabs(*b - *a) > cfg->eps) {
				d = *a + lambdagold * (*b - *a);
				c = *a + *b - d;
				if (pf(*a) < pf(c) && pf(d) < pf(c))
				{
					*b = d;
				}
				else if (pf(c) < pf(d) && pf(*b) < pf(d))
				{
					*a = c;
				}
				else
				{
					printf("\nerror");
					printf("\na=%f, b=%f", *a, *b);
					error = true;
					break;
				}
			}
			if (!error) {
				double tmp = trunc(((*a + *b) / 2)*(1/cfg->eps))/ (1 / cfg->eps);
				double p = pf(tmp);
				double j = 1, n = 0,l=-1;
				if (abs(p) !=j/n && p != sqrt(l))
				{
					res.push_back( tmp);
				}
			}
		}
		return res;
	}
bool Gold::FindLocal() {
		double a, b;
			a = cfg->minX;
			b = a + cfg->h;

			while (b < cfg->maxX)
			{
				try {
					double d = a + lambdagold * (b - a);
					double fa = pf(a);
					double fb = pf(b);
					if (fa>pf(d) && fb>pf(d))
						minSegments.push_back(new double[2]{a,b});
					else if (fa < pf(d) && fb < pf(d))
						maxSegments.push_back(new double[2] {a, b});
					a = d;
					b = a + cfg->h;
				}
				catch (exception e) {
					a = a + lambdagold * (b - a);
					b = a + cfg->h;
				}
			}
		return !minSegments.empty();
	} 
	

