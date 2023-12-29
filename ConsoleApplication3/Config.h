#pragma once
#include "pch.h"

struct Config {

	double h = 1e-3;
	double maxX = 1000;
	double minX = -1000;
	double eps = 1e-7;

	Config(double maxX, double minX, double eps);
	Config();
};