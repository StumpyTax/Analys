#ifndef NEWTON_H
#define NEWTON_H

#include "Config.h"

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <algorithm>

class Newton {
private:
	std::list<double*> minSegments;
	std::list<double*> maxSegments;
	double FindFirstDerivative(double x);
	double FindSecondDerivative(double x);
	bool FindLocal();
	double (*pf)(double);
	Config* cfg;
public:
	Newton(double (*pf)(double));
	Newton(double (*pf)(double), Config* cfg);
	Newton(Newton& A);
	std::list<double> FindExtrems();
	std::list<double> FindMin();
	std::list<double> FindMax();

};

#endif