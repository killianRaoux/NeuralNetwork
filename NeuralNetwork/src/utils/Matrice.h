#pragma once

#include "../core.h"

namespace NeuralNetWork {
	class NN_API Matrice
	{
	public:
		Matrice();
		Matrice(unsigned int i, unsigned int j, double base_value = 0);
		Matrice(unsigned int i, unsigned int j, double* value);
		~Matrice();
		void set(unsigned int i, unsigned j, double value);
		double get(unsigned int i, unsigned j);
		double* get_value();
		Matrice operator* (Matrice other);
		void opti_mul(Matrice *A, Matrice *B);
		unsigned int get_row_size();
		unsigned int get_col_size();
		void info();
	private:
		unsigned int m_row_size, m_col_size;
		double* m_value;
	};
}

