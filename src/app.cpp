#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>


int main(int argc, char *argv[])

{
  SDL_Surface *ecran = NULL , *figure = NULL;
  SDL_Rect positionFigure;
	SDL_Event event;
	int continuer = 1;
	
	if(SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	ecran = SDL_SetVideoMode(640,480,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	if(ecran == NULL)
	{
		fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	//figure = IMG_Load("../img/sprite-player/player1.png");	
	figure = SDL_LoadBMP("../img/zozor.bmp");
	SDL_SetColorKey(figure, SDL_SRCCOLORKEY, SDL_MapRGB(figure->format, 0,0,255));
	
	// On centre l'image à l'écran
	positionFigure.x = ecran->w / 2 - figure->w / 2;
	positionFigure.y = ecran->h / 2 - figure->h / 2;
	SDL_EnableKeyRepeat(5,5);
	while (continuer)
	{
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN :
				switch(event.key.keysym.sym)
				{
					case SDLK_UP :
						positionFigure.y--;
						break;
					case SDLK_DOWN :
						positionFigure.y++;
						break;
					case SDLK_RIGHT :
						positionFigure.x++;
						break;
					case SDLK_LEFT :
						positionFigure.x--;
						break;
				}
				break;
		}
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255,255,255));
		SDL_BlitSurface(figure, NULL, ecran, &positionFigure);
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(figure);
	SDL_Quit();
	
	return EXIT_SUCCESS;
}
