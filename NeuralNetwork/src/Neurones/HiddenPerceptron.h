#pragma once
#include "Perceptron.h"
class HiddenPerceptron
{
public:
	HiddenPerceptron(unsigned int nb_entry, unsigned int i, unsigned int j, double *alpha, double* momentum, double(*foo)(double) = &identity);
	~HiddenPerceptron();
	// Calcul d'un resulta pour un entree X
	double foward_propagation(std::vector<double> X);
	// Calcul des valeurs delta.
	std::vector<double> back_propagation(double deltas);
	// Rectification des poids.
	double final_propagation(std::vector<double>);
	void info();
	void debug();//fonction de debogage.
private:
	unsigned int m_nb_entry; // taille de l'entree
	std::vector<double> m_poids, m_X; // liste des poids
	std::vector<double> m_delta_poids; // liste des delta des poids
	bool m_x0; // activation du seuil
	double m_seuil; // valeur du poid de seuil
	double m_erreur; // valeur du delta de sorti l'or de l'aprentissage
	double *m_coef_aprentissage; // valeur tu coefficient d'apprentissage
	double *m_coef_momentum; // valeur du coefficient d'inertie
	double(*m_f_sortie)(double); // fonction de sortie
	double m_y_calculer;
	unsigned int m_couche, m_index; // Identifient du Neurone. i = couche 
};

