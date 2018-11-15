// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

/* 
MODULE NIM_IO

Module qui assure l'interactivit� du jeu avec l'usager.

Le module comporte des fonctions permmettant de g�rer le jeu, incluant:

- io_demarrer_jeu: G�re le jeu en alternant entre les joueurs.
- io_lire_entier: Demande � l'usager un entier entre les bornes min et max inclusivement.
- io_afficher_menu: Demande � l'usager la difficult� et le nombres de colonnes utilis�es dans la partie.
- io_plateau_afficher: Affiche le plateau de jeu � l'�cran au fur et � mesure.
- io_tour_humain: D�clenche le tour de l'usager en lui demandant de choisir la colonne et le nombre de pi�ces � retirer du plateau.
- io_tour_ia: D�clenche le tour de l'ordinateur.
*/

/*
IO_LIRE_ENTIER

Param�tres: 
Retour:
*/
int io_lire_entier(int min, int max);

/*
IO_AFFICHER_MENU

Param�tres: Aucun
Retour:
*/
int io_afficher_menu(void);

/*
IO_PLATEAU_AFFICHER

Param�tres:
Retour: Aucun
*/
void io_plateau_afficher(int plateau[], int colonnes);