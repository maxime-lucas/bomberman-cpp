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
	// Vars
	SDL_Surface *fondIMG ,*logoIMG ,*buttonStartIMG, *buttonQuitIMG; /*sprites ecran accueil*/
	SDL_Rect dimCoordSprite; /*coordonnées et dimensions des boutons*/
	int boucle = 1; /*variable de sortie de boucle*/
	SDL_Event event; /*variable évènement*/
	
	// Préparation du Timer pour les animations
	Timer fps;

	// Chargement des images
	buttonStartIMG = IMG_Load("../img/start-screen/start-button.png"); /*chargement des boutons*/
	buttonQuitIMG = IMG_Load("../img/start-screen/quit-button.png");
	fondIMG = IMG_Load("../img/start-screen/start.png");

	// Préparation de la structure pour les boutons
	dimCoordSprite.x = 0;
	dimCoordSprite.y = 0;
	dimCoordSprite.w = 147;
	dimCoordSprite.h = 48;

	// Instanciation des boutons
	Button *start = new Button(buttonStartIMG ,dimCoordSprite, 2); /*creation d'un objet bouton pour start*/
	Button *quit = new Button(buttonQuitIMG , dimCoordSprite, 2); /*création d'un objet bouton pour quit*/ 

	// Positionnement des boutons sur l'écran
	start->setDimCoordEcranX(15);
	start->setDimCoordEcranY(420);
	quit->setDimCoordEcranX(180);
	quit->setDimCoordEcranY(420);

	// Animation du logo
	char filename[64];
	for (int i = 1 ; i <= 76 ; i++)
	{
		fps.start();
		
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
		sprintf(filename ,"../img/start-screen/intro/%d.png" ,i);
		logoIMG = IMG_Load(filename);
		apply_surface(0,0,fondIMG, ecran);
		apply_surface(0,0,logoIMG, ecran);
		SDL_Flip(ecran);
		
		while( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {}
		
		fps.stop();
	}
	
	// Affichage des boutons 
	start->show(ecran);
	quit->show(ecran);
	SDL_Flip(ecran);

	// Gestion du survol des boutons
	while(boucle)
	{
		while( SDL_PollEvent(&event) )
		{
			// Quitter la fenetre
			if( event.type == SDL_QUIT )
				boucle = 0;
				
			// Mouvement de souris
			else if( event.type == SDL_MOUSEMOTION )
			{
				// Survol du bouton PLAY
				if( start->isHovered( event.motion.x, event.motion.y ) )
				{
					start->setHovered(); /*on affiche le bouton survolé*/
					start->show(ecran);
					SDL_Flip(ecran);
				}
				else
				{
					start->unsetHovered(); /*on affiche le bouton survolé*/
					start->show(ecran);
					SDL_Flip(ecran);
				}
				
				// Survol du bouton QUIT
				if( quit->isHovered( event.motion.x, event.motion.y ) ) // Gestion vers la fonction play
				{
					quit->setHovered(); /*on affiche le bouton survolé*/
					quit->show(ecran);
					SDL_Flip(ecran);
				}
				else
				{
					quit->unsetHovered(); /*on affiche le bouton survolé*/
					quit->show(ecran);
					SDL_Flip(ecran);
				}
			}
			
			// Clic de la souric
			else if( event.type == SDL_MOUSEBUTTONUP )
			{
				// Clic du bouton PLAY
				if( start->isHovered( event.motion.x, event.motion.y ) )
				{
					printf("Click PLAY\n");
				}
				
				// Clic du bouton QUIT
				if( quit->isHovered( event.motion.x, event.motion.y ) ) // Gestion vers la fonction play
				{
					printf("Click QUIT\n");
					
					// Nettoyage
					SDL_FreeSurface(buttonStartIMG);
					SDL_FreeSurface(buttonQuitIMG);
					SDL_FreeSurface(fondIMG);
					SDL_FreeSurface(logoIMG);
					
					delete start;
					delete quit;
					
					boucle = 0;
				}		
			}
		}
	}
}
