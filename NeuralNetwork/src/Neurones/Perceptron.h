#pragma once
#include <vector>
#include "../utils/utils.h"
#include "../core.h"

namespace NeuralNetWork {
	/*
	Les perceptron sont des neurones unitaires.
		-Ils ont un nombre definie d'entrees et une sortie.
		-Ils fonctionnent avec un sommateur et des poids.
		-Ils "aprennent" grace a un algorithm nommé "BackPropagation" qui rectifie la valeur des poids a chaque test.
		-alpha est le coefficient d'apprentissage. alpha E [0,1]. plus alpha est grand plus le perceptron a tendance a apprendre vite
			mais plus le reseau a des chances d'osciller voir meme de diverger!
		-momentum est un coefficient pour eviter cette oscillation. Plus il est grand moins il a de chance d'oscillation.
			Mais plus il est petit moins le perceptron apprend.
		-Il est donc benefique de trouver un couple alpha/momentum pour un apprentissage rapide mais non oscillant.
	*/
	class NN_API Perceptron
	{
	public:
		Perceptron(unsigned int nb_entry, double(*foo)(double) = &identity, bool x0 = true); //Constructeur
		~Perceptron(); // Destructeur
		double test(std::vector<double> X); // Test unitaire sur une entree X
		double learn(std::vector<double> X, double Y); // Aprentissage unitaire pour un entree x et une sortie y
		// Getter
		unsigned int get_nb_entry();
		double get_alpha();
		double get_momentum();
		//Setter
		void set_alpha(double alpha);
		void set_momentum(double momentum);
		//Autre
		virtual void info();
	protected:
		unsigned int m_nb_entry; // taille de l'entree
		std::vector<double> m_poids; // liste des poids
		std::vector<double> m_delta_poids; // liste des delta des poids
		bool m_x0; // activation du seuil
		double m_w0; // valeur du poid de seuil
		double m_delta; // valeur du delta de sorti l'or de l'aprentissage
		double m_alpha; // valeur tu coefficient d'apprentissage
		double m_momentum; // valeur du coefficient d'inertie
		double(*m_foo)(double); // fonction de sortie
	};
}

