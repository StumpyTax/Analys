#ifndef POLYLINE_H
#define POLYLINE_H

#include "Config.h"

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <algorithm>

class Polyline {
private:
	std::list<double*> segments;
	double FindFirstDerivative(double x);
	bool FindLocal();
	double (*pf)(double);
	Config* cfg;
public:
	std::list<double> FindExtr();
	Polyline(double (*pf)(double));
	Polyline(double (*pf)(double), Config* cfg);
	Polyline(Polyline& A);
};

#endif