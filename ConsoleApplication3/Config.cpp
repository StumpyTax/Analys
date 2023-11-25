#ifndef CONFIG_H
#define CONFIG_H
#include "Config.h"


	Config::Config(double maxX, double minX, double eps)
	{
		this->maxX = maxX;
		this->minX = minX;
		this->eps = eps;
	}
	Config::Config() {}
#endif