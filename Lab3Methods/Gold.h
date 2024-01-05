#ifndef GOLD_H
#define GOLD_H

#include "Config.h"
#include <iostream>
#include <vector>
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