//#ifndef DIHOTOMY_H
//#define DIHOTOMY_H
//#include "Config.cpp"
//
//
//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <list>
//#include <algorithm>
//
//class Dihotomy {
//public:
//	Dihotomy(double (*pf)(double));
//	Dihotomy(double (*pf)(double), struct Config cfg);
//	Dihotomy(Dihotomy& A);
//	std::list<double> FindExtrems();
//	std::list<double> FindMin();
//	std::list<double> FindMax();
//	double (*pf)(double);
//	struct Config cfg;
//	int getExtrCount();
//private:
//	std::list<double*> minSegments;
//	std::list<double*> maxSegments;
//	bool FindLocal();
//
//};
//#endif