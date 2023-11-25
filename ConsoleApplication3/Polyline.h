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
	std::list<double*> minSegments;
	std::list<double*> maxSegments;
	double FindFirstDerivative(double x);
	bool FindLocal();
	double (*pf)(double);
	Config* cfg;
public:
};

#endif