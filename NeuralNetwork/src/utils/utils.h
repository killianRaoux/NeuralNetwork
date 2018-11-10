#pragma once
#include "../core.h"

namespace NeuralNetWork {
	// Retourne un double random entre min et max (de base entre -1 et 1)
	double NN_API random_double(double min = -1.0, double max = 1.0);

	//Fonction Siganoid
	double NN_API sigmanoid(double x);

	//Fonction identity
	double NN_API identity(double x);

	//Fonction de seuil
	double NN_API seuil(double x);
}