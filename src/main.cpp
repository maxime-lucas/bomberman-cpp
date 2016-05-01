// Les fichiers d'entête
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "functions.h"

// Les attributs de l'écran (640 * 480)
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// Les surfaces
SDL_Surface *screen = NULL;
SDL_Surface *image  = NULL;

// La structure d'evenement
SDL_Event event;

// Le font a utiliser
TTF_Font *font;

// La couleur
SDL_Color textColor = { 0,0,0};

int main( int arc, char* args[] )
{
	bool quit = false;

	if(!init())
		return EXIT_FAILURE;
	if(!load_files())
		return EXIT_FAILURE;

	message = TTF_RenderText_Solid( font, "Play now !", textColor );
	if( message == NULL )
		return 1;

	apply_surface( 0,0, background, screen );
	apply_surface( 0, 200, message, screen );

	SDL_Flip( screen );

	while(quit == false)
		while(SDL_PollEvent( &event ))
			if( event.type == SDL_QUIT )
				quit = true;
	clean_up();
	
	return 0;
}
