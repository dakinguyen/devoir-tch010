// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

/*
MODULE NIM_IO

Module qui assure l'interactivit� du jeu avec l'usager.

Le module comporte des fonctions permmettant de g�rer le jeu, incluant:

- demarrer_jeu: G�re le jeu en alternant entre les joueurs.
- lire_entier: Demande � l'usager un entier entre les bornes min et max inclusivement.
- afficher_menu: Demande � l'usager la difficult� et le nombres de colonnes utilis�es dans la partie.
- plateau_afficher: Affiche le plateau de jeu � l'�cran au fur et � mesure.
- tour_humain: D�clenche le tour de l'usager en lui demandant de choisir la colonne et le nombre de pi�ces � retirer du plateau.
- tour_ia: D�clenche le tour de l'ordinateur.
*/

/*
LIRE_ENTIER

Param�tres:
Retour:
*/
int lire_entier(int min, int max);

/*
AFFICHER_MENU

Param�tres: Aucun
Retour:
*/
void afficher_menu(void);

/*
PLATEAU_AFFICHER

Param�tres:
Retour: Aucun
*/
void plateau_afficher(int plateau[], int colonnes);

/*
TOUR_HUMAIN

Param�tres:
Retour: Aucun
*/
void tour_humain(int plateau[], int nb_colonnes);

/*
TOUR_IA

Param�tres:
Retour: Aucun
*/
void tour_ia(int plateau[], int nb_colonnes, double difficulte);

/*
DEMARRER_JEU

Param�tres:
Retour: Aucun
*/
void demarrer_jeu(double difficulte);