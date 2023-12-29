#pragma once
#include "pch.h"
struct Config {

	double h = 1e-2;
	double maxX = 1000;
	double minX = -1000;
	double eps = 1e-5;
	int iter = 100;
	double stopMinValueX = -10000;
	double stopMaxValueX = 10000;

	Config(double maxX, double minX, double eps,int iter, double stopMinValueX, double stopMaxValueX);
	Config();
};