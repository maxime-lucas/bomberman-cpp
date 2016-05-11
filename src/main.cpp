#include "Header.h"

//const int MS_PER_UPDATE = 50;

int main(int argc, char *argv[])
{
	// Initialisation
	SDL_Surface *ecran ;
	SDL_putenv("SDL_VIDEO_CENTERED=center");
	init(&ecran);

	start_screen(ecran);
	menu(ecran);

	// Fin du jeu
	SDL_Quit();
	return EXIT_SUCCESS;
}
