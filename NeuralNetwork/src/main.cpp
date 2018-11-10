#include "neurone.h"
#include <stdlib.h>

// Point d'entreer du programme.
int main() {
	double alpha = 0.005;
	double momentum = 0.95;
	std::vector<unsigned int> sl{ 9,9,1 };
	MultiLayerPerceptron mlp(sl,9,1, &alpha, &momentum, sigmanoid);
	//mlp.info();


	std::vector<IOData> datas;
	add_IO(&datas, {
		0.0,0.0,0.0,
		0.0,0.0,0.0,
		0.0,0.0,0.0 }, { 0.0 });
	add_IO(&datas, {
		1.0,0.0,0.0,
		0.0,1.0,0.0,
		0.0,0.0,1.0 }, { 1.0 });
	add_IO(&datas, {
		-1.0,0.0,0.0,
		0.0,-1.0,0.0,
		0.0,0.0,-1.0 }, { -1.0 });
	add_IO(&datas, {
		1.0,0.0,0.0,
		0.0,-1.0,0.0,
		0.0,0.0,1.0 }, { 0.0 });
	add_IO(&datas, {
		1.0,1.0,1.0,
		0.0,0.0,0.0,
		0.0,0.0,0.0 }, { 1.0 });
	add_IO(&datas, {
		-1.0,-1.0,-1.0,
		0.0,0.0,0.0,
		0.0,0.0,0.0 }, { -1.0 });
	for (int k = 0; k < 100; k++) {
		for (IOData t : datas) {
			learning_loop(&mlp, t, 10, 0.00001);
		}
	}
	int i = 0;
	for (IOData t : datas) {
		printf("test %d %f pour %f\n",i, mlp.test(t.X)[0], t.Y[0]);
		i++;
	}
	//mlp.info();
	system("pause");

}