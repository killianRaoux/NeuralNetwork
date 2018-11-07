#include "HiddenPerceptron.h"



HiddenPerceptron::HiddenPerceptron(unsigned int nb_entry, unsigned int i, unsigned int j, double(*foo)(double)):
	Perceptron(nb_entry, foo, true), m_i(i), m_j(i)
{
}

HiddenPerceptron::~HiddenPerceptron()
{
}

std::vector<double> HiddenPerceptron::back_propagation(double delta)
{
	m_delta = delta;
	std::vector<double> deltas;
	for (double w : m_poids) {
		deltas.push_back( w * delta);
	}
	return deltas;
}

double HiddenPerceptron::foward_propagation(std::vector<double> X)
{
	m_X = X;
	double y = 0;
	unsigned int i = 0;
	while (i < m_nb_entry) {
		y += X[i] * m_poids[i];
		i++;
	}
	y += m_w0;
	return m_foo(y);
}

