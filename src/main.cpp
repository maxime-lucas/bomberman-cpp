// Les fichiers d'entête
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <SDL/SDL_ttf.h>

// Les attributs de l'écran (640 * 480)
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// Les surfaces
SDL_Surface *screen = NULL;
SDL_Surface *background = NULL;
SDL_Surface *message = NULL;

// La structure d'evenement
SDL_Event event;

// Le font a utiliser
TTF_Font *font = NULL;

// La couleur ud font
SDL_Color textColor = { 255, 255, 255 };

bool init()
{
	if( SDL_Init(SDL_INIT_EVERYTHING ) == -1)
	{
		printf("Initialisation de SDL impossible: %s\n", SDL_GetError());
		return false;
	}

	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE );

	if( screen == NULL )
	{
		return false;
	}

	if( TTF_Init() == -1 )
	{
		printf("TTF se charge pas\n");
		return false;
	}

	SDL_WM_SetCaption( "TTF Test", NULL );

	return true;
}

bool load_files()
{	
	// Chargement du fond
	background = IMG_Load("background.png");

	// Chargement du font
	font = TTF_OpenFont( "CaslonBold.ttf", 28); 
	
	// Vérification des erreurs
	if( background == NULL )
	{
		printf("Le background se charge pas\n");
		return false;
	}
	if( font == NULL ) 
	{
		printf("La police se charge pas\n");
		return false;
	}
	printf("load_files:done\n");
	return true;
}

void clean_up()
{
	// Free des surfaces
	SDL_FreeSurface( background );
	SDL_FreeSurface( message );

	// Fermeture des fonts
	TTF_CloseFont( font );

	// Quitte SDL_TTF
	TTF_Quit();

	// Quitte SDL
	SDL_Quit();
}

void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip = NULL )
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(src, clip, dest, &offset);
}


int main( int arc, char* args[] )
{
	bool quit = false;

	if(!init())
	{
		printf("Erreur dans l'initialisation : %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	if(!load_files())
	{
		printf("Erreur dans le chargement des fichiers : %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}	

	message = TTF_RenderText_Solid( font, "Test pour sdl_ttf", textColor );

	if( message == NULL ) {
		return 1;
	}

	apply_surface(0,0, background, screen);
	apply_surface(200,200,message, screen);

	SDL_Flip( screen );

	while(quit == false)
		while(SDL_PollEvent( &event ))
			if( event.type == SDL_QUIT )
				quit = true;
	clean_up();
	
	return 0;
}
