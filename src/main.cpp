#include "Header.h"


//const int MS_PER_UPDATE = 50;

int main(int argc, char *argv[])
{
        Timer fps;
        SDL_Surface *ecran ;
    
        // Initialisation :
	//	- Pour centrer la fen�tre dans l'�cran
	// 	- Appel de la fonction init()
	char config[] = "SDL_VIDEO_CENTERED=center";
	SDL_putenv(config);
	init(&ecran);

        // Intro
        Animation *intro = new Animation("img/animations/intro/%d.png", 90);
        for(int i = 0; i <  intro->getNbFrames() ; i++)
        {
            fps.start();
            
            intro->render(ecran);
            intro->nextFrame();
            SDL_Flip(ecran);
            
            while( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {}
            fps.stop();
        }
        
        // Stage 1
        Animation *stage1 = new Animation("img/animations/stage1/%d.png", 42);
        for(int i = 0; i <  stage1->getNbFrames() ; i++)
        {
            fps.start();
            
            stage1->render(ecran);
            stage1->nextFrame();
            SDL_Flip(ecran);
            
            while( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {}
            fps.stop();
        }
        
        // Lancement du jeu
        play(ecran);

	// Fin du jeu
        SDL_FreeSurface(ecran);
	SDL_Quit();
	return EXIT_SUCCESS;
}
