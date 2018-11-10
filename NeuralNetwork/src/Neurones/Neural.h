#pragma once
#include <vector>
const double MAXERROR = 100000.0;
class Neural
{
public:
	virtual std::vector<double> test(std::vector<double>) = 0;
	virtual std::vector<double> learn(std::vector<double>, std::vector<double>) = 0;
};

struct IOData {
	std::vector<double> X;
	std::vector<double> Y;
};

void add_IO(std::vector<IOData>* datas, std::vector<double> X, std::vector<double> Y);
void learning_loop(Neural*,IOData, unsigned int, double);