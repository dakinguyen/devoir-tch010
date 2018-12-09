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
Demande � l'usager de saisir un entier entre les bornes min et max
(inclusivement). La fonction doit valider la saisie et redemander � l'usager
de saisir une valeur jusqu'� l'obtention d'une valeur satisfaisante.

Param�tres:
- min (entier): borne inferieure
- max (entier): borne superieure
Retour: (entier) Une valeur qui se retrouve dans les bornes
*/
int lire_entier(int min, int max);

/*
AFFICHER_MENU
Demande � l'utilisateur le niveau de difficult� de la partie et le nombre de
colonne dans le jeu. Ce programme d�marre le jeu avec le bon
niveau de difficult� et le nombre de colonne.

Param�tres: Aucun
Retour: Aucun
*/
void afficher_menu(void);

/*
PLATEAU_AFFICHER
Affiche la configuration du plateau � l'�cran. Elle affiche chacune des
colonnes en mettant une pi�ce par ligne, selon le nombre de pi�ces pr�sentes
dans la colonne en question.

Param�tres: 
- plateau[] (entier): tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
Retour: Aucun
*/
void plateau_afficher(int plateau[], int nb_colonnes);

/*
TOUR_HUMAIN
D�clenche le tour de l'humain en demandant � l'usager de choisir la colonne
(appel � ihm_choisir_colonne) et le nombre de pi�ces � retirer du plateau de
jeu. Une fois le choix effectu�, la fonction doit faire appel �
nim_jouer_tour pour appliquer les changements au plateau.

Param�tres:
- plateau[] (entier): tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
Retour: Aucun
*/
void tour_humain(int plateau[], int nb_colonnes);

/*
TOUR_IA
D�clenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur,
on fait appel � la fonction nim_choix_ia.
Une fois le choix effectu�, la fonction doit faire appel � nim_jouer_tour
pour appliquer les changements au plateau.

Param�tres:
- plateau[] (entier): tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
- difficulte (entier): niveau de difficulte
Retour: Aucun
*/
void tour_ia(int plateau[], int nb_colonnes, double difficulte);

/*
DEMARRER_JEU
Fonction qui contr�le le jeu de nim: elle donne la main, tour � tour, �
chacun des deux joueurs et d�clare le gagnant une fois la partie termin�e.
On quitte cette fonction quand la partie est termin�e.
Pour donner la main aux joueurs, on appelle les fonctions tour_humain et
tour_ia. Apr�s chaque tour, cette fonction se charge de d�fragmenter le
plateau de jeu, de modifier la taille du plateau � l'�cran et d'afficher la
nouvelle configuration du plateau de jeu.

Param�tres:
- difficulte (entier): niveau de difficulte
Retour: Aucun
*/
void demarrer_jeu(double difficulte);