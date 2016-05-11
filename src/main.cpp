#include "Header.h"

int main(int argc, char* argv[])
{
	// Initialisation
	SDL_Surface *ecran ;
	SDL_putenv("SLD_VIDEO_CENTERED=center");
	init(&ecran); 
	
	start_screen_2(ecran);
	play(ecran);
	
	// Fin du jeu
	SDL_Quit();
	return EXIT_SUCCESS;
}
