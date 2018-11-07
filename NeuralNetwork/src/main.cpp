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
	std::printf("Hello World\n");
	std::vector<double> x{ 1.0,1.0,1.0 };
	Perceptron p(3,IDENTITY);
	std::printf("resultat:%f\n",p.test(x));
	learnLoop(100, 0.00001, &p, x, 1.0);
	std::printf("resultat:%f\n", p.test(x));
	system("pause");

}