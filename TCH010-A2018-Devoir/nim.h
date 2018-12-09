// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

// Declaration des constantes
#define PLATEAU_MAX_PIECES 35 // nombre maximum
#define FACILE 1 // choix pour faire une partie facile
#define NORMALE 2 // choix pour faire une partie normale
#define DIFFICILE 3 // choix pour faire une partie difficile
#define QUITTER 4 // choix pour quitter la partie
#define NB_FIBO 9 // nombre de nombres utilises dans la suite de fibonacci

#include "m_distributions.h"

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
- nim_choix_ia_strategie1: Calcule le coup de l'ordinateur.
- nim_choix_piece_ia: Retourne le nombre de pi�ces qui seront prises par l'ordinateur.

*/

/*
NIM_QUI_COMMENCE
Fonction qui d�termine, al�atoirement, qui doit jouer en premier. Elle
retourne l'identifiant du joueur (JOUEUR_HUMAIN==0 ou JOUEUR_IA==1).

Param�tres: Aucun
Retour: Retourne 0 ou 1, 0 comme etant l'ordinateur et 1 comme etant le joueur humain
*/
int nim_qui_commence(void);

/*
NIM_PLATEAU_INIT
Initialise le plateau de jeu en remplissant les nb_colonnes d'un nombre
al�atoire de pi�ces entre 1 et PLATEAU_MAX_PIECES=35.

Param�tres:
- plateau[] (entier): le tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
Retour: Aucun
*/
void nim_plateau_init(int plateau[], int nb_colonnes);

/*
NIM_PLATEAU_SUPPRIMER_COLONNE
Supprime la colonne col_a_supprimer du plateau. Pour supprimer une colonne,
on d�cale les colonnes situ� � droite de la col_a_supprimer d'une position
vers la gauche.

Param�tres:
- plateau[] (entier): le tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
- col_a_supprimer (entier): la colonne a supprimer
Retour: Aucun
*/
void nim_plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);

/*NIM_PLATEAU_DEFRAGMENTER
Fonction qui supprime les colonnes vides du tableau en utilisant la fonction
nim_plateau_supprimer_colonne. Le nombre de colonnes restant est retourn�.

Param�tres:
- plateau[] (entier): le tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
Retour: Le nombre de colonnes restants
*/
int nim_plateau_defragmenter(int plateau[], int nb_colonnes);

/*
NIM_JOUER_TOUR
Applique des changements � la configuration du plateau de jeu en retirant
"nb_pieces" de la colonne "colonne" du plateau.
La fonction s'assure que le coup est valide et renvoie Vrai si le coup
d�sir� a pu s'appliquer � la configuration actuelle du jeu.
Pour �tre valide, la colonne doit exister et le nombre de pi�ces retir�es
doit �tre inf�rieure ou �gale au nombre de pi�ces actuellement pr�sentes
dans la colonne en question.

Param�tres:
- plateau[] (entier): le tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
- colonne (entier): la colonne jouee
- nb_pieces (entier): le nombre de pieces choisies dans la colonne
Retour: Si le tour joue est valide (1) ou non(0)
*/
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);

/*
NIM_CHOIX_IA
Fonction qui d�termine quel doit �tre le coup de l'ordinateur. Cette
fonction impl�mente l'algorithme d�crit dans l'�nonc� du TP. Le choix de
l'ordinateur sera stock� dans les r�f�rences choix_colonne et
choix_nb_pieces.
Dans un partie facile, l'ordinateur utilise la fonction
nim_choix_ia_aleatoire pour choisir son coup.
Dans une partie interm�diaire, l'ordinateur utilise la fonction
nim_choix_ia_aleatoire lors de 50% de ces coups. Alternativement, il utilise
la fonction nim_choix_ia_strategie1.
Dans une partie difficile, l'ordinateur utilise la fonction
nim_choix_ia_strategie1 pour choisir son coup.

Param�tres:
- plateau (entier): le plateau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
- difficulte (flottant double): le nombre representant la difficulte choisie par l'utilisateur (facile = 1, normale = 2, difficile = 3)
- *choix_colonne (entier): pointeur vers le parametre du choix de colonne
- *choix_nb_pieces (entier): pointeur vers le parametre du choix du nombre de pieces
Retour: Aucun
*/
void nim_choix_ia(const int plateau[], int nb_colonnes, double difficulte, int *choix_colonne, int *choix_nb_pieces);

/*
NIM_CHOIX_IA_ALEATOIRE
Fonction qui effectue un coup al�atoire en choisissant au hasard une
colonne, puis au hasard le nombre de pi�ces � jouer de cette colonne.

Param�tres:
- plateau (entier): le plateau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
- *choix_colonne (entier): pointeur vers le parametre du choix de colonne
- *choix_nb_pieces (entier): pointeur vers le parametre du choix du nombre de pieces
Retour: Aucun
*/
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces);

/*
NIM_CHOIX_IA_STRATEGIE1
Calcule le coup de l�ordinateur. Le coup de l�ordinateur est stock� dans les
r�f�rences choix_colonne et choix_nb_pieces.
L'ordinateur trouve la colonne du plateau qui contient le plus de pi�ces.
Ensuite, elle utilise la fonction nim_choix_piece_ia pour d�terminer le
nombre de pi�ces qu'elle y prendra.

Param�tres:
- plateau (entier): le plateau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
- *choix_colonne (entier): pointeur vers le parametre du choix de colonne
- *choix_nb_pieces (entier): pointeur vers le parametre du choix du nombre de pieces
Retour: Aucun
*/
void nim_choix_ia_strategie1(const int plateau[], int nb_colonnes, int *choix_colonne, int *choix_nb_pieces);

/*
NIM_CHOIX_PIECE_IA
Cette fonction retourne le nombre de pi�ces qui seront prises par
l'ordinateur. Ce nombre correspond au plus grand terme de la suite de
Fibonacci qui ne d�passe pas le nombre de pi�ces dans la colonne.

Param�tres:
- nb_pieces (entier): le nombre de pieces choisies dans la colonne
Retour: Aucun
*/
int nim_choix_piece_ia(int nb_pieces);
