// Fait par Dat Quang Nguyen et Sara Nguyen
// Fait le 9 novembre 2018
// Jeu de Nim

#include <stdlib.h>
#include "nim_ihm.h"
#include "m_distributions.h"
#include "nim.h"
#include "nim_io.h"

int main(int argc, char *argv[])
{
	md_srand_interne();

	if (!ihm_init_ecran(0, 0)) {
		system("pause");
		return EXIT_FAILURE;
	}

	ihm_printf("Votre coquille du projet fonctionne convenablement. \n");

	ihm_pause();
	return 0;
}
