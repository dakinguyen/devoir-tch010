// Fait par Dat Quang Nguyen
// 9 novembre 2018
// Fichier de fonctions
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// verifier la valeur entree par l'utilisateur
int lire_entier(int min, int max) {

	int valeur; // valeur entree par l'utilisateur

	scanf("%d", &valeur);
	// si la valeur entree par l'utilisateur n'est pas conforme a l'intervalle de valeur demandee, demander d'entrer une autre valeur
	if (valeur < min || valeur > max) {
		do {
			printf("La valeur entree n'est pas valide, entree une autre valeur: ");
			scanf("%d", &valeur);

		} while (valeur < min || valeur > max);
	}

	return valeur;
}

// initialiser le plateau de jeu avec un nombre aleatoire de pieces
void nim_plateau_init(int plateau[], int nb_colonnes) {


}

// afficher le plateau de jeu
void plateau_afficher(int plateau[], int colonnes) {

	int i;

	// afficher les colonnes
	for (i = 0; i < colonnes - 1; i++) {
		printf("%d ", colonnes);
	}
	printf("\n");

	// afficher le nombre de pieces dans la colonne
	for (i = 0; i < colonnes - 1; i++) {
		printf("%d ", plateau[i]);
	}
}

// determine qui commence a jouer le premier tour aleatoirement
int nim_qui_commence() {

	int premier_joueur;
	// random joueur entre 1 et 0
	// premier_joueur = ...

	// return premier_joueur;
}

// valider le choix de l'utilisateur et enlever la piece si elle fonctionne
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces) {

	int valide = 0;

	// si la colonne entree par l'utilisateur existe et que le nombre de piece est bonne, le choix est valide
	if (colonne <= nb_colonnes && nb_pieces < plateau[colonne]) {
		valide = 1;
	}

	return valide;
}

// supprimer une colonne du plateau
void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int colonne, int nb_pieces) {

	int col_a_supprimer;
	int i;

	for (i = 0; i <= nb_colonnes - 1; i++) {
		if (plateau[i] == 0) {
			for (col_a_supprimer = i; col_a_supprimer <= nb_colonnes - 1; col_a_supprimer++) {
				plateau[col_a_supprimer] = plateau[col_a_supprimer + 1];
			}
			nb_colonnes = nb_colonnes - 1;
		}
	}

}