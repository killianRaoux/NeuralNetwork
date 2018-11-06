#pragma once
#include <vector>
/*
Fonction Siganoid
*/
double sigmanoid(double x);
/*
Les perceptron sont des neurones unitaires.
Ils ont un nombre definie d'entrees et une sortie.
Ils fonctionnent avec un sommateur et des poids.
Ils "aprennent" grace a un algorithm nommé "BackPropagation" qui rectifie la valeur des poids a chaque test.
*/
class Perceptron
{
public:
	Perceptron(unsigned int nb_entry, bool x0 = true);
	~Perceptron();
	unsigned int get_nb_entry();
	double test(std::vector<double> X);
	void learn(std::vector<double> X, double Y);
	double back_propagation();
	void info();
protected:
	unsigned int m_nb_entry;
	std::vector<double> m_poids;
	bool m_x0;
	double m_w0;
	double m_delta;
	double m_alpha; 
};

