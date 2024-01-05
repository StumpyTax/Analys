#include "LocalMinOnLine.h"

LocalMinOnLine::LocalMinOnLine(double (*pf)(double, double, double), std::vector<double>& start,std::vector<double>& dir)
{
	this->pf = pf;
	this->segments_=std::vector<std::vector<double>*>{};
	this->dir= dir;
	this->cfg_ = new Config();
	this->start = start;
}

LocalMinOnLine::LocalMinOnLine(double (*pf)(double, double, double), Config* cfg, std::vector<double>& dir, std::vector<double>& start)
{
	this->pf = pf;
	this->cfg_ = cfg;
	this->dir = dir;
	this->start = start;
	this->segments_ = std::vector<std::vector<double>*>{};
}
LocalMinOnLine:: LocalMinOnLine(LocalMinOnLine& A)
{
	this->pf = A.pf;
	this->cfg_ = A.cfg_;
	this->dir = A.dir;
	this->start = A.start;
}

std::vector<double> LocalMinOnLine::findLocalMin()
{
	std::vector<double> a{ 0,0,0 }, b{ 0,0,0 }, min{};
	double min_val = DBL_MAX;
	for(double mult=cfg_->minX;mult<cfg_->maxX;mult+=cfg_->h)
	{
		for (int i = 0; i < 3; i++)
			a[i]= start[i]+dir[i]*mult;
		if (pf(a[0], a[1], a[2]) < min_val) {
			min_val = pf(a[0], a[1], a[2]);
			min = a;
		}
	}
	
	return min;
}


