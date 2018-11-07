#pragma once
#include <vector>
#include "../utils/utils.h"
#include "HiddenPerceptron.h"
/*
Reseaux de neurone multicouche (MLP) permetant d'apprendre des données plus complexes.*/
class MultiLayerPerceptron
{
public:
	//Constructeur
	MultiLayerPerceptron(std::vector<unsigned int> layer_structur, unsigned int xsize, unsigned int ysize, double(*foo)(double) = &identity);
	~MultiLayerPerceptron();
	// Fonction de test sans aprentissage.
	std::vector<double> test(std::vector<double> X);
	// Fonction d'aprentissage.
	double learn(std::vector<double> X, double Y);
	// Fonction permetant d'afficher les information du MLP
	void info();
private:
	double(*m_foo)(double);
	std::vector<unsigned int> m_structur;
	std::vector<std::vector<HiddenPerceptron>> m_layers;
	unsigned int m_xsize;
	unsigned int m_ysize;
};

