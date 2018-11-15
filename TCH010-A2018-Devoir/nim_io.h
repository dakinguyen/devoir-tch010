// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

/* 
MODULE NIM_IO

Module qui assure l'interactivité du jeu avec l'usager.

Le module comporte des fonctions permmettant de gérer le jeu, incluant:

- io_demarrer_jeu: Gère le jeu en alternant entre les joueurs.
- io_lire_entier: Demande à l'usager un entier entre les bornes min et max inclusivement.
- io_afficher_menu: Demande à l'usager la difficulté et le nombres de colonnes utilisées dans la partie.
- io_plateau_afficher: Affiche le plateau de jeu à l'écran au fur et à mesure.
- io_tour_humain: Déclenche le tour de l'usager en lui demandant de choisir la colonne et le nombre de pièces à retirer du plateau.
- io_tour_ia: Déclenche le tour de l'ordinateur.
*/

/*
IO_LIRE_ENTIER

Paramètres: 
Retour:
*/
int io_lire_entier(int min, int max);

/*
IO_AFFICHER_MENU

Paramètres: Aucun
Retour:
*/
int io_afficher_menu(void);

/*
IO_PLATEAU_AFFICHER

Paramètres:
Retour: Aucun
*/
void io_plateau_afficher(int plateau[], int colonnes);