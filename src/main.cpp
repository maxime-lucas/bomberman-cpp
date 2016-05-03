#include "Header.h"
#include "Classes.h"

int main(int argc, char* argv[])
{
	bool quit = false;
	SDL_Event event;
	
	SDL_Surface *ecran;
	
	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Bomberman tro kool", NULL);
	
	Mario *mario = new Mario();
	Bomber *bomber = new Bomber();
	
	mario->show(ecran);
	bomber->show(ecran);
	
	SDL_Flip(ecran);
	while( !quit )
	{
		while(SDL_PollEvent( &event ) ) 
		{
			if( event.type == SDL_QUIT ) { 
				//On quitte le programme 
				quit = true; 
			}
		}
	}
	
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
