#include <iostream>
#include <stdio.h>

double f(double x);
void test();

struct config
{
	double left_x0, right_x0;
};
class Gold
{
public:
	double a, b;
	double xmin;
	double (*pf)(double);
	struct config cfg;
	Gold(double (*pf)(double))
	{
		this->pf = pf;
	}
	Gold(double (*pf)(double),struct config cfg)
	{
		this->pf = pf;
		this->cfg = cfg;
	}
	Gold(Gold& A)
	{
		pf = A.pf;
		cfg = A.cfg;
	}
	void FindLocal()
	{
		a = -5;
		b = 10;
	}
	void FindMin()
	{
		double lambdagold = (sqrt(5) - 1) / 2;
		FindLocal();
		double d,c;
		while (fabs(b-a)>1e-7)
		{
			d = a + lambdagold * (b - a);
			c = a + b - d;
			if(pf(a)>pf(c) && pf(d)>pf(c))
			{
				b = d;

			}
			else if(pf(c)>pf(d) && pf(b)>pf(d))
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
};
double f(double x)
{
	return  x * x - 2 * x;
}
int main()
{
	test();
	Gold gold(f);
	gold.FindMin();
	printf("x_min = %f", gold.xmin);
	return 0;
}

void test()
{
	{
		Gold gold(f);
		gold.FindMin();
		double ans = 1;
		double res = gold.xmin;
		if (fabs(ans - res) > 1e-3)
			printf("\nerror 1");
	}
}

