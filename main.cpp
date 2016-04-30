#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

SDL_Surface *ecran; /*variable global zone affichage �cran*/
SDL_Rect positionDansEcran; /*variable globale pour position affichange dans �cran*/

int main(int argc, char *argv[])
{
    SDL_Surface *player1; /*sprite du player 1*/
    SDL_Rect positionDansSprite; /* positionnement dans l'image sprite et dans l'�cran*/
    bool haut ,bas ,gauche ,droite; /*gestion repetion touche pour animation*/
    SDL_Event event; /* La variable contenant l'�v�nement */
    int continuer = 1; /* Notre bool�en pour la boucle */

    positionDansEcran.x = positionDansEcran.y = 0;
    positionDansSprite.x = positionDansSprite.y = 0;
    positionDansSprite.w = 36; positionDansSprite.h = 60;
    haut = bas = gauche = droite = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /*cr�ation de la fen�tre avec double buffering*/
    SDL_WM_SetCaption("Bomberman", NULL); /*nom de la fen�tre*/

    player1 = IMG_Load("img/sprite-player/player1(x2).png"); /*chargement image du joueur 1*/
    SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /*affichage initial � l'�cran*/

    SDL_EnableKeyRepeat(10,60); /*on active la r�p�tition des touches lorsqu'on maintient enfonc�*/

    while (continuer) /* TANT QUE la variable ne vaut pas 0 */
    {
        SDL_WaitEvent(&event); /* On attend un �v�nement qu'on r�cup�re dans event */
        switch(event.type) /* On teste le type d'�v�nement */
        {
            case SDL_QUIT: /* Si c'est un �v�nement QUITTER */
                continuer = 0; /* On met le bool�en � 0, donc la boucle va s'arr�ter */
                break;
            case SDL_KEYDOWN: /* Si appui sur une touche */
                switch (event.key.keysym.sym) /*switch case pour les actions clavier*/
                {
                    case SDLK_UP: // Fl�che haut
                        if (haut != 1) positionDansSprite.x = 0; /*si flag d�placement � z�ro position de d�part de l'animation*/
                        positionDansSprite.y = 60;
                        if ((positionDansEcran.y = positionDansEcran.y - 7) < 0) /*traitement des bords de fen�tre pour ne pas d�passer*/
                            positionDansEcran.y = positionDansEcran.y + 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage �cran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite � l'�cran*/
                        haut = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 216) /* si on arrive au bout de l'animation, on reprend au d�but*/
                            positionDansSprite.x = 0;
                        break;
                    case SDLK_DOWN: // Fl�che bas
                        if (bas != 1) positionDansSprite.x = 0; /*si flag d�placement � z�ro position de d�part de l'animation*/
                        positionDansSprite.y = 0;
                        if ((positionDansEcran.y = positionDansEcran.y + 7) >= 420) /*traitement des bords de fen�tre pour ne pas d�passer*/
                            positionDansEcran.y = positionDansEcran.y - 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage �cran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite � l'�cran*/
                        bas = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 216) /* si on arrive au bout de l'animation, on reprend au d�but*/
                            positionDansSprite.x = 0;
                        break;
                    case SDLK_RIGHT: // Fl�che droite
                        if (droite != 1) positionDansSprite.x = 216; /*si flag d�placement � z�ro position de d�part de l'animation*/
                        positionDansSprite.y = 0;
                        if ((positionDansEcran.x = positionDansEcran.x + 7) >= 604) /*traitement des bords de fen�tre pour ne pas d�passer*/
                            positionDansEcran.x = positionDansEcran.x - 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage �cran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite � l'�cran*/
                        droite = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 432) /* si on arrive au bout de l'animation, on reprend au d�but*/
                            positionDansSprite.x = 216;
                        break;
                    case SDLK_LEFT: // Fl�che gauche
                        if (gauche != 1) positionDansSprite.x = 216; /*si flag d�placement � z�ro position de d�part de l'animation*/
                        positionDansSprite.y = 60;
                        if  ((positionDansEcran.x = positionDansEcran.x - 7) < 0) /*traitement des bords de fen�tre pour ne pas d�passer*/
                            positionDansEcran.x = positionDansEcran.x + 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage �cran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite � l'�cran*/
                        gauche = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 432) /* si on arrive au bout de l'animation, on reprend au d�but*/
                            positionDansSprite.x = 216;
                        break;
                }
                break;
        }
    }
    SDL_FreeSurface(player1);
    SDL_Quit();

    return EXIT_SUCCESS;
}
