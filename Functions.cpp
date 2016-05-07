#include "Header.h"

void UpdateEvents(Input* in) /*fonction de gestion des évènements clavier et souris*/
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                in->key[event.key.keysym.sym]=1; /*on stocke 1 pour une touche pressée*/
                break;
            case SDL_KEYUP:
                in->key[event.key.keysym.sym]=0; /*et zéro pour touche relachée*/
                break;
            case SDL_MOUSEMOTION:
                in->mousex=event.motion.x; /*on enregistre les coordonnées absolues du curseur souris*/
                in->mousey=event.motion.y;
                in->mousexrel=event.motion.xrel; /*on enregistre les coordonnées relatives du curseur souris*/
                in->mouseyrel=event.motion.yrel;
                break;
            case SDL_MOUSEBUTTONDOWN:
                in->mousebuttons[event.button.button]=1; /*1 pour bouton souris enfoncé*/
                break;
            case SDL_MOUSEBUTTONUP:
                in->mousebuttons[event.button.button]=0; /*0 pour bouton souris relâché*/
                break;
            case SDL_QUIT:
                in->quit = 1; /*pour quitter*/
                break;
            default:
                break;
        }
    }
}

/*fonction pour l'affichage de tous types de sprite à l'écran*/
void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x; /*coordonnée X*/
    offset.y = y; /*coordonnée Y*/

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &offset ); /*on blit dans l'écran (affiche)*/
}

void start_screen(SDL_Surface *ecran) /*page d'accueil du jeu*/
{
    // Vars
    SDL_Surface *fondIMG ,*logoIMG ,*buttonStartIMG, *buttonQuitIMG; /*sprites ecran accueil*/
    SDL_Rect dimCoordSprite; /*coordonnées et dimensions des boutons*/

    // Préparation du Timer pour les animations
    Timer fps;

    // Chargement des images
    buttonStartIMG = IMG_Load("img/start-screen/start-button.png"); /*chargement des boutons*/
    buttonQuitIMG = IMG_Load("img/start-screen/quit-button.png");
    fondIMG = IMG_Load("img/start-screen/start.png");

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
        sprintf(filename ,"img/start-screen/intro/%d.png" ,i);
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

    Input in;
    memset(&in,0,sizeof(in));
    // Gestion du survol des boutons
    while(in.quit == 0)
    {
        UpdateEvents(&in);
        // Mouvement de souris

        // Survol du bouton PLAY
        if( start->isHovered( in.mousex, in.mousey ) )
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
        if( quit->isHovered( in.mousex, in.mousey ) ) // Gestion vers la fonction play
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


        // Clic de la souric
        if(in.mousebuttons[SDL_BUTTON_LEFT])
        {
            // Clic du bouton PLAY
            if( start->isHovered( in.mousex, in.mousey ) )
            {
                printf("Click PLAY\n"); // Gestion vers la fonction play
                SDL_FreeSurface(buttonStartIMG);
                SDL_FreeSurface(buttonQuitIMG);
                SDL_FreeSurface(fondIMG);
                SDL_FreeSurface(logoIMG);
                SDL_FillRect(ecran , NULL, SDL_MapRGB(ecran->format , 0,0,0));
                SDL_Flip(ecran);
                jeu(ecran);
            }

            // Clic du bouton QUIT
            if( quit->isHovered( in.mousex, in.mousey ) )
            {
                printf("Click QUIT\n");

                // Nettoyage
                SDL_FreeSurface(buttonStartIMG);
                SDL_FreeSurface(buttonQuitIMG);
                SDL_FreeSurface(fondIMG);
                SDL_FreeSurface(logoIMG);
                in.quit = 1;
            }
        }
    }
}

void jeu(SDL_Surface * ecran)
{
    Input in;
    Timer fps;
    memset(&in,0,sizeof(in));

    Bomber* player1 = new Bomber();
    Bomber* player2 = new Bomber();
    player2->setDimCoordEcranX(600);
    player2->setSprite(IMG_Load("img/sprite-player/player2.png"));
    player1->show(ecran);
    player2->show(ecran);
    SDL_Flip(ecran);

    while(in.quit == 0)
    {
        fps.start();
        UpdateEvents(&in);

        /*Touches joueur 2*/

        if (in.key[SDLK_DOWN] && !in.key[SDLK_UP] && !in.key[SDLK_LEFT] && !in.key[SDLK_RIGHT])
        {
            player2->setYvel((player2->getSpeed() / (FRAMES_PER_SECOND)));
            player2->MoveDown();
        }
        if (in.key[SDLK_LEFT] && !in.key[SDLK_UP] && !in.key[SDLK_DOWN] && !in.key[SDLK_RIGHT])
        {
            player2->setXvel((player2->getSpeed() / (FRAMES_PER_SECOND)));
            player2->MoveLeft();
        }
        if (in.key[SDLK_RIGHT] && !in.key[SDLK_UP] && !in.key[SDLK_LEFT] && !in.key[SDLK_DOWN])
        {
            player2->setXvel((player2->getSpeed() / (FRAMES_PER_SECOND)));
            player2->MoveRight();
        }
        if (in.key[SDLK_UP] && !in.key[SDLK_DOWN] && !in.key[SDLK_LEFT] && !in.key[SDLK_RIGHT])
        {
            player2->setYvel((player2->getSpeed() / (FRAMES_PER_SECOND)));
            player2->MoveUp();
        }
        if (!in.key[SDLK_DOWN] && !in.key[SDLK_UP] && !in.key[SDLK_LEFT] && !in.key[SDLK_RIGHT])
        {
            player2->resetSprite();
        }

        /*Touches Joueur 1*/

        if (in.key[SDLK_s] && !in.key[SDLK_w] && !in.key[SDLK_a] && !in.key[SDLK_d])
        {
            player1->setYvel((player1->getSpeed() / (FRAMES_PER_SECOND)));
            player1->MoveDown();
        }
        if (in.key[SDLK_a] && !in.key[SDLK_w] && !in.key[SDLK_s] && !in.key[SDLK_d])
        {
            player1->setXvel((player1->getSpeed() / (FRAMES_PER_SECOND)));
            player1->MoveLeft();
        }
        if (in.key[SDLK_d] && !in.key[SDLK_w] && !in.key[SDLK_a] && !in.key[SDLK_s])
        {
            player1->setXvel((player1->getSpeed() / (FRAMES_PER_SECOND)));
            player1->MoveRight();
        }
        if (in.key[SDLK_w] && !in.key[SDLK_s] && !in.key[SDLK_a] && !in.key[SDLK_d])
        {
            player1->setYvel((player1->getSpeed() / (FRAMES_PER_SECOND)));
            player1->MoveUp();
        }
        if (!in.key[SDLK_s] && !in.key[SDLK_w] && !in.key[SDLK_a] && !in.key[SDLK_d])
        {
            player1->resetSprite();
        }

        SDL_FillRect(ecran , NULL, SDL_MapRGB(ecran->format , 0,0,0));
        player1->show(ecran);
        player2->show(ecran);
        SDL_Flip(ecran);
        while(fps.get_ticks() < 2000/FRAMES_PER_SECOND)
        {

        }
    }
}
