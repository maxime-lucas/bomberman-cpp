#include "Header.h"

Game::Game(SDL_Surface *ecran)
{
	this->ecran = ecran;

	mapBackground = new TileMap();
	mapWalls = new TileMap();

	//b1->setDimCoordEcranX(200);
	//b1->setDimCoordEcranY(50);
	tileSet = new TileSet();
}

Game::Game(SDL_Surface *ecran, Player players[])
{
	for(int i = 0; i < NB_PLAYERS; i++)
	{
		this->players[i] = players[i];
	}
	this->ecran = ecran;

	b1 = new Bomb();
	b1->nextStep();

	mapBackground = new TileMap();
	mapWalls = new TileMap();
	tileSet = new TileSet();
}

void Game::setupGame()
{
	int i,j;

	// Création de la map
	for(i = 0; i < NB_TILES_WIDTH; i++)
	{
		for(j = 0; j < NB_TILES_HEIGHT; j++)
		{
			Tile *t = new Tile(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_GRASS);
			mapBackground->add(t);

			if(i == 0 || j == 0 || i == NB_TILES_WIDTH - 1 || j == NB_TILES_HEIGHT - 1)
			{
				Tile *t = new Tile(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_WALL);
				mapWalls->add(t);
			}
		}
	}
	
	// Placement des personnages	
	for(int i = 0; i < NB_PLAYERS; i++)
	{
		players[i].setDimCoordEcranX(TILE_WIDTH* SPAWN_PLAYERS[i][0]);
		
		if(i <= 1)
			players[i].setDimCoordEcranY(20);
		else
			players[i].setDimCoordEcranY( TILE_HEIGHT*SPAWN_PLAYERS[i][1] - ( players[i].getDimCoordSpriteH() - TILE_HEIGHT ) - 3 );
	}

	// Ajout des murs centraux
	for(i = 1; i < NB_TILES_WIDTH - 1; i++)
	{
		for(j = 1; j < NB_TILES_HEIGHT - 1; j++)
		{
			if( i % 2 == 0 && j % 2 == 0 )
			{
				Tile *t = new Tile(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_BRICK);
				mapWalls->add(t);
			}
		}
	}

}

void Game::evolue(Input& in)
{
	SDLKey tabkey[3][4] = 
		{ 
			{SDLK_t,SDLK_g,SDLK_f,SDLK_h}, 
			{SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT}, 
			{SDLK_KP8, SDLK_KP5, SDLK_KP4, SDLK_KP6},
		};

	int i;

	for(i=0;i<NB_PLAYERS;i++)
	{
		if( in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
			players[i].setYvel((players[i].getSpeed() / (FRAMES_PER_SECOND)));
            	players[i].MoveUp();

    			if(touchesTile(players[i].getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				players[i].setDimCoordEcranY(players[i].getDimCoordEcranY() + players[i].getYvel() );
    			}
		}

		if( !in.getKey(tabkey[i][0]) && in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
			players[i].setYvel((players[i].getSpeed() / (FRAMES_PER_SECOND)));
            	players[i].MoveDown();

            	if(touchesTile(players[i].getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				players[i].setDimCoordEcranY(players[i].getDimCoordEcranY() - players[i].getYvel() );
    			}
		}

		if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
			players[i].setXvel((players[i].getSpeed() / (FRAMES_PER_SECOND)));
            	players[i].MoveLeft();

            	if(touchesTile(players[i].getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				players[i].setDimCoordEcranX(players[i].getDimCoordEcranX() + players[i].getXvel() );
    			}
		}

		if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && in.getKey(tabkey[i][3]))
		{
			players[i].setXvel((players[i].getSpeed() / (FRAMES_PER_SECOND)));
            	players[i].MoveRight();

            	if(touchesTile(players[i].getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				players[i].setDimCoordEcranX(players[i].getDimCoordEcranX() - players[i].getXvel() );
    			}
		}

		if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
            	players[i].resetSprite();
		}
	}

	b1->nextSprite();
	if ((b1->getStep() == 1) && (SDL_GetTicks() >= b1->getDateOfExplosion() - b1->getDelay() / 1))
    {
        b1->nextStep();
        b1->resetSprite();
    }

    if ((b1->getStep() == 2) && (SDL_GetTicks() >= b1->getDateOfExplosion()) )
    {
        b1->nextStep();
        b1->resetSprite();
    }
}

void Game::render()
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	mapBackground->draw(tileSet, ecran);
	mapWalls->draw(tileSet, ecran);

	if(b1->getStep() != 3)
        b1->show(ecran);

	for(int i = 0; i < NB_PLAYERS ; i++)
		players[i].show(ecran);

}

void Game::flip()
{
    while(SDL_Flip(ecran)!=0)
        SDL_Delay(1);

}

bool Game::touchesTile( SDL_Rect box, TileMap *tm, int nbTiles )
{
	for( int i = 0; i < nbTiles; ++i )
	{
		Tile *t = (Tile *) tm->get(i);
		if( ( t->getType() >= TILE_BRICK ) && (  t->getType() <= TILE_WALL ) )
		{
			if( checkCollision( box, t->getBox() ) )
			{
				return true;
			}
		}
	}
	return false;
}
