// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

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

