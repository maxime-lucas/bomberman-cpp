#include "Header.h"
int main( void )
{
   // Variables
   SDL_Surface *ecran ;
    
        // Initialisation :
	//	- Pour centrer la fenêtre dans l'écran (Propre à SQL)
	// 	- Appel de la fonction init() [ Functions.cpp ]
	char config[] = "SDL_VIDEO_CENTERED=center";
	SDL_putenv(config);
	init(&ecran);

        // Animation d'intro
        //playIntro(ecran);
        
        // Animation pour stage 1
        //playStage1(ecran);
        
        // Lancement du jeu
        playGame(ecran);

	// Fin du jeu
        SDL_FreeSurface(ecran);
	SDL_Quit();
	return EXIT_SUCCESS;
}
