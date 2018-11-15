// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

/*
MODULE NIM

Module qui agit comme le � cerveau � du programme.

Le module comporte des fonctions permettant au programme de g�rer le plateau de jeu en m�moire et celles permettant le calcul de la strat�gie de l'ordinateur, incluant:

- nim_qui_commence: D�termine al�atoirement qui doit jouer en premier.
- nim_plateau_init: Initialise le plateau en remplissant les nb_colonnes avec un nombre al�atoire de pi�ces entre 1 et 35.
- nim_plateau_supprimer_colonne: Supprime la colonne col_a_supprimer du plateau.
- nim_plateau_defragmenter: Supprime les colonnes vides du tableau et retourne le nombre de colonnes restant.
- nim_jouer_tour: Retire "nb_pieces" de la colonne "colonne" du plateau.
- nim_choix_ia: D�termine le coup de l'ordinateur selon la difficult� choisie.
- nim_choix_ia_aleatoire: Effectue un coup al�atoire en choisissant au hasard une colonne et un nombre de pi�ces de celle-ci.
- nim_choix_ia_strategiel: Calcule le coup de l'ordinateur.
- nim_choix_piece_ia: Retourne le nombre de pi�ces qui seront prises par l'ordinateur.

*/

/*
NIM_QUI_COMMENCE

Param�tres: Aucun
Retour:
*/
int nim_qui_commence(void);

/*
NIM_PLATEAU_INIT

Param�tres:
Retour: Aucun
*/
void nim_plateau_init(int plateau[], int nb_colonnes);

/*
NIM_PLATEAU_SUPPRIMER_COLONNE

Param�tres:
Retour: Aucun
*/
void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int colonne, int nb_pieces);

/*
NIM_JOUER_TOUR

Param�tres:
Retour:
*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);