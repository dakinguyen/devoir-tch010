// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

#include "nim.h"
#include <stdio.h>
#include <stdlib.h>
#include "m_distributions.h"

// determine qui commence a jouer le premier tour aleatoirement
int nim_qui_commence() {

	return md_randi(2) - 1;
}

// initialiser le plateau de jeu avec un nombre aleatoire de pieces de 1 a 35
void nim_plateau_init(int plateau[], int nb_colonnes) {

	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = md_randi(PLATEAU_MAX_PIECES);
	}

}

// supprimer une colonne du plateau
void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer) {

	int i;

	for (i = col_a_supprimer; i < nb_colonnes; i++) {
		plateau[i] = plateau[i + 1];
	}
}

// supprimer les colonnes vides du tableau
int nim_plateau_defragmenter(int plateau[], int nb_colonnes) {

	int i;

	for (i = 0; i < nb_colonnes; i++) {
		if (plateau[i] == 0) {
			nim_plateau_supprimer_colonne(plateau, nb_colonnes, i);
			nb_colonnes = nb_colonnes - 1;
		}
	}
	return nb_colonnes;
}

// valider le choix de l'utilisateur et enlever les pieces si elle fonctionne
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces) {

	int valide = 0;

	// si la colonne entree par l'utilisateur existe et que le nombre de piece est bonne, le choix est valide et enlever les pieces
	if (colonne < nb_colonnes && nb_pieces <= plateau[colonne]) {
		valide = 1;
		plateau[colonne] -= nb_pieces;

	}
	return valide;
}

// determiner le coup de l'ordinateur
void nim_choix_ia(const int plateau[], int nb_colonnes, double difficulte, int *choix_colonne, int *choix_nb_pieces) {

	int ia_tour = md_randi(2) - 1;

	if (difficulte == FACILE) {

		nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
	}

	if (difficulte == NORMALE) {

		if (ia_tour == 0) {

			nim_choix_ia_aleatoire(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
		}
		else {

			nim_choix_ia_strategie1(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
		}
	}

	if (difficulte == DIFFICILE) {

		nim_choix_ia_strategie1(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
	}
}


// effectuer un coup aleatoire
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces) {

	*choix_colonne = md_randi(nb_colonnes) - 1;
	*choix_nb_pieces = md_randi(plateau[*choix_colonne]);

}



// effectuer un coup calcule
void nim_choix_ia_strategie1(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces) {

	int i;

	// trouver la colonne ayant le plus de pieces
	*choix_colonne = 0;
	for (i = 0; i < nb_colonnes; i++) {

		if (plateau[i] > plateau[*choix_colonne]) {

			*choix_colonne = i;
		}
	}

	*choix_nb_pieces = nim_choix_piece_ia(plateau[*choix_colonne]);

}


// retourner le nombre de pieces prises par l'ordinateur pour une partie difficile
int nim_choix_piece_ia(int nb_pieces) {

	int nb_fibonacci[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34 }; // suite de fibonacci
	int i;

	for (i = 0; i < NB_FIBO; i++) {

		if (nb_pieces == PLATEAU_MAX_PIECES) {

			return nb_fibonacci[NB_FIBO - 1];

		}
		else if (nb_fibonacci[i] < nb_pieces) {

		}
		else if (nb_fibonacci[i] == nb_pieces) {

			return nb_fibonacci[i];

		}
		else {

			return nb_fibonacci[i - 1];

		}

	}

}

