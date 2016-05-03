#include "Header.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran ; /*variable zone affichage*/

    SDL_Event event; /*variable d'�v�nement*/

    bool quit = false;

    FMOD_SYSTEM *system; /*d�claration d'un objet son*/
    FMOD_SOUND *musique; /*d�claration d'une musique*/
    FMOD_CHANNELGROUP *canaux; /*d�claration d'un groupe de canaux*/
    FMOD_System_Create(&system); /*allocation de l'objet son*/
    FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL); /*initialisation de l'objet son*/
    FMOD_System_CreateSound(system, "sounds/theme.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique); /*chargement musique dans objet son*/
    FMOD_Sound_SetLoopCount(musique, -1); /*mise en boucle de la musique*/
    FMOD_System_GetMasterChannelGroup(system ,&canaux); /*r�cup�ration du groupe de canaux*/
    FMOD_ChannelGroup_SetVolume(canaux ,0.5); /*r�glage du volume de la musique*/
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL); /* On joue la musique */

    SDL_Init(SDL_INIT_VIDEO); /*d�marrage de la librairie SDL*/

    ecran = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF); /*cr�ation de la fen�tre avec double buffering*/
    SDL_WM_SetCaption("Bomberman", NULL); /*nom de la fen�tre*/

    //Bomber *player1 = new Bomber();
    //player1->show(ecran);

    start_screen(ecran);

    SDL_Flip(ecran);

    while(!quit)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    //startscreen(ecran);

    FMOD_System_Close(system); /*fermeture de l'objet son*/
    FMOD_System_Release(system); /*lib�ration de l'objet son*/

    SDL_Quit(); /*fermeture de la librairie SDL*/

    return EXIT_SUCCESS;
}
