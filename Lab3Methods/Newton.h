#ifndef NEWTON_H
#define NEWTON_H

#include "Config.h"
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>
class Newton {
private:

	double FindFirstDerivative(double x);
	double FindSecondDerivative(double x);
	double (*pf)(double);
	Config* cfg;
public:
	Newton(double (*pf)(double));
	Newton(double (*pf)(double), Config* cfg);
	Newton(Newton& A);
	std::set<double> FindExtrems();

};

#endif