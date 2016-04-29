#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>


int main(int argc, char *argv[])

{

    	SDL_Surface *ecran = NULL , *figure = NULL;
    	SDL_Rect positionFigure, positionEcran;
	int tempsPrecedent = 0, tempsActuel = 0;

	positionEcran.x = 0;
	positionEcran.y = 0;
	positionFigure.x = 108;
	positionFigure.y = 0;
	positionFigure.w = 18;
	positionFigure.h = 30;

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(640,480,32, SDL_HWSURFACE);    
	
	figure = IMG_Load("img/sprite-player/player1.png");	
	
	int continuer = 1;
    	SDL_Event event;
    	while (continuer)
    	{
      	  	SDL_PollEvent(&event);
        	switch(event.type)
      	  	{
        		case SDL_QUIT:
                	continuer = 0;
        	}
		
		tempsActuel = SDL_GetTicks();
		if(tempsActuel - tempsPrecedent > 50)
		{
			SDL_FillRect(ecran, NULL, 0x000000);
			SDL_BlitSurface(figure, &positionFigure, ecran, &positionEcran);
			SDL_Flip(ecran);			
			positionFigure.x = positionFigure.x + 18;
			
			if(positionFigure.x >= 216)
				positionFigure.x = 108;
			if(positionEcran.x <= (640 - 18))
				positionEcran.x = positionEcran.x + 5;
			tempsPrecedent = tempsActuel;
		}
		
    	}

	SDL_FreeSurface(figure);
    	SDL_Quit();

    	return EXIT_SUCCESS;
}
