// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

/*
MODULE NIM

Module qui agit comme le « cerveau » du programme.

Le module comporte des fonctions permettant au programme de gérer le plateau de jeu en mémoire et celles permettant le calcul de la stratégie de l'ordinateur, incluant:

- nim_qui_commence: Détermine aléatoirement qui doit jouer en premier.
- nim_plateau_init: Initialise le plateau en remplissant les nb_colonnes avec un nombre aléatoire de pièces entre 1 et 35.
- nim_plateau_supprimer_colonne: Supprime la colonne col_a_supprimer du plateau.
- nim_plateau_defragmenter: Supprime les colonnes vides du tableau et retourne le nombre de colonnes restant.
- nim_jouer_tour: Retire "nb_pieces" de la colonne "colonne" du plateau.
- nim_choix_ia: Détermine le coup de l'ordinateur selon la difficulté choisie.
- nim_choix_ia_aleatoire: Effectue un coup aléatoire en choisissant au hasard une colonne et un nombre de pièces de celle-ci.
- nim_choix_ia_strategiel: Calcule le coup de l'ordinateur.
- nim_choix_piece_ia: Retourne le nombre de pièces qui seront prises par l'ordinateur.

*/

// determine qui commence a jouer le premier tour aleatoirement
int nim_qui_commence() {

	int premier_joueur;
	// random joueur entre 1 et 0
	// premier_joueur = ...

	// return premier_joueur;
}

// initialiser le plateau de jeu avec un nombre aleatoire de pieces
void nim_plateau_init(int plateau[], int nb_colonnes) {


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

// valider le choix de l'utilisateur et enlever la piece si elle fonctionne
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces) {

	int valide = 0;

	// si la colonne entree par l'utilisateur existe et que le nombre de piece est bonne, le choix est valide
	if (colonne <= nb_colonnes && nb_pieces < plateau[colonne]) {
		valide = 1;
	}

	return valide;
}

