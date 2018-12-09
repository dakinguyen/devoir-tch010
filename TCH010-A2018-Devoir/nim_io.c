// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

#include "nim.h"
#include "nim_ihm.h"
#include "nim_io.h"


// verifier la valeur entree par l'utilisateur
int lire_entier(int min, int max) {

	int valeur; // valeur entree par l'utilisateur

	ihm_scanf("%d", &valeur);
	// si la valeur entree par l'utilisateur n'est pas conforme a l'intervalle de valeur demandee, demander d'entrer une autre valeur
	if (valeur < min || valeur > max) {
		do {
			ihm_printf("La valeur entree n'est pas valide, entrez une autre valeur: ");
			ihm_scanf("%d", &valeur);

		} while (valeur < min || valeur > max);
	}

	return valeur;
}

// demander le niveau de difficulté de la partie et le nombre de colonnes utilisees
void afficher_menu(void) {

	int choix; // choix de l'utilisateur

	// afficher le menu tant que le choix 4 n'a pas encore ete choisi
	do {

		ihm_printf("\n MENU:");
		ihm_printf("\n-------");
		ihm_printf("\n(%d) Jouer une partie facile", FACILE);
		ihm_printf("\n(%d) Jouer une partie normale", NORMALE);
		ihm_printf("\n(%d) Jouer une partie difficile", DIFFICILE);
		ihm_printf("\n(%d) Quitter", QUITTER);
		ihm_printf("\nSaisir une valeur entre %d et %d: ", FACILE, QUITTER);
		ihm_scanf("%d", &choix);

		switch (choix) {
			// si l'utilisateur choisit 1, 2 ou 3, commencer une partie selon le niveau de difficulte
		case 1:

			ihm_printf("\n Vous avez choisi de jouer une partie facile.");

			demarrer_jeu(FACILE);

			break;

		case 2:

			ihm_printf("\n Vous avez choisi de jouer une partie normale.");

			demarrer_jeu(NORMALE);

			break;

		case 3:

			ihm_printf("\n Vous avez choisi de jouer une partie difficile.");

			demarrer_jeu(DIFFICILE);

			break;

			// si l'utilisateur choisit 4, quitter le jeu.
		case 4:

			ihm_printf("\n\nJeu termine.");
			break;

			// si l'utilisateur entre une valeur invalide, montrer un message d'erreur
		default:

			ihm_printf("\n\nMauvaise valeur, veuillez entrer une valeur entre %d et %d.", FACILE, QUITTER);

		}
	} while (choix != QUITTER);
}

// afficher le plateau de jeu
void plateau_afficher(int plateau[], int nb_colonnes) {

	int i, j;

	// afficher les pieces dans chaque colonne
	for (i = 0; i < nb_colonnes; i++) {
		for (j = 0; j < plateau[i]; j++) {
			ihm_ajouter_piece(j, i);

		}
	}
}


// declencher le tour de l'humain
void tour_humain(int plateau[], int nb_colonnes) {

	int choix_colonne; // colonne choisie par l'utilisateur
	int choix_nb_pieces; // nombre de pieces a retirer

	// demander a l'utilisateur de choisir une colonne
	ihm_printf("Choisissez une colonne.\n");
	choix_colonne = ihm_choisir_colonne();

	// demander a l'utilisateur le nombre de pieces a enlever
	ihm_printf("Entrez le nombre de pieces a enlever: ");
	choix_nb_pieces = lire_entier(PLATEAU_MIN_PIECES, plateau[choix_colonne]);

	// appliquer les changements au plateau
	nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}


// declencer le tour de l'ordinateur
void tour_ia(int plateau[], int nb_colonnes, double difficulte) {

	int choix_colonne = 0; // colonne choisie par l'ordinateur
	int choix_nb_pieces = 0; // nombre de pieces a retirer

	nim_choix_ia(plateau, nb_colonnes, difficulte, &choix_colonne, &choix_nb_pieces);

	// appliquer les changements au plateau
	ihm_printf("\ncolonne : %d --- pieces : %d\n", choix_colonne, choix_nb_pieces);
	ihm_pause();
	nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}

// controler le jeu de nim
void demarrer_jeu(double difficulte) {

	int nb_colonnes; // nombre de colonnes actuel
	int plateau_jeu[NB_COLONNE_MAX]; // plateau vide avec nombre de colonne maximal
	int joueur_actuel; // joueur actuel

	ihm_effacer_ecran();

	ihm_printf("Vous commencez une nouvelle partie! :)\n");

	// demander le nombre de colonnes 
	ihm_printf("Entrez le nombre de colonnes desire entre %d et %d: ", NB_COLONNE_MIN, NB_COLONNE_MAX);
	nb_colonnes = lire_entier(NB_COLONNE_MIN, NB_COLONNE_MAX);

	nim_plateau_init(plateau_jeu, nb_colonnes);

	// afficher le nouveau plateau de jeu
	ihm_changer_taille_plateau(PLATEAU_MAX_PIECES, nb_colonnes);
	plateau_afficher(plateau_jeu, nb_colonnes);

	// decider et afficher celui qui commence
	joueur_actuel = nim_qui_commence();

	if (joueur_actuel == 0) {
		ihm_printf("Le IA commence.\n");
	}
	else {
		ihm_printf("Vous commencez. \n");
	}

	// tant qu'il reste des colonnes, alterner les joueurs et changer le plateau de jeu a chaque coup
	while (nb_colonnes != 0) {
		if (joueur_actuel == 1) {
			tour_humain(plateau_jeu, nb_colonnes);
		}
		else {
			tour_ia(plateau_jeu, nb_colonnes, difficulte);
		}

		nb_colonnes = nim_plateau_defragmenter(plateau_jeu, nb_colonnes);

		if (nb_colonnes != 0) {
			if (joueur_actuel == 1) {
				joueur_actuel = 0;
			}
			else {
				joueur_actuel = 1;
			}
		}

		ihm_changer_taille_plateau(PLATEAU_MAX_PIECES, nb_colonnes);
		plateau_afficher(plateau_jeu, nb_colonnes);
	}

	// afficher le gagnant
	if (joueur_actuel == 1) {
		ihm_printf("\nL'ordinateur a gagne :(\n\n");
	}
	else {
		ihm_printf("Vous avez gagne XD\n\n");
	}

	ihm_pause();

}
