#ifndef GOLD_H
#define GOLD_H

#include "Config.h"

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <algorithm>

class Gold {
private:
	std::list<double*> minSegments;
	std::list<double*> maxSegments;
	bool FindLocal();
public:
	double (*pf)(double);
	Config* cfg;
	const double lambdagold = (sqrt(5) - 1) / 2;
	Gold(double (*pf)(double));
	Gold(double (*pf)(double), Config* cfg);
	Gold(Gold& A);
	std::list<double> FindExtrems();
	std::list<double> FindMin();
	std::list<double> FindMax();
};

#endif