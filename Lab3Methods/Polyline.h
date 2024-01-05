#ifndef POLYLINE_H
#define POLYLINE_H

#include "Config.h"

#include <vector>

class Polyline {
private:
	std::vector<double*> segments;
	double FindFirstDerivative(double x);
	bool FindLocal();
	double (*pf)(double);
	Config* cfg;
public:
	std::vector<double> FindExtr();
	Polyline(double (*pf)(double));
	Polyline(double (*pf)(double), Config* cfg);
	Polyline(Polyline& A);
};

#endif