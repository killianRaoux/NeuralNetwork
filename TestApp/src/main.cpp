/* 
Exemple d'utilisation de la library.
Ici l'on se concentre sur lutilisation des MultiLayersPerceptron qui sont des
reseaux de neurones multi couche permettant d'aprendre des données en profondeur*/
// Les includes
#include <stdlib.h> // Non utile pour le calcule, ici juste utilisé pour l'affichage de l'exemple

// Include de la dll et de ses elements pour le teste.
#include "NeuralNetwork.h" 

// Tout les elements sont stocké dans le namespace NeuralNetwork
using namespace NeuralNetWork;

// Exemple n1:
void Exemple1() {
	// On definie la structure des couches de MLP. Ici il y aura 3 couches.
	// L'entree sera de taille 9.
	// La sortie sera de taille 1.
	// il y aura donc deux couche de 9 neurone cacheés.
	std::vector<unsigned int> network_structure{
		9, // Taille de la couche d'entree.
		9, // Taille d'une couche cacher, ici il n'y en a qu'une mais il peut en avoir plusieur.
		1 }; // Taille de la couche de sortie.

			 /* Definition du coefficient d'aprentissage
			 Il represente la vitesse d'aprentissage du reseau.
			 Il doit etre compris entre 0 et 1.
			 Plus il est proche de 1 plus il aprend vite mais il y a des risque de divergence
			 qui bloque le reseau. Il faut donc trouver un compromis entre vitesse et stabilite.
			 */
	double alpha = 0.01;
	/* Definition du coefficient momentum
	Il definit dans un certain sens le taux de stabilite du reseau
	compris entre 0 et 1, plus il est grand moins le coefficient a de l'effet.
	Mais un trop petit momentum diminue la vitesse d'aprentissage voir s'il est inferieur a 0.5
	peut rendre le reseau instable pour les erreurs eleves.
	*/
	double momentum = 0.9;
	/* On creer le reseau */
	MultiLayerPerceptron mlp(
		network_structure,  // structure
		&alpha,				// Coefficient d'aprentissage
		&momentum,			// Coefficient du momentum
		&identity);			// (Obtionnel) Fonction d'activation

							/* Definition de data a aprendre au reseau*/
	IOData test;
	test.X = {
		1.0,1.0,1.0,
		1.0,1.0,1.0,
		1.0,1.0,1.0 }; // Valeur d'entree
	test.Y = { 1.0 }; // Valeur de sortie.

					  // Test avant aprentissage:
	printf(" test avant aprentissage: %f \n", mlp.test(test.X)[0]);

	// Aprentissage de nos data:
	learning_loop(
		&mlp, // pointeur vers le reseau de neurone.
		test, // Data a aprendre.
		100,  // Nombre d'aprentissage
		0.000001); // Erreur minimal 

				   // Test apres aprentissage:
	printf(" test avant aprentissage: %f \n", mlp.test(test.X)[0]);

}

void test() {
	double Av[6] = { 0.0 ,1.0 ,2.0 ,3.0 ,4.0 ,5.0 };
	double Bv[6] = { 0.0 ,1.0 ,2.0 ,3.0 ,4.0 ,5.0 };
	Matrice A(3, 2, Av);
	Matrice B(2, 3, Bv);
	A.info();
	B.info();
	printf("Hello");
	(A*B).info();
	Matrice C = A * B;
	C.info();
}
// Point d'entree du programme.
int main() {
	Exemple1();
	system("pause");
}

