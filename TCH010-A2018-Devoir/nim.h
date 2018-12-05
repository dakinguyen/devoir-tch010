// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

// Declaration des constantes
#define PLATEAU_MAX_PIECES 35
#define PLATEAU_MIN_PIECES 1
#define FACILE 1 // choix pour faire une partie facile
#define NORMALE 2 // choix pour faire une partie normale
#define DIFFICILE 3 // choix pour faire une partie difficile
#define QUITTER 4 // choix pour quitter la partie
#define NB_FIBO 9 // nombre de nombres utilises dans la suite de fibonacci

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
- nim_choix_ia_strategie1: Calcule le coup de l'ordinateur.
- nim_choix_piece_ia: Retourne le nombre de pièces qui seront prises par l'ordinateur.

*/

/*
NIM_QUI_COMMENCE

Paramètres: Aucun
Retour: Retourne 0 ou 1, 0 comme etant l'ordinateur et 1 comme etant le joueur humain
*/
int nim_qui_commence(void);

/*
NIM_PLATEAU_INIT

Paramètres:
Retour: Aucun
*/
void nim_plateau_init(int plateau[], int nb_colonnes);

/*
NIM_PLATEAU_SUPPRIMER_COLONNE

Paramètres:
- plateau[] (entier): le tableau de jeu
- nb_colonnes (entier): le nombre de colonnes
- col_a_supprimer (entier): la colonne a supprimer
Retour: Aucun
*/
void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);

/*NIM_PLATEAU_DEFRAGMENTER

Paramètres:
- plateau[] (entier): le tableau de jeu
- nb_colonnes (entier): le nombre de colonnes
Retour: Le nombre de colonnes restants
*/
int nim_plateau_defragmenter(int plateau[], int nb_colonnes);

/*
NIM_JOUER_TOUR

Paramètres:
- plateau[] (entier): le tableau de jeu
- nb_colonnes (entier): le nombre de colonnes
- colonne (entier): la colonne jouee
- nb_pieces (entier): le nombre de pieces dans la colonne
Retour: Si le tour joue est valide ou non
*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);

/*
NIM_CHOIX_IA

Paramètres:
- plateau (entier): le plateau de jeu
- nb_colonnes (entier): le nombre de colonnes
- difficulte (flottant double): le nombre representant la difficulte choisie par l'utilisateur (facile = 1, normale = 2, difficile = 3)
- *choix_colonne (entier):
Retour: Aucun
*/
void nim_choix_ia(const int plateau[], int nb_colonnes, double difficulte, int *choix_colonne, int *choix_nb_pieces);

/*
NIM_CHOIX_IA_ALEATOIRE

Paramètres:
- plateau (entier): le plateau de jeu
- nb_colonnes (entier): le nombre de colonnes
Retour: Aucun
*/
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces);

/*
NIM_CHOIX_IA_STRATEGIE1

Paramètres:
Retour: Aucun
*/
void nim_choix_ia_strategie1(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces);

/*
NIM_CHOIX_PIECE_IA

Paramètres:
- nb_pieces:
Retour: Aucun
*/
int nim_choix_piece_ia(int nb_pieces);
