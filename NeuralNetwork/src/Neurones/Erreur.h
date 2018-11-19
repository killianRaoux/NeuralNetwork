#pragma once

#include <exception>
#include <string>

#include <exception>

class Erreur : public std::exception
{
public:
	Erreur(int numero = 0, std::string const& phrase = "", int niveau = 0) throw()
		:m_numero(numero), m_phrase(phrase), m_niveau(niveau)
	{}

	virtual const char* what() const throw()
	{
		return m_phrase.c_str();
	}

	int getNiveau() const throw()
	{
		return m_niveau;
	}

	virtual ~Erreur() throw()
	{}

private:
	int m_numero;               //Numéro de l'erreur
	std::string m_phrase;            //Description de l'erreur
	int m_niveau;               //Niveau de l'erreur
};