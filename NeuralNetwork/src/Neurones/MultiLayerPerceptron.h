#pragma once
#include <vector>
#include "../utils/utils.h"
#include "HiddenPerceptron.h"
/*
Reseaux de neurone multicouche permetant d'apprendre des données plus complexes.*/
class MultiLayerPerceptron
{
public:
	MultiLayerPerceptron(std::vector<unsigned int> layer_structur, unsigned int xsize, unsigned int ysize, double(*foo)(double) = &identity);
	~MultiLayerPerceptron();
	double test(std::vector<double> X);
	double learn(std::vector<double> X, double Y);
	void info();
private:
	double(*m_foo)(double);
	std::vector<unsigned int> m_structur;
	std::vector<std::vector<HiddenPerceptron>> m_layers;
	unsigned int m_xsize;
	unsigned int m_ysize;

};

