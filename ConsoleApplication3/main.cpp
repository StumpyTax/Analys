#include "../Lab3Methods/LocalMinOnLine.h"
#include <iostream>

double f(double x,double y,double z) {
	int v = 5;
	return pow(x,2) + v * pow(y,2) + pow(z,2) + 3 * x * y - v * x * z - y * z + x - v * y + z;
}


int main(){

	std::vector<double> start{ 2,1,5 };
	std::vector<double> dir{ -1,2,1 };
	LocalMinOnLine loc(f, start, dir);
	auto min = loc.findLocalMin();
	
	std::cout << "min: " << min[0] <<" " << min[1] << " " << min[2] << std::endl;

	
	return 0;
}