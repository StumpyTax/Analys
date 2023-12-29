
#include "Config.h"
#include "pch.h"


	Config::Config(double maxX, double minX, double eps,int iter,double stopMinValueX, double stopMaxValueX)
	{
		this->maxX = maxX;
		this->minX = minX;
		this->eps = eps;
		this->iter = iter;
		this->stopMaxValueX = stopMaxValueX;
		this->stopMinValueX = stopMinValueX;
	}
	Config::Config() {}
