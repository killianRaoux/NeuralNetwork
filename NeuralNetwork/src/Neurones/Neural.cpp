#include "Neural.h"

void add_IO(std::vector<IOData> * datas, std::vector<double> X, std::vector<double> Y)
{
	IOData t;
	t.X = X;
	t.Y = Y;
	datas->push_back(t);
}

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
