#include "neurone.h"
#include <stdlib.h>
/*
Point d'entreer du programme.
*/

int main() {
	std::printf("Hello World\n");
	std::vector<double> x{ 1.0,1.0,1.0 };
	Perceptron p(3,SIGMANOID);
	std::printf("resultat:%f\n",p.test(x));
	unsigned int i = 0;
	while (i < 100) {
		p.learn(x, 1.0);
		p.info();
		i++;
	}
	std::printf("resultat:%f\n", p.test(x));
	system("pause");

}