#include "Header.h"

//const int MS_PER_UPDATE = 50;

int main(int argc, char *argv[])
{
	// Initialisation
	SDL_Surface *ecran ;
	SDL_putenv("SDL_VIDEO_CENTERED=center");
	init(&ecran);

	// initialisation du son
	FMOD_SYSTEM *system;
	FMOD_SOUND *sound;
	FMOD_System_Create(&system);
	FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, NULL);
    FMOD_System_CreateSound(system, "sounds/theme.mp3",FMOD_LOOP_NORMAL | FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound);
    FMOD_Sound_SetLoopCount(sound, -1);
    FMOD_CHANNELGROUP *channel;
    FMOD_System_GetMasterChannelGroup(system, &channel);
    FMOD_ChannelGroup_SetVolume(channel, 0.8);
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, NULL);


    start_screen(ecran);

    //fin du son
    FMOD_System_Close(system);
    FMOD_System_Release(system);

	// Fin du jeu
	SDL_Quit();
	return EXIT_SUCCESS;
}
