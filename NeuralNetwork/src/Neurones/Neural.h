#pragma once
#include <vector>
#include "../core.h"
#include "Erreur.h"
const double MAXERROR = 100000.0;
namespace NeuralNetWork {
	class NN_API Neural
	{
	public:
		virtual std::vector<double> test(std::vector<double>) = 0;
		virtual std::vector<double> learn(std::vector<double>, std::vector<double>) = 0;
	};

	struct NN_API IOData {
		std::vector<double> X;
		std::vector<double> Y;
	};

	void NN_API add_IO(std::vector<IOData>* datas, std::vector<double> X, std::vector<double> Y);
	void NN_API learning_loop(Neural*, IOData, unsigned int, double);
}