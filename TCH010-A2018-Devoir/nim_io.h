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
permet de lire et valider un entier entre. cette valeur doit se
retrouver entre les bornes du min et du max inclusivement.

Paramètres:
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


Paramètres: Aucun
Retour: Aucun
*/
void afficher_menu(void);

/*
PLATEAU_AFFICHER
affiche la plateau de jeu.

Paramètres: 
- tableau de jeu
- le nombre de colonne que le tableau contient
Retour: Aucun
*/
void plateau_afficher(int plateau[], int colonnes);

/*
TOUR_HUMAIN
joue le tour humain.

Paramètres:
- tableau de jeu
- le nombre de colonnes que le tableau contient
Retour: Aucun
*/
void tour_humain(int plateau[], int nb_colonnes);

/*
TOUR_IA
joue le tour de l'ordinateur.

Paramètres:
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

Paramètres:
- niveau de difficulte
Retour: Aucun
*/
void demarrer_jeu(double difficulte);