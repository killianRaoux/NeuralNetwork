#include "Perceptron.h"
#include <cstdlib> // Ajout de random
#include <stdlib.h>
#include "../utils/utils.h"
#include <math.h>
/*
Constructeur de la class Perceptron
:param nb_entry: nombre d'entrees du perceptron.
:param x0: Active ou desactive le poids constant ajoutant un poids qui sera toujours multiplier par 1.*/
Perceptron::Perceptron(unsigned int nb_entry, bool x0) : m_nb_entry(nb_entry), m_x0(x0), m_alpha(0.1)
{
	unsigned int i = 0;
	while (i < nb_entry) {
		m_poids.push_back(random_double());
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
	return y;
}

void Perceptron::learn(std::vector<double> X, double Y)
{
	m_delta = Y - test(X);
	unsigned int i = 0;
	while (i < m_nb_entry) {
		m_poids[i] += m_alpha * m_delta* X[i];
		i++;
	}
	m_w0 += m_alpha * m_delta;
	std::printf("Final delta:%f avec un resulta de %f\n", Y - test(X), test(X));
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
