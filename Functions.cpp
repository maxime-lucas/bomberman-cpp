#include "Header.h"

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
    SDL_Surface *fond ,*logo ; /*sprites ecran accueil*/
    SDL_Rect positionFondDansEcran; /*variable pour position affichage dans écran*/
    SDL_Rect dimCoordQuit ,dimCoordStart; /*coordonnées et dimensions des boutons*/
    int boucle = 1; /*variable de sortie de boucle*/
    SDL_Event event; /*variable évènement*/

    fond = IMG_Load("img/start-screen/start.png"); /*chargement du fond d'écran*/

    //Button *start = new Button(startButtonN ,dimCoordStart); /*creation d'un objet bouton pour start*/
    //Button *quit = new Button(quitButtonN ,dimCoordQuit); /*création d'un objet bouton pour quit*/
    //Button *startH = new Button(startButtonH ,dimCoordStart); /*création objet pour bouton start survolé*/
    //Button *quitH = new Button(quitButtonH ,dimCoordQuit); /*création objet pour bouton quit survolé*/

    positionFondDansEcran.x = positionFondDansEcran.y = 0;
    SDL_BlitSurface(fond ,NULL ,ecran ,&positionFondDansEcran); /*affichage dans le buffer*/

    char filename[64];
    for (int i = 1 ; i <= 76 ; i++)
    {
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
        sprintf(filename ,"img/start-screen/intro/%d.png" ,i);
        logo = IMG_Load(filename);
        SDL_BlitSurface(fond ,NULL ,ecran ,&positionFondDansEcran); /*affichage dans le buffer*/
        SDL_BlitSurface(logo ,NULL ,ecran ,&positionFondDansEcran);
        SDL_Flip(ecran);
    }

    //start->show(ecran ,dimCoordStart); /*affichage de start dans le buffer*/
    //quit->show(ecran ,dimCoordQuit); /*affichage de quit dans le buffer*/

    SDL_Flip(ecran); /*affichage à l'écran*/

//    while(boucle) /*boucle pour attente d'évenement*/
//    {
//        SDL_PollEvent(&event);
//        switch(event.type) /*switch des types d'evenements et actions à appliquer*/
//        {
//            case SDL_MOUSEMOTION: /*cas position de la souris*/
//                /*si la souris se trouve sur le bouton start*/
//                if ((event.motion.x > start->getDimCoordx() && event.motion.x < (start->getDimCoordx() + start->getDimCoordw())) && (event.motion.y > start->getDimCoordy() && event.motion.y < (start->getDimCoordy() + start->getDimCoordh()))) // Gestion vers la fonction play
//                {
//                    startH->print(ecran ,dimCoordStart); /*on affiche le bouton survolé*/
//                    SDL_Flip(ecran);
//                }
//                else
//                {
//                    start->print(ecran ,dimCoordStart); /*sinon on affiche le bouton normal*/
//                    SDL_Flip(ecran);
//                }
//                /*si la souris se trouve sur le bouton quit*/
//                if ((event.motion.x > quit->getDimCoordx() && event.motion.x < (quit->getDimCoordx() + quit->getDimCoordw())) && (event.motion.y > quit->getDimCoordy() && event.motion.y < (quit->getDimCoordy() + quit->getDimCoordh()))) // Gestion vers la fonction play
//                {
//                    quitH->print(ecran ,dimCoordQuit); /*on affiche le bouton survolé*/
//                    SDL_Flip(ecran);
//                }
//                else
//                {
//                    quit->print(ecran ,dimCoordQuit); /*sinon on affiche le bouton normal*/
//                    SDL_Flip(ecran);
//                }
//                break;
//            case SDL_MOUSEBUTTONUP:
//                if (event.button.button == SDL_BUTTON_LEFT) /*cas click bouton gauche*/
//                {
//                    /*si on se trouve sur le bouton start*/
//                    if ((event.button.x > start->getDimCoordx() && event.button.x < (start->getDimCoordx() + start->getDimCoordw())) && (event.button.y > start->getDimCoordy() && event.button.y < (start->getDimCoordy() + start->getDimCoordh())))
//                    {
//                        SDL_FreeSurface(fond); /*on libère tous les prites créés dans la fonction*/
//                        SDL_FreeSurface(logo);
//                        SDL_FreeSurface(startButtonH);
//                        SDL_FreeSurface(startButtonN);
//                        SDL_FreeSurface(quitButtonH);
//                        SDL_FreeSurface(quitButtonN);
//                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
//                        SDL_Flip(ecran);
//                        jouer(ecran); /*on lance la fonction jouer*/
//                    }
//                    /*si on se trouve sur le bouton quit*/
//                    if ((event.button.x > quit->getDimCoordx() && event.button.x < (quit->getDimCoordx() + quit->getDimCoordw())) && (event.button.y > quit->getDimCoordy() && event.button.y < (quit->getDimCoordy() + quit->getDimCoordh())))
//                        {
//                            SDL_FreeSurface(fond); /*on libère tous les sprites créés dans la fonction*/
//                            SDL_FreeSurface(logo);
//                            SDL_FreeSurface(startButtonH);
//                            SDL_FreeSurface(startButtonN);
//                            SDL_FreeSurface(quitButtonH);
//                            SDL_FreeSurface(quitButtonN);
//                            SDL_FreeSurface(ecran);
//                            boucle = 0; /*on quitte la page d'accueil et retour au main pour quitter le programme*/
//                        }
//                }
//                break;
//        }
//    }
}
