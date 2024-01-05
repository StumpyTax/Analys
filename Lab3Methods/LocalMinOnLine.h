#pragma once

#include <vector>
#include "Config.h"


class LocalMinOnLine
{
private:
	std::vector<std::vector<double>*> segments_;
	double (*pf)(double,double,double);
	Config* cfg_;
	 std::vector<double> dir;
	 std::vector<double> start;
	const double lambdagold_ = (sqrt(5) - 1) / 2;
public:
	LocalMinOnLine(double (*pf)(double, double, double), std::vector<double>& start, std::vector<double>& dir);
	LocalMinOnLine(double (*pf)(double, double, double), Config* cfg, std::vector<double>& start, std::vector<double>& dir);
	LocalMinOnLine(LocalMinOnLine& A);
	std::vector<double> findLocalMin();
};

