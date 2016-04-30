#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <fmodex/fmod.h>


SDL_Surface *ecran; /*variable global zone affichage écran*/
SDL_Rect positionDansEcran; /*variable globale pour position affichange dans écran*/

int main(int argc, char *argv[])
{
    SDL_Surface *player1; /*sprite du player 1*/
    SDL_Rect positionDansSprite; /* positionnement dans l'image sprite et dans l'écran*/
    bool haut ,bas ,gauche ,droite; /*gestion repetion touche pour animation*/
    SDL_Event event; /* La variable contenant l'événement */
    int continuer = 1; /* Notre booléen pour la boucle */

    positionDansEcran.x = positionDansEcran.y = 0;
    positionDansSprite.x = positionDansSprite.y = 0;
    positionDansSprite.w = 36; positionDansSprite.h = 60;
    haut = bas = gauche = droite = 0;

    FMOD_SYSTEM *system; /*déclaration d'un objet son*/
    FMOD_SOUND *musique; /*déclaration d'une musique*/
    FMOD_CHANNELGROUP *canaux; /*déclaration d'un groupe de canaux*/
    FMOD_System_Create(&system); /*allocation de l'objet son*/
    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL); /*initialisation de l'objet son*/
    FMOD_System_CreateSound(system, "music/theme.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique); /*chargement musique dans objet son*/
    FMOD_Sound_SetLoopCount(musique, -1); /*mise en boucle de la musique*/
    FMOD_System_GetMasterChannelGroup(system ,&canaux); /*récupération du groupe de canaux*/
    FMOD_ChannelGroup_SetVolume(canaux ,0.5); /*réglage du volume de la musique*/
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL); /* On joue la musique */

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); /*création de la fenêtre avec double buffering*/
    SDL_WM_SetCaption("Bomberman", NULL); /*nom de la fenêtre*/

    player1 = IMG_Load("img/sprite-player/player1(x2).png"); /*chargement image du joueur 1*/
    SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /*affichage initial à l'écran*/
    SDL_Flip(ecran);

    SDL_EnableKeyRepeat(10,50); /*on active la répétition des touches lorsqu'on maintient enfoncé*/

    while (continuer) /* TANT QUE la variable ne vaut pas 0 */
    {
        SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event */
        switch(event.type) /* On teste le type d'événement */
        {
            case SDL_QUIT: /* Si c'est un événement QUITTER */
                continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
                break;
            case SDL_KEYDOWN: /* Si appui sur une touche */
                switch (event.key.keysym.sym) /*switch case pour les actions clavier*/
                {
                    case SDLK_UP: // Flèche haut
                        if (haut != 1) positionDansSprite.x = 0; /*si flag déplacement à zéro position de départ de l'animation*/
                            positionDansSprite.y = 60;
                        if ((positionDansEcran.y = positionDansEcran.y - 7) < 0) /*traitement des bords de fenètre pour ne pas dépasser*/
                            positionDansEcran.y = positionDansEcran.y + 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        haut = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 216) /* si on arrive au bout de l'animation, on reprend au début*/
                            positionDansSprite.x = 0;
                        break;
                    case SDLK_DOWN: // Flèche bas
                        if (bas != 1) positionDansSprite.x = 0; /*si flag déplacement à zéro position de départ de l'animation*/
                            positionDansSprite.y = 0;
                        if ((positionDansEcran.y = positionDansEcran.y + 7) >= 420) /*traitement des bords de fenètre pour ne pas dépasser*/
                            positionDansEcran.y = positionDansEcran.y - 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        bas = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 216) /* si on arrive au bout de l'animation, on reprend au début*/
                            positionDansSprite.x = 0;
                        break;
                    case SDLK_RIGHT: // Flèche droite
                        if (droite != 1) positionDansSprite.x = 216; /*si flag déplacement à zéro position de départ de l'animation*/
                            positionDansSprite.y = 0;
                        if ((positionDansEcran.x = positionDansEcran.x + 7) >= 604) /*traitement des bords de fenètre pour ne pas dépasser*/
                            positionDansEcran.x = positionDansEcran.x - 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        droite = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 432) /* si on arrive au bout de l'animation, on reprend au début*/
                            positionDansSprite.x = 216;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                        if (gauche != 1) positionDansSprite.x = 216; /*si flag déplacement à zéro position de départ de l'animation*/
                            positionDansSprite.y = 60;
                        if  ((positionDansEcran.x = positionDansEcran.x - 7) < 0) /*traitement des bords de fenètre pour ne pas dépasser*/
                            positionDansEcran.x = positionDansEcran.x + 7;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        gauche = 1;
                        if ((positionDansSprite.x = positionDansSprite.x + 36) >= 432) /* si on arrive au bout de l'animation, on reprend au début*/
                            positionDansSprite.x = 216;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP: /*si on relâche une touche*/
                switch (event.key.keysym.sym) /*switch case pour les actions clavier*/
                {
                    case SDLK_UP: /*fleche haut*/
                        positionDansSprite.x = 0;
                        positionDansSprite.y = 60;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        haut = 0; /*passage du flag position sprite a zéro pour recuperer la position initiale*/
                        break;
                    case SDLK_DOWN: /*fleche bas*/
                        positionDansSprite.x = 0;
                        positionDansSprite.y = 0;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        bas = 0; /*passage du flag position sprite a zéro pour recuperer la position initiale*/
                        break;
                    case SDLK_LEFT: /*fleche gauche*/
                        positionDansSprite.x = 216;
                        positionDansSprite.y = 60;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        gauche = 0; /*passage du flag position sprite a zéro pour recuperer la position initiale*/
                        break;
                    case SDLK_RIGHT: /*fleche droite*/
                        positionDansSprite.x = 216;
                        positionDansSprite.y = 0;
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /*nettoyage écran*/
                        SDL_BlitSurface(player1 ,&positionDansSprite ,ecran ,&positionDansEcran); /* on colle le sprite dans le buffer*/
                        SDL_Flip(ecran); /*affichage du sprite à l'écran*/
                        droite = 0; /*passage du flag position sprite a zéro pour recuperer la position initiale*/
                        break;
                    default:
                        break;
                }


        }
    }
    SDL_FreeSurface(player1); /*libération de l'espace mémoire du sprite joueur 1*/
    FMOD_System_Close(system); /*fermeture de l'objet son*/
    FMOD_System_Release(system); /*libération de l'objet son*/
    SDL_Quit(); /*fermeture de SDL*/

    return EXIT_SUCCESS;
}
