#pragma once
#include "Perceptron.h"
class HiddenPerceptron :
	public Perceptron
{
public:
	HiddenPerceptron(unsigned int nb_entry, unsigned int i, unsigned int j, double(*foo)(double) = &identity);
	~HiddenPerceptron();
	std::vector<double> back_propagation(double deltas);
	double foward_propagation(std::vector<double> X);
	void info();
private:
	std::vector<double> m_X;
	unsigned int m_i, m_j;
};

