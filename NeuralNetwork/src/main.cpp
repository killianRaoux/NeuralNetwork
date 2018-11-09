#include "neurone.h"
#include <stdlib.h>

// Point d'entreer du programme.
int main() {
	double alpha = 0.005;
	double momentum = 0.95;
	std::vector<unsigned int> sl{ 9,9,9,1 };
	MultiLayerPerceptron mlp(sl,3,1, &alpha, &momentum);
	//mlp.info();
	
	IOData t;
	t.X = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
	t.Y = { 0.0 };

	IOData t2;
	t2.X = { 1.0,0.0,0.0,0.0,1.0,0.0,1.0,0.0,0.0 };
	t2.Y = { 1.0 };

	IOData t3;
	t3.X = { -1.0,0.0,0.0,0.0,-1.0,0.0,-1.0,0.0,0.0 };
	t3.Y = { -1.0 };

	for (int k = 0; k < 50; k++) {
		learning_loop(&mlp, t, 10, 0.00001);
		learning_loop(&mlp, t2, 10, 0.00001);
		learning_loop(&mlp, t3, 10, 0.00001);
	}
	printf("RES = %f\n", mlp.test(t.X)[0]);
	printf("RES = %f\n", mlp.test(t2.X)[0]);
	printf("RES = %f\n", mlp.test(t3.X)[0]);
	//mlp.info();
	system("pause");

}