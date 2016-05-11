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

//	// Objet pour gérer les événements
//	Input in;
//
//	// Instanciation des joueurs
//	Bomber p1, p2;
//	p2.setSprite(IMG_Load("img/sprite-player/player2.png"));
//	Figure players[NB_PLAYERS] = { (Figure) p1, (Figure) p2};
//
//	// Instanciation du jeu
//	Game *g = new Game( ecran, players);
//	g->setupGame();
//
//	// Variables temporelles
//	double previous = SDL_GetTicks();
//	double lag = 0.0;
//
//	while( !in.getQuit() && !in.getKey(SDLK_ESCAPE) )
//	{
//		// Calcul du lag
//		int i = 0;
//		double current = SDL_GetTicks();
//		double elapsed = current - previous;
//		previous = current;
//		lag += elapsed;
//
//		// Mise à jour des événements
//		in.Update();
//
//		// Evolution du jeu, en fonction du lag
//		while (lag >= MS_PER_UPDATE)
//		{
//			g->evolue(in);
//			i++;
//			lag -= MS_PER_UPDATE;
//		}
//
//		// Génération de la map
//		g->render();;
//		g->flip();
//
//	}
    start_screen(ecran);

    //fin du son
    FMOD_System_Close(system);
    FMOD_System_Release(system);

	// Fin du jeu
	SDL_Quit();
	return EXIT_SUCCESS;
}
