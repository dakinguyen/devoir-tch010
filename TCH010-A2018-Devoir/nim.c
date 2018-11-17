// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

#include "nim.h"
#include <stdio.h>
#include <stdlib.h>


#define PLATEAU_MAX_PIECES 35
#define PLATEAU_MIN_PIECES 1

// determine qui commence a jouer le premier tour aleatoirement
int nim_qui_commence() {

	return rand() / (RAND_MAX/1.9);
}

// initialiser le plateau de jeu avec un nombre aleatoire de pieces de 1 a 35
void nim_plateau_init(int plateau[], int nb_colonnes) {
	
	int i;

	for (i = 0; i < nb_colonnes; i++) {
		plateau[i] = PLATEAU_MIN_PIECES + rand() / (RAND_MAX / PLATEAU_MAX_PIECES + 1);
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
		}
		nb_colonnes = nb_colonnes - 1;
	}
	return nb_colonnes;
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

