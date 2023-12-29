#include "Gold.h"
#include "pch.h"
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

set<double> Gold::FindExtrems() {
			if (!FindLocalMin() && !FindLocalMax())
				return set<double>();

		set<double> res;
		for (double* i : segments) {
			double* a = &i[0];
			double* b = &i[1];
			double d = *a + lambdagold * (*b - *a);
			double c = *a+ *b - d;
			double prev;
			bool error = false;
			while (fabs(*b - *a) > cfg->eps) {
				d = *a + lambdagold * (*b - *a);
				c = *a + *b - d;
				bool acd = pf(*a) > pf(c) && pf(d) > pf(c);
				bool cdb = pf(c) > pf(d) && pf(*b) > pf(d);
				if (acd)
				{
					prev = *b;
					*b = d;
				}
				else if (cdb)
				{
					prev = *a;
					*a = c;
				}
				else {
					if (prev > *b){
						*a = *b- cfg->h;
						*b = prev+cfg->h;
					}
					else if (prev < *a) {
						*b =* a+cfg->h;
						*a = prev-cfg->h;
					}
					else {
						printf("\nerror");
						printf("\na=%f, b=%f", *a, *b);
						error = true;
						break;
					}
				}
				/*{
					printf("\nerror");
					printf("\na=%f, b=%f", *a, *b);
					error = true;
					break;
				}*/
			}
			if (!error) {
				double tmp = trunc(((*a + *b) / 2) * (1 / cfg->eps)) / (1 / cfg->eps);
				double p = pf(tmp);
				double j = 1, n = 0, l = -1;
				if (abs(p) != j / n && p != sqrt(l))
				{
					bool inRes = false;
					for (auto i : res)
						if (abs(tmp - i) < cfg->eps) {
							inRes = true;
							break;
						}
					if (!inRes)
						res.insert(tmp);
				}
			}
		}
		return res;
	}

bool Gold::FindLocalMin() {
	for (int i = 0; i < cfg->iter; i++) {
		double a, b;
		//a = rand() * (cfg->minX - cfg->maxX) / RAND_MAX + cfg->minX;
		a = (rand() / (double)RAND_MAX) * (cfg->maxX - cfg->minX) + cfg->minX;		
		b = a + cfg->h;
		short reversed = 1;
		while (b > cfg->stopMinValueX && b<cfg->stopMaxValueX)
		{
			double d = a + reversed*lambdagold * cfg->h;
				double fa = pf(a);
				double fb = pf(b);
				double fd = pf(d);

				if (fa > fd && fb > fd)
					if (reversed < 0) {
						segments.push_back(new double[2] {b, a});
						break;
					}
					else {
						segments.push_back(new double[2] {a, b});
						break;
					}
				if (fa < fb && reversed>0) {
					reversed = -1;
				}
				a = d;
				b = a+reversed*cfg->h;

		}
	}
	return !segments.empty();
}
bool Gold::FindLocalMax() {
	for (int i = 0; i < cfg->iter; i++) {
		double a, b;
		//a = rand() * (cfg->minX - cfg->maxX) / RAND_MAX + cfg->minX;
		a = (rand() / (double)RAND_MAX) * (cfg->maxX - cfg->minX) + cfg->minX;
		b = a + cfg->h;
		short reversed = 1;
		while (b > cfg->stopMinValueX && b < cfg->stopMaxValueX)
		{
				double d = a + reversed * lambdagold * cfg->h;
				double fa = pf(a);
				double fb = pf(b);
				double fd = pf(d);

				if (fa < fd && fb < fd)
					if (reversed < 0) {
						segments.push_back(new double[2] {b, a});
						break;
					}
					else {
						segments.push_back(new double[2] {a, b});
						break;
					}
				if (fa > fb && reversed>0) {
					reversed = -1;
				}
				a = d;
				b = a + reversed * cfg->h;

		}
	}
	return !segments.empty();
}
	

