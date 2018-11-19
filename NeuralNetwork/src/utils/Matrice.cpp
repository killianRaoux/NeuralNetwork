#include "Matrice.h"

#include <stdlib.h>
#include <stdio.h>


namespace NeuralNetWork {
	Matrice::Matrice():m_row_size(0), m_col_size(0)
	{
	}
	Matrice::Matrice(unsigned int row_size, unsigned int col_size, double base_value):
		m_row_size(row_size), m_col_size(col_size)
	{
		m_value = (double*)malloc(m_row_size*m_col_size);
		for (unsigned int i = 0; i < row_size*col_size; i++) {
			m_value[i] = base_value;
		}
	}

	Matrice::Matrice(unsigned int i, unsigned int j, double * value):
		m_row_size(i), m_col_size(j), m_value(value)
	{
	}


	Matrice::~Matrice()
	{
		free(m_value);
	}

	void Matrice::set(unsigned int i, unsigned j, double value)
	{
		if (i > m_row_size || j > m_col_size) {
			printf("Erreur: index de la matrice trop grand: \n    Données: %d/%d\n    Attendue: %d/%d", i, j, m_row_size, m_col_size);
		}
		m_value[i*m_row_size + j] = value;
	}

	double Matrice::get(unsigned int i, unsigned j)
	{
		if (i > m_row_size || j > m_col_size) {
			printf("Erreur: index de la matrice trop grand: \n    Données: %d/%d\n    Attendue: %d/%d\n", i, j, m_row_size, m_col_size);
		}
		return m_value[i*m_row_size + j];
	}

	double * Matrice::get_value()
	{
		return m_value;
	}

	Matrice Matrice::operator*(Matrice other)
	{
		printf("Hello");
		if (m_col_size != other.get_row_size()) {
			printf("Erreur: Multipliaction impossible mauvaise taille");
			system("pause");
			exit(1);
		}
		unsigned int q = m_row_size, p = other.get_col_size(), k = m_col_size;
		Matrice res (q, p);
		double temp;
		for (unsigned int iq = 0; iq < q; iq++) {
			for (unsigned int ip = 0; ip < p; ip++) {
				temp = 0;
				for (unsigned int ik = 0; ik < k; ik++) {
					temp += this->get(iq, ik)*other.get(ik, ip);
				}
				res.set(iq, ip, temp);
			}
		}
		res.info();
		return res;
	}

	void Matrice::opti_mul(Matrice * A, Matrice * B)
	{
		// TODO
	}

	unsigned int Matrice::get_row_size()
	{
		return m_row_size;
	}

	unsigned int Matrice::get_col_size()
	{
		return m_col_size;
	}

	void Matrice::info()
	{
		for (unsigned int i = 0; i < m_row_size; i++) {
			printf("[");
			for (unsigned int j = 0; j < m_col_size; j++) {
				printf("%5.5f,", m_value[i*m_row_size + j]);
			}
			printf("]\n");
		}
	}
}