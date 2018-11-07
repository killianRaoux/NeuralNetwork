#include "MultiLayerPerceptron.h"


MultiLayerPerceptron::MultiLayerPerceptron(std::vector<unsigned int> layer_structur, unsigned int xsize, unsigned int ysize, double(*foo)(double))
{
	m_xsize = xsize;
	m_ysize = ysize;
	std::vector<HiddenPerceptron> layer;
	unsigned int lsize = xsize;
	unsigned int i = 0;
	for (unsigned int s : layer_structur) {
		int j = 0;
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

double MultiLayerPerceptron::test(std::vector<double> X)
{
	return 0.0;
}

void MultiLayerPerceptron::info()
{
	std::printf("MLP\n    xsize:%d ysize:%d\n nlayer:%d   strucure:", m_xsize, m_ysize, m_layers.size());
	for (unsigned int l : m_structur) {
		std::printf(" %d", l);
	}
	std::printf("\n");
}
