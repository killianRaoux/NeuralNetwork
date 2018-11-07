#pragma once
#include <vector>
#define SIGMANOID &sigmanoid
#define IDENTITY  &identity
#define SEUIL     &seuil
//Fonction Siganoid
double sigmanoid(double x);

//Fonction identity
double identity(double x);

//Fonction de seuil
double seuil(double x);


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
class Perceptron
{
public:
	Perceptron(unsigned int nb_entry, double(*foo)(double)= &identity, bool x0 = true);
	~Perceptron();
	unsigned int get_nb_entry();
	double test(std::vector<double> X);
	double learn(std::vector<double> X, double Y);
	double get_alpha();
	double get_momentum();
	void set_alpha(double alpha);
	void set_momentum(double momentum);
	void info();
protected:
	unsigned int m_nb_entry;
	std::vector<double> m_poids;
	std::vector<double> m_delta_poids;
	bool m_x0;
	double m_w0;
	double m_delta;
	double m_alpha;
	double m_momentum;
	double(*m_foo)(double);
};

