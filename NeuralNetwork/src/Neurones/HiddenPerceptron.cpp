#include "HiddenPerceptron.h"



HiddenPerceptron::HiddenPerceptron(unsigned int nb_entry, unsigned int i, unsigned int j, double(*foo)(double)):
	Perceptron(nb_entry, foo, true), m_i(i), m_j(j)
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
	m_X = std::vector<double>(X);
	double y = 0;
	unsigned int i = 0;
	while (i < m_nb_entry) {
		y += m_X[i] * m_poids[i];
		i++;
	}
	y += m_w0;
	m_yres = m_foo(y);
	return m_yres;
}

double HiddenPerceptron::final_propagation(std::vector<double> X)
{
	unsigned int i = 0;
	double sig = 0;
	while (i < m_nb_entry) {
		sig = m_momentum * m_alpha * m_delta* X[i] + (1 - m_momentum)*m_delta_poids[i];
		m_delta_poids[i] = sig;
		m_poids[i] += sig;
		i++;
	}
	m_w0 += m_alpha * m_delta;
	//std::printf("Final delta:%f avec un resulta de %f\n", Y - test(X), test(X));
	return foward_propagation(X);
}

void HiddenPerceptron::info()
{
	std::printf("HP(%d,%d) w:", m_i, m_j);
	for (double w : m_poids) {
		std::printf(" %d", w);
	}
	std::printf("\n");
}

