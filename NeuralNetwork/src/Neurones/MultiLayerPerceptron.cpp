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
			ltemp.push_back(h.test(lvalue));
		}
		lvalue = ltemp;
		ltemp.clear();
	}
	return lvalue;
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
