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
permet de lire et valider un entier entre. cette valeur doit se
retrouver entre les bornes du min et du max inclusivement.

Param�tres:
- borne inferieure
- borne superieure
Retour: 
- valeur qui se retrouve dans les bornes
*/
int lire_entier(int min, int max);

/*
AFFICHER_MENU
affiche un menu qui demande a l'utilisateur le niveau de difficulte 
a laquelle il veut jouer. avec ce menu, selon la difficulte 
selectionnee, il peut jouer au jeu de nim.


Param�tres: Aucun
Retour: Aucun
*/
void afficher_menu(void);

/*
PLATEAU_AFFICHER
affiche la plateau de jeu.

Param�tres: 
- tableau de jeu
- le nombre de colonne que le tableau contient
Retour: Aucun
*/
void plateau_afficher(int plateau[], int colonnes);

/*
TOUR_HUMAIN
joue le tour humain.

Param�tres:
- tableau de jeu
- le nombre de colonnes que le tableau contient
Retour: Aucun
*/
void tour_humain(int plateau[], int nb_colonnes);

/*
TOUR_IA
joue le tour de l'ordinateur.

Param�tres:
- tableau de jeu
- nombre de colonnes que le tableau contient
- niveau de difficulte
Retour: Aucun
*/
void tour_ia(int plateau[], int nb_colonnes, double difficulte);

/*
DEMARRER_JEU
demarre le jeu et permet a l'utilisateur de jouer en choisissant la
difficulte desiree.

Param�tres:
- niveau de difficulte
Retour: Aucun
*/
void demarrer_jeu(double difficulte);