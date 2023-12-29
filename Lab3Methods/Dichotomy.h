#ifndef DIHOTOMY_H
#define DIHOTOMY_H
#include "Config.cpp"

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>

class Dichotomy {
private:
	std::vector<double*> segments;
	double (*pf)(double);
	Config* cfg;
	bool FindLocalMax();
	bool FindLocalMin();
public:
	Dichotomy(double (*pf)(double));
	Dichotomy(double (*pf)(double), Config* cfg);
	Dichotomy(Dichotomy& A);
	std::set<double> FindExtrems();

};
#endif