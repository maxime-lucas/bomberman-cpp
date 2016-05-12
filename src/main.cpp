#include "Header.h"


//const int MS_PER_UPDATE = 50;

int main(int argc, char *argv[])
{
	// Initialisation :
	//	- Pour centrer la fenêtre dans l'écran
	// 	- Appel de la fonction init()
	
	SDL_Surface *ecran ;
	char config[] = "SDL_VIDEO_CENTERED=center";
	SDL_putenv(config);
	init(&ecran);

	// Intro et Menu principal du jeu :
	start_screen(ecran);
	menu(ecran);

	// Fin du jeu
	SDL_Quit();
	return EXIT_SUCCESS;
}
