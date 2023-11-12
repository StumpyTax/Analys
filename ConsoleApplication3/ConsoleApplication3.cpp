#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

double f(double x);
void test();

struct config
{
	int itteractionCount = 5;
	double h = 1;
	double segment = 1000;
	double eps = 1e-7;
};
class Gold
{
public:
	double xmin;
	double a, b;
	double (*pf)(double);
	struct config cfg;
	double lambdagold = (sqrt(5) - 1) / 2;

	Gold(double (*pf)(double))
	{
		this->pf = pf;
	}
	Gold(double (*pf)(double), struct config cfg)
	{
		this->pf = pf;
		this->cfg = cfg;
	}
	Gold(Gold& A)
	{
		pf = A.pf;
		cfg = A.cfg;
	}
	
	void FindMin() {
		if (!FindLocal())
			throw exception("Localization failed");

		double d = a + lambdagold * (b - a);
		double c = a + b - d;
		while (fabs(b - a) > cfg.eps) {
			d = a + lambdagold * (b - a);
			c = a + b - d;
			if (pf(a) > pf(c) && pf(d) > pf(c))
			{
				b = d;
			}
			else if (pf(c) > pf(d) && pf(b) > pf(d))
			{
				a = c;
			}
			else
			{
				printf("\nerror");
				printf("\na=%f, b=%f", a, b);
				return;
			}
		}
		xmin = (a + b) / 2;
	}

private:
	bool FindLocal() {
		for (int i = 0; i < cfg.itteractionCount; i++) {
			a = rand() % 2001 - 1000;
			b = a + cfg.h*(1+lambdagold);
			while (abs(a) < cfg.segment && abs(b) < cfg.segment)
			{
				double d = a + lambdagold * (b - a);
				double fa = pf(a);
				double fb = pf(b);
				if ((fa-pf(a+cfg.eps) > 0 && fb - pf(b + cfg.eps) < 0) || (fa - pf(a + cfg.eps) < 0 && fb - pf(b + cfg.eps) >0))
					return true;
				//if (abs(fb) > abs(fa))
				//	cfg.h = -cfg.h;
				a = d;
				b = a + cfg.h * (1 + lambdagold);
			}
		}
		return false;
	}
};
double testf(double x)
{
	return pow(x,2) - 2 * x;
}
double mainf(double x) {
	int v = 5;
	return pow(x, 6) - v * pow(x, 5) + v * pow(x, 3) - 10 * pow(x, 2) + x;
}
int main()
{
	//test();
	Gold gold(mainf);

	try {
		gold.FindMin();
	}
	catch (const exception& e) {
		cout << e.what();
		return 1;
	}
	printf("x_min = %f", gold.xmin);
	return 0;
}

//void test()
//{
//	{
//		Gold gold(f);
//		//gold.FindMin();
//		double ans = 1;
//		double res = gold.xmin;
//		if (fabs(ans - res) > 1e-3)
//			printf("\nerror 1");
//	}
//}

