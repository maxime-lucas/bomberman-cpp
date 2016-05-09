#include "Header.h"

const int MS_PER_UPDATE = 50;

int main(int argc, char *argv[])
{
	// Initialisation
	SDL_Surface *ecran ;
	init(&ecran); 
	
	// Objet pour g�rer les �v�nements
	Input in;
	
	// Instanciation des joueurs
	Bomber p1, p2;
	Figure players[NB_PLAYERS] = { (Figure) p1, (Figure) p2};
	
	// Instanciation du jeu
	Game *g = new Game( ecran, players);
	g->setupGame();
	
	// Variables temporelles
	double previous = SDL_GetTicks();
	double lag = 0.0;
	
	while( !in.getQuit() && !in.getKey(SDLK_ESCAPE) )
	{	
		// Calcul du lag
		int i = 0;
		double current = SDL_GetTicks();
		double elapsed = current - previous;
		previous = current;
		lag += elapsed;
		
		// Mise � jour des �v�nements
		in.Update();
		
		// Evolution du jeu, en fonction du lag
		while (lag >= MS_PER_UPDATE)
		{
			g->evolue(in);
			i++;
			lag -= MS_PER_UPDATE;
		}
		
		// G�n�ration de la map
		g->render();;
		g->flip();

	}
	
	// Fin du jeu
	SDL_Quit();
	return EXIT_SUCCESS;
}
