// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

#include "nim.h"
#include "nim_ihm.h"

#define FACILE 1 // choix pour faire une partie facile
#define NORMALE 2 // choix pour faire une partie normale
#define DIFFICILE 3 // choix pour faire une partie difficile
#define QUITTER 4 // choix pour quitter le jeu

int io_lire_entier(int min, int max);

// verifier la valeur entree par l'utilisateur
int io_lire_entier(int min, int max) {

	int valeur; // valeur entree par l'utilisateur

	ihm_scanf("%d", &valeur);
	// si la valeur entree par l'utilisateur n'est pas conforme a l'intervalle de valeur demandee, demander d'entrer une autre valeur
	if (valeur < min || valeur > max) {
		do {
			ihm_printf("La valeur entree n'est pas valide, entree une autre valeur: ");
			ihm_scanf("%d", &valeur);

		} while (valeur < min || valeur > max);
	}

	return valeur;
}

// demander le niveau de difficulté de la partie et le nombre de colonnes utilisees
int io_afficher_menu(void) {

	int choix; // choix de l'utilisateur
	int col_min = 2; // nombre de colonnes minimum
	int col_max = 20; // nombre de colonnes maximum
	int nb_colonnes; // nombre de colonnes dans le plateau de jeu

	// afficher le menu tant que le choix 4 n'a pas encore ete choisi
	do {
		ihm_printf("\n Menu:");
		ihm_printf("\n-------");
		ihm_printf("\n(%d) Jouer une partie facile", FACILE);
		ihm_printf("\n(%d) Jouer une partie normale", NORMALE);
		ihm_printf("\n(%d) Jouer une partie difficile", DIFFICILE);
		ihm_printf("\n(%d) Quitter", QUITTER);
		ihm_printf("\nSaisir une valeur entre 1 et 4: ");
		ihm_scanf("%d", &choix);

		switch (choix) {
			// si l'utilisateur choisi 1, 2 ou 3, demander le nombre de colonnes
		case 1:
		case 2:
		case 3:
			// function that scanf choix to set difficulty (?)
			ihm_printf("\n\n***** NOUVELLE PARTIE *****");
			ihm_printf("\nSaisir une valeur entre %d et %d: ", col_min, col_max);
			nb_colonnes = lire_entier(col_min, col_max);

			return nb_colonnes;

			break;

		case 4:
			// message quitter 
			break;

		default:
			// message d'erreur				
		}
	} while (choix != QUITTER);

	// return QUITTER->main program : if io_afficher_menu == 4 quit the game(?)

}

// afficher le plateau de jeu
void io_plateau_afficher(int plateau[], int colonnes) {

	int i;

	// afficher les colonnes
	for (i = 0; i < colonnes - 1; i++) {
		ihm_printf("%d ", colonnes);
	}
	ihm_printf("\n");

	// afficher le nombre de pieces dans la colonne
	for (i = 0; i < colonnes - 1; i++) {
		ihm_printf("%d ", plateau[i]);
	}
}