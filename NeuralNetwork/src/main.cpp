#include "neurone.h"
#include <stdlib.h>
/*
Point d'entreer du programme.
*/
double learnLoop(unsigned int n, double seuil, Perceptron *p, std::vector<double> x, double y) {
	unsigned int i = 0;
	double delta;
	while (i < n) {
		delta = (*p).learn(x, y);
		if (abs(delta) < seuil) {
			std::printf("Fin de la phase d'aprentissage en %d iteration\navec un delta final de %f\n", i + 1, delta);
			break;
		}
		i++;
	}
	return delta;
}
int main() {
	std::vector<unsigned int> sl{ 3,3,3 };
	MultiLayerPerceptron mlp(sl,3,3);
	mlp.info();
	for (int i = 0; i < 100; i++) {
		mlp.learn({ 1.0,1.0,1.0 }, { 1.0 });
	}
	for (double d: mlp.learn({ 1.0,1.0,1.0 }, { 1.0 })) {
		printf("%f ", d);
	}
	mlp.info();
	system("pause");

}