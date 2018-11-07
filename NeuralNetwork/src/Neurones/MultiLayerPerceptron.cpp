#include "MultiLayerPerceptron.h"


MultiLayerPerceptron::MultiLayerPerceptron(std::vector<unsigned int> layer_structur, unsigned int xsize, unsigned int ysize, double(*foo)(double))
{
	m_xsize = xsize;
	m_ysize = ysize;
	m_structur = layer_structur;
	std::vector<HiddenPerceptron> layer;
	unsigned int lsize = xsize;
	unsigned int i = 0;
	for (unsigned int s : layer_structur) {
		unsigned int j = 0;
		while (j < s) {
			layer.push_back(HiddenPerceptron(lsize,i,j));
			j++;
		}
		lsize = s;
		m_layers.push_back(layer);
		layer.clear();
		i++;
	}
}

MultiLayerPerceptron::~MultiLayerPerceptron()
{
}

std::vector<double> MultiLayerPerceptron::test(std::vector<double> X)
{
	std::vector<double> lvalue = X;
	std::vector<double> ltemp;
	for (std::vector<HiddenPerceptron> l : m_layers) {
		for (HiddenPerceptron h : l) {
			ltemp.push_back(h.foward_propagation(lvalue));
		}
		lvalue = ltemp;
		ltemp.clear();
	}
	return lvalue;
}

std::vector<double> MultiLayerPerceptron::learn(std::vector<double> X, std::vector<double> Y)
{
	std::vector<double> deltas; // valeurs des delta Y-yres ou delta(t-1)*Swi
	std::vector<double> delta_temp; // valeur transitoire
	std::vector<double> yres = test(X);
	// Delta des couche de sortie.

	unsigned int i = 0;
	for (double y : yres) {
		deltas.push_back(Y[i] - y);
	}
	// Delta des couche cacher.

	unsigned int k = m_layers.size() - 1; // On inverse l'ordre de lecture des couche (Layer)
	while (k) { 
		// Initialisation des delta temp
		if (k > 1) {
			delta_temp = std::vector<double>(m_structur[k - 1]);
		}
		else {
			delta_temp = std::vector<double>(m_xsize);
		}
		// 
		i = 0;
		for (HiddenPerceptron h : m_layers[k]) {
			for (double d : h.back_propagation(deltas[i])) {
				delta_temp[i] += d;
			}
			i++;
		}
		deltas = delta_temp;
		k--;
	}
	std::vector<double> lvalue = X;
	std::vector<double> ltemp;
	for (std::vector<HiddenPerceptron> l : m_layers) {
		for (HiddenPerceptron h : l) {
			ltemp.push_back(h.foward_propagation(lvalue));
		}
		lvalue = ltemp;
		ltemp.clear();
	}
	return deltas;
}

void MultiLayerPerceptron::info()
{
	std::printf("MLP\n    xsize:%d  ysize:%d\n    nlayer:%d  strucure:", m_xsize, m_ysize, m_layers.size());
	for (unsigned int l : m_structur) {
		std::printf(" %d", l);
	}
	std::printf("\n");
	for (std::vector<HiddenPerceptron> l : m_layers) {
		for (HiddenPerceptron h : l) {
			h.info();
		}
	}
}
