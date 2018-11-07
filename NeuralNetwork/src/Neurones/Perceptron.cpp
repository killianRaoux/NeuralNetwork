#include "Perceptron.h"
#include <stdlib.h>
#include "../utils/utils.h"
#include <math.h>
/*
Constructeur de la class Perceptron
:param nb_entry: nombre d'entrees du perceptron.
:param x0: Active ou desactive le poids constant ajoutant un poids qui sera toujours multiplier par 1.
:param foo: fonction de sortie de la fonction test. L'utilisateur peut utiliser les defines.*/
Perceptron::Perceptron(unsigned int nb_entry, double(*foo)(double), bool x0) :
	m_nb_entry(nb_entry), m_x0(x0), m_alpha(0.1),m_foo(foo), m_momentum(0.9)
{
	unsigned int i = 0;
	while (i < nb_entry) {
		m_poids.push_back(random_double());
		m_delta_poids.push_back(0.0);
		i++;
	}
	m_w0 = random_double();
}

Perceptron::~Perceptron()
{
}

unsigned int Perceptron::get_nb_entry()
{
	return m_nb_entry;
}

double Perceptron::test(std::vector<double> entry)
{
	double y = 0;
	unsigned int i = 0;
	while (i < m_nb_entry) {
		y += entry[i] * m_poids[i];
		i++;
	}
	if (m_x0) {
		y += m_w0;
	}
	return m_foo(y);
}

double Perceptron::learn(std::vector<double> X, double Y)
{
	m_delta = Y - test(X);
	unsigned int i = 0;
	double sig = 0;
	while (i < m_nb_entry) {
		sig = m_momentum * m_alpha * m_delta* X[i] + (1-m_momentum)*m_delta_poids[i];
		m_delta_poids[i] = sig;
		m_poids[i] += sig;
		i++;
	}
	m_w0 += m_alpha * m_delta;
	//std::printf("Final delta:%f avec un resulta de %f\n", Y - test(X), test(X));
	return m_delta;
}

double Perceptron::get_alpha()
{
	return m_alpha;
}

double Perceptron::get_momentum()
{
	return m_momentum;
}

void Perceptron::set_alpha(double alpha)
{
	m_alpha = alpha;
}

void Perceptron::set_momentum(double momentum)
{
	m_momentum = momentum;
}

void Perceptron::info()
{
	std::printf("Perceptron\n    Poids:");
	unsigned int i = 0;
	for (double w : m_poids) {
		std::printf("%d:%f    ", i, w);
		i++;
	}
	std::printf("\n    poid null:%f\n", m_w0);
}

double sigmanoid(double x)
{
	return 1/(1+exp(-x));
}

double identity(double x)
{
	return x;
}

double seuil(double x)
{
	if (x < 0)
		return 0.0;
	else
		return 1.0;
}
