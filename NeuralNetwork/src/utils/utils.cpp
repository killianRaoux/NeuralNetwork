#include "utils.h"
#include <random>

double random_double(double min, double max)
{
	return (double)(min + (rand() / (RAND_MAX / (max - min))));
}

double sigmanoid(double x)
{
	return 1 / (1 + exp(-x));
}

double identity(double x)
{
	return x;
}

double seuil(double x)
{
	if (x < 0)
		return 0.0;
	else
		return 1.0;
}