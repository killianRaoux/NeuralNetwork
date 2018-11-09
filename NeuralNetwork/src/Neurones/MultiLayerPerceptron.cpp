#include "MultiLayerPerceptron.h"


MultiLayerPerceptron::MultiLayerPerceptron(std::vector<unsigned int> layer_structur, unsigned int xsize,
	unsigned int ysize, double * alpha, double * momentum, double(*foo)(double)):
	m_xsize(xsize), m_ysize(ysize), m_alpha(alpha), m_momentum(momentum), m_structur(layer_structur)
{
	std::vector<HiddenPerceptron*> layer;
	unsigned int lsize = xsize;
	unsigned int i = 0;
	m_temp_size = 0;
	for (unsigned int s : layer_structur) {
		if (m_temp_size < s) {
			m_temp_size = s;
		}
		unsigned int j = 0;
		while (j < s) {
			layer.push_back(new HiddenPerceptron(lsize,i,j,m_alpha,m_momentum));
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
	for (std::vector<HiddenPerceptron*> l : m_layers) {
		for (HiddenPerceptron *h : l) {
			ltemp.push_back(h->foward_propagation(lvalue));
		}
		lvalue = ltemp;
		ltemp.clear();
	}
	return lvalue;
}
/* Fonction d'aprentissage:
:param X: vecteur des entrees.
:param Y: vecteur des sorties.
:return:  vecteur des valeurs d'erreur delta (sortie attentue - sortie calculer)*/
std::vector<double> MultiLayerPerceptron::learn(std::vector<double> X, std::vector<double> Y)
{
	std::vector<double> deltas; // valeurs des delta Y-yres ou delta(t-1)*Swi
	std::vector<double> delta_temp; // valeur transitoire
	std::vector<double> yres = test(X); // Calcule de la sortie calculer.
	
	// Delta des couche de sortie.
	// initialisation d'un index permetant de lire les sortie une a une
	unsigned int i = 0;
	for (double y : yres) { // Pour chaque sortie calculer y
		deltas.push_back(Y[i] - y); // on ajoute a la liste des deltas erreurs la valeur d'erreur de sortie.
	}

	unsigned int k = m_layers.size()-1; // On inverse l'ordre de lecture des couche (Layer)
	while (k+1) {
		// Initialisation des delta temp
		delta_temp = std::vector<double>(m_temp_size);

		i = 0;
		
		for (HiddenPerceptron *h : m_layers[k]) {
			std::vector<double> bp = h->back_propagation(deltas[i]);
			for (double d : bp) {
				delta_temp[i] += d;
			}
			i++;
		}
		deltas = delta_temp;
		k--;
	}

	std::vector<double> lvalue = X;
	std::vector<double> ltemp;
	for (std::vector<HiddenPerceptron*> l : m_layers) {
		for (HiddenPerceptron* h : l) {
			ltemp.push_back(h->final_propagation(lvalue));
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
	for (std::vector<HiddenPerceptron*> l : m_layers) {
		for (HiddenPerceptron *h : l) {
			h->info();
		}
	}
}
