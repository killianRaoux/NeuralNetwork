#pragma once
#include "Perceptron.h"
class HiddenPerceptron :
	public Perceptron
{
public:
	HiddenPerceptron(unsigned int nb_entry, unsigned int i, unsigned int j, double(*foo)(double) = &identity);
	~HiddenPerceptron();
	// Calcul d'un resulta pour un entree X
	double foward_propagation(std::vector<double> X);
	// Calcul des valeurs delta.
	std::vector<double> back_propagation(double deltas);
	// Rectification des poids.
	double final_propagation(std::vector<double>);
	void info();
private:
	std::vector<double> m_X;
	double m_yres;
	unsigned int m_i, m_j;
};

