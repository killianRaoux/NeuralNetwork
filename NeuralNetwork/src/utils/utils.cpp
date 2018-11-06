#include "utils.h"
#include <random>

double random_double(double min, double max)
{
	return (double)(min + (rand() / (RAND_MAX / (max - min))));
}
