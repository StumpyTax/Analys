#ifndef GOLD_H
#define GOLD_H

#include "Config.h"
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>


class Gold {
private:
	std::vector<double*> segments;
	double (*pf)(double);
	Config* cfg;
	bool FindLocalMax();
	bool FindLocalMin();
	const double lambdagold = (sqrt(5) - 1) / 2;
public:
	Gold(double (*pf)(double));
	Gold(double (*pf)(double), Config* cfg);
	Gold(Gold& A);
	std::set<double> FindExtrems();

};

#endif