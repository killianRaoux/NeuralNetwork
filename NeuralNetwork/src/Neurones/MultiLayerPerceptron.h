#pragma once
#include <vector>
#include "../utils/utils.h"
#include "HiddenPerceptron.h"
#include "Neural.h"
namespace NeuralNetWork {
	/*
	Reseaux de neurone multicouche (MLP) permetant d'apprendre des données plus complexes.*/
	class NN_API MultiLayerPerceptron : public Neural
	{
	public:
		//Constructeur
		MultiLayerPerceptron(std::vector<unsigned int> layer_structur, double * alpha, double * momentum, double(*foo)(double) = &identity);
		~MultiLayerPerceptron();
		// Fonction de test sans aprentissage.
		std::vector<double> test(std::vector<double> X) override;
		// Fonction d'aprentissage.
		std::vector<double> learn(std::vector<double> X, std::vector<double> Y) override;
		// Fonction permetant d'afficher les information du MLP
		void info();
	private:
		double(*m_foo)(double);
		std::vector<unsigned int> m_structur;
		std::vector<std::vector<HiddenPerceptron*>> m_layers;
		unsigned int m_xsize;
		unsigned int m_ysize;
		unsigned int m_temp_size;
		double *m_alpha;
		double *m_momentum;
	};
}

