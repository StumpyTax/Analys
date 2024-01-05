#ifndef DIHOTOMY_H
#define DIHOTOMY_H
#include "Config.h"


#include <vector>


class Dichotomy {
private:
	std::vector<double*> segments_;
	double (*pf)(double);
	Config* cfg_;
	bool FindLocal();
	double FindFirstDerivative(double x) const;
public:
	Dichotomy(double (*pf)(double));
	Dichotomy(double (*pf)(double), Config* cfg);
	Dichotomy(Dichotomy& A);
	std::vector<double> FindExtrems();

};
#endif