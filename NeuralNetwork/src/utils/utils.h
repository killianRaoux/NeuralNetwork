#pragma once

// Retourne un double random entre min et max (de base entre -1 et 1)
double random_double(double min = -1.0, double max = 1.0);
#define SIGMANOID &sigmanoid
#define IDENTITY  &identity
#define SEUIL     &seuil
//Fonction Siganoid
double sigmanoid(double x);

//Fonction identity
double identity(double x);

//Fonction de seuil
double seuil(double x);
