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
Demande à l'usager de saisir un entier entre les bornes min et max
(inclusivement). La fonction doit valider la saisie et redemander à l'usager
de saisir une valeur jusqu'à l'obtention d'une valeur satisfaisante.

Paramètres:
- min (entier): borne inferieure
- max (entier): borne superieure
Retour: (entier) Une valeur qui se retrouve dans les bornes
*/
int lire_entier(int min, int max);

/*
AFFICHER_MENU
Demande à l'utilisateur le niveau de difficulté de la partie et le nombre de
colonne dans le jeu. Ce programme démarre le jeu avec le bon
niveau de difficulté et le nombre de colonne.

Paramètres: Aucun
Retour: Aucun
*/
void afficher_menu(void);

/*
PLATEAU_AFFICHER
Affiche la configuration du plateau à l'écran. Elle affiche chacune des
colonnes en mettant une pièce par ligne, selon le nombre de pièces présentes
dans la colonne en question.

Paramètres: 
- plateau[] (entier): tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
Retour: Aucun
*/
void plateau_afficher(int plateau[], int nb_colonnes);

/*
TOUR_HUMAIN
Déclenche le tour de l'humain en demandant à l'usager de choisir la colonne
(appel à ihm_choisir_colonne) et le nombre de pièces à retirer du plateau de
jeu. Une fois le choix effectué, la fonction doit faire appel à
nim_jouer_tour pour appliquer les changements au plateau.

Paramètres:
- plateau[] (entier): tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
Retour: Aucun
*/
void tour_humain(int plateau[], int nb_colonnes);

/*
TOUR_IA
Déclenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur,
on fait appel à la fonction nim_choix_ia.
Une fois le choix effectué, la fonction doit faire appel à nim_jouer_tour
pour appliquer les changements au plateau.

Paramètres:
- plateau[] (entier): tableau de jeu
- nb_colonnes (entier): nombre de colonnes que le tableau contient
- difficulte (entier): niveau de difficulte
Retour: Aucun
*/
void tour_ia(int plateau[], int nb_colonnes, double difficulte);

/*
DEMARRER_JEU
Fonction qui contrôle le jeu de nim: elle donne la main, tour à tour, à
chacun des deux joueurs et déclare le gagnant une fois la partie terminée.
On quitte cette fonction quand la partie est terminée.
Pour donner la main aux joueurs, on appelle les fonctions tour_humain et
tour_ia. Après chaque tour, cette fonction se charge de défragmenter le
plateau de jeu, de modifier la taille du plateau à l'écran et d'afficher la
nouvelle configuration du plateau de jeu.

Paramètres:
- difficulte (entier): niveau de difficulte
Retour: Aucun
*/
void demarrer_jeu(double difficulte);