#include "Header.h"

void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &offset );
}

void start_screen(SDL_Surface *ecran) /*page d'accueil du jeu*/
{
    SDL_Surface *fondIMG ,*logoIMG ,*startButtonIMG, *quitButtonIMG; /*sprites ecran accueil*/
    SDL_Rect positionFondDansEcran; /*variable pour position affichage dans écran*/
    SDL_Rect dimCoordSprite; /*coordonnées et dimensions des boutons*/
    
    int boucle = 1; /*variable de sortie de boucle*/
    SDL_Event event; /*variable évènement*/
    
    startButtonIMG = IMG_Load("../img/start-screen/start-button.png"); /*chargement des boutons*/
    quitButtonIMG = IMG_Load("../img/start-screen/quit-button.png");

    dimCoordSprite.x = 0;
    dimCoordSprite.y = 0;
    dimCoordSprite.w = 147;
    dimCoordSprite.h = 48;

    // Instanciation des boutons
    Button *start = new Button(startButtonIMG ,dimCoordSprite, 2); /*creation d'un objet bouton pour start*/
    Button *quit = new Button(quitButtonIMG , dimCoordSprite, 2); /*création d'un objet bouton pour quit*/ 
    
    // Affichage des boutons
    start->show(ecran);
    start->toString();
    
    SDL_Flip(ecran);
    
    while(boucle)
    {
    	while(SDL_PollEvent(&event))
    	{
    		if(event.type == SDL_QUIT)
    			boucle = 0;
    	}
    }
}
