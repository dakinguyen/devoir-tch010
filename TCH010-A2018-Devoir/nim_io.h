// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

/*
MODULE NIM_IO

Module qui assure l'interactivité du jeu avec l'usager.

Le module comporte des fonctions permmettant de gérer le jeu, incluant:

- demarrer_jeu: Gère le jeu en alternant entre les joueurs.
- lire_entier: Demande à l'usager un entier entre les bornes min et max inclusivement.
- afficher_menu: Demande à l'usager la difficulté et le nombres de colonnes utilisées dans la partie.
- plateau_afficher: Affiche le plateau de jeu à l'écran au fur et à mesure.
- tour_humain: Déclenche le tour de l'usager en lui demandant de choisir la colonne et le nombre de pièces à retirer du plateau.
- tour_ia: Déclenche le tour de l'ordinateur.
*/

/*
LIRE_ENTIER

Paramètres:
Retour:
*/
int lire_entier(int min, int max);

/*
AFFICHER_MENU

Paramètres: Aucun
Retour:
*/
void afficher_menu(void);

/*
PLATEAU_AFFICHER

Paramètres:
Retour: Aucun
*/
void plateau_afficher(int plateau[], int colonnes);

/*
TOUR_HUMAIN

Paramètres:
Retour: Aucun
*/
void tour_humain(int plateau[], int nb_colonnes);

/*
TOUR_IA

Paramètres:
Retour: Aucun
*/
void tour_ia(int plateau[], int nb_colonnes, double difficulte);

/*
DEMARRER_JEU

Paramètres:
Retour: Aucun
*/
void demarrer_jeu(double difficulte);