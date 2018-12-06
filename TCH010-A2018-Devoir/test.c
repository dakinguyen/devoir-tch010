#include "test.h"


void test_all() {

	test_qui_commence();
	test_plateau_init();
	printf("End of tests!\n");
	system("pause");
}


void test_qui_commence() 
{
	printf("----- Test nim_qui_commence ------\n");
	printf("Il devrait y avoir des 0 ou des 1.\n");

	int nb0 = 0;
	int nbTry = 10;

	for (size_t i = 0; i < nbTry; i++)
	{
		int r = nim_qui_commence();
		printf("%d ,", r);
		if (r == 0)
			nb0++;
	}

	printf("\n\n");
	if (nb0 == nbTry || nb0 == 0)
		printf("[FAIL], retourne toujours la meme valeur.\n\n");
	else
		printf("[SUCESS]\n\n");
}


void test_plateau_init() 
{
	printf("----- Test nim_plateau_init ------\n");
	printf("Ce tableau devrait avoir des valeurs entre 1 et 35 dans les 6 premières valeurs..\n");

	//nsinati
	int erreurRangeValeurs = 0;
	int tab[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	nim_plateau_init(tab, 6);


	for (size_t i = 0; i < 6; i++)
	{
		if (tab[i] > 35 || tab[i] < 1)
			erreurRangeValeurs++;

		printf("%d ,", tab[i]);
	}

	int erreurValeursExterieur = 0;
	for (size_t i = 7; i < 20; i++)
	{
		if (tab[i] != 00)
			erreurValeursExterieur++;
		printf("%d ,", tab[i]);
	}



	printf("\n\n");
	if (erreurRangeValeurs)
		printf("[FAIL], n'a pas de valeurs entre 35.\n");
	else
		printf("[SUCESS]\n");
	if (erreurValeursExterieur)
		printf("[FAIL], a des valeurs non 0 à l'extérieur du nb de colones demandé.\n\n");
	else
		printf("[SUCESS]\n\n");


	printf("\n\n");

}