#include "Header.h"
#include "Classes.h"

int main(int argc, char* argv[])
{
	SDL_Surface *ecran;
	
	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Bomberman tro kool", NULL);
	
	Input in;
	Timer fps;
	memset(&in, 0, sizeof(in));
	
	Bomber *player1 = new Bomber();
	player1->show(ecran);
	SDL_Flip(ecran);
	
	while(in.quit == 0)
	{
		fps.start();
		UpdateEvents(&in);
		if ( in.key[SDLK_UP] )
		{
			player1->MoveUp();
			
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
			player1->show(ecran);
			SDL_Flip(ecran);
		}
		
		if ( in.key[SDLK_RIGHT] )
		{
			player1->MoveRight();
			
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
			player1->show(ecran);
			SDL_Flip(ecran);
		}
		
		if ( in.key[SDLK_LEFT] )
		{
			player1->MoveLeft();
			
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
			player1->show(ecran);
			SDL_Flip(ecran);
		}
		
		if ( in.key[SDLK_DOWN] )
		{
			player1->MoveDown();
			
			SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
			player1->show(ecran);
			SDL_Flip(ecran);
		}
		
		while( fps.get_ticks() < 2000 / FRAMES_PER_SECOND )
     {
         //On attend
     }
		
	}
		
	//start_screen(ecran);
	
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
