#include "HiddenPerceptron.h"
#include "Erreur.h"

namespace NeuralNetWork {
	HiddenPerceptron::HiddenPerceptron(unsigned int nb_entry, unsigned int i, unsigned int j, double *alpha, double* momentum, double(*foo)(double)) :
		m_couche(i), m_index(j), m_nb_entry(nb_entry), m_x0(true), m_coef_aprentissage(alpha),
		m_f_sortie(foo), m_coef_momentum(momentum), m_erreur(0.0)
	{
		for (unsigned int index = 0; index < nb_entry; index++) {
			m_poids.push_back(random_double());
			m_delta_poids.push_back(0.0);
		}
		m_seuil = random_double();
	}


	HiddenPerceptron::~HiddenPerceptron()
	{
	}


	std::vector<double> HiddenPerceptron::back_propagation(double delta)
	{
		m_erreur = delta;
		std::vector<double> deltas;
		for (double w : m_poids) {
			double wd = w * delta;
			deltas.push_back(wd);
		}
		return deltas;
	}

	double HiddenPerceptron::foward_propagation(std::vector<double> X)
	{
		m_X = std::vector<double>(X);
		double y = 0;
		unsigned int i = 0;
		while (i < m_nb_entry) {
			y += m_X[i] * m_poids[i];
			i++;
		}
		y += m_seuil;
		m_y_calculer = m_f_sortie(y);
		return m_y_calculer;
	}

	double HiddenPerceptron::final_propagation(std::vector<double> X)
	{
		unsigned int i = 0;
		double sig = 0;
		while (i < m_nb_entry) {
			sig = (double)(*m_coef_momentum * *m_coef_aprentissage * m_erreur* X[i] + (1 - *m_coef_momentum)*m_delta_poids[i]);
			m_delta_poids[i] = sig;
			m_poids[i] = m_poids[i] + sig;
			i++;
		}
		m_seuil += *m_coef_aprentissage * m_erreur;
		return foward_propagation(X);
	}

	void HiddenPerceptron::info()
	{
		std::printf("HP(%d,%d) w:", m_couche, m_index);
		for (double w : m_poids) {
			std::printf(" %f", w);
		}
		std::printf("\n");
	}

	void HiddenPerceptron::debug()
	{
		printf("DEBUG DU NERONE (%d/%d)\n", m_couche, m_index);
		printf("    >delta : %f\n", m_erreur);
	}
}
