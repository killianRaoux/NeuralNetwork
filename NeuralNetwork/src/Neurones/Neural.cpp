#include "Neural.h"

void learning_loop(Neural *RN, IOData data, unsigned int count , double seuil)
{
	double erreur = 2*seuil;
	std::vector<double> res;
	for (int i =0; i < count; i++){
		erreur = 0.0;
		count--;
		res = RN->learn(data.X, data.Y);
		for (double d : res) {
			erreur += abs(d);
		}
		if (erreur < seuil) {
			break;
		}
		else if (erreur > MAXERROR){
			printf("DIVERGENCE!!! %d \n", i);
			break;
		}
	}
}
