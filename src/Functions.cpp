#include "Header.h"

// Fonction pour gérer 
void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &offset );
}

void start_screen(SDL_Surface *ecran)
{
    // Vars
    SDL_Surface *fondIMG ,*logoIMG ,*buttonStartIMG, *buttonQuitIMG;
    SDL_Rect dimCoordSprite;

    // Préparation du Timer pour les animations
    Timer fps;
    
    // Préparation de l'objet permettant de gérer les événements
    Input in;

    // Chargement des images
    buttonStartIMG = IMG_Load("../img/start-screen/start-button.png");
    buttonQuitIMG = IMG_Load("../img/start-screen/quit-button.png");
    fondIMG = IMG_Load("../img/start-screen/start.png");

    // Préparation de la structure pour les boutons
    dimCoordSprite.x = 0;
    dimCoordSprite.y = 0;
    dimCoordSprite.w = 147;
    dimCoordSprite.h = 48;

    // Instanciation des boutons
    Button *start = new Button(buttonStartIMG ,dimCoordSprite, 2);
    Button *quit = new Button(buttonQuitIMG , dimCoordSprite, 2);

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
    while(!in.getQuit())
    {
        in.Update();
        
        // Survol du bouton PLAY
        if( start->isHovered( in.getMouseX(), in.getMouseY() ) )
        {
            start->setHovered();
            start->show(ecran);
            SDL_Flip(ecran);
        }
        else
        {
            start->unsetHovered();
            start->show(ecran);
            SDL_Flip(ecran);
        }

        // Survol du bouton QUIT
        if( quit->isHovered( in.getMouseX(), in.getMouseY() ) )
        {
            quit->setHovered();
            quit->show(ecran);
            SDL_Flip(ecran);
        }
        else
        {
            quit->unsetHovered();
            quit->show(ecran);
            SDL_Flip(ecran);
        }


        // Clic de la souris
        if (in.getMouseButton(SDL_BUTTON_LEFT) )
        {
            // Clic du bouton PLAY
            if( start->isHovered( in.getMouseX(), in.getMouseY() ) )
            {
                // Nettoyage
                SDL_FreeSurface(buttonStartIMG);
                SDL_FreeSurface(buttonQuitIMG);
                SDL_FreeSurface(fondIMG);
                SDL_FreeSurface(logoIMG);
                
                // Reset de l'écran
                SDL_FillRect(ecran , NULL, SDL_MapRGB(ecran->format , 0,0,0));
                SDL_Flip(ecran);
                
                // Lancement du jeu
                //jeu(ecran);
                
                // Fin de la boucle 
                in.setQuit(1);
            }

            // Clic du bouton QUIT
            if( quit->isHovered( in.getMouseX(), in.getMouseY() ) )
            {
                // Nettoyage
                SDL_FreeSurface(buttonStartIMG);
                SDL_FreeSurface(buttonQuitIMG);
                SDL_FreeSurface(fondIMG);
                SDL_FreeSurface(logoIMG);
                
                // Fin de la boucle
                in.setQuit(1);
            }
        }
    }
}

bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    // Les côtés des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // Côtes de A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    // Côtes de B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    return true;
}
 
void init(SDL_Surface** s)
{
	SDL_Init(SDL_INIT_VIDEO);
	*s = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Bomberman", NULL);
}
