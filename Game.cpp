#include "Header.h"

Game::Game(SDL_Surface *ecran)
{
	this->ecran = ecran;

	mapBackground = new TileMap();
	mapWalls = new TileMap();
	mapPlayers = new PlayerMap();
	mapBombs = new BombMap();
	mapExplosions = new ExplosionMap();
	tileSet = new TileSet();
}

Game::Game(SDL_Surface *ecran, Player players[])
{
	this->ecran = ecran;

	mapBackground = new TileMap();
	mapWalls = new TileMap();
	mapPlayers = new PlayerMap();
	mapExplosions = new ExplosionMap();
	mapBombs = new BombMap();
	tileSet = new TileSet();

	for(int i = 0; i < NB_PLAYERS; i++)
	{
		Player *p = &players[i];
		mapPlayers->add((void*) p);
	}

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
		// Récupération du joueur i
		Player *p = (Player*) mapPlayers->get(i);

		p->setDimCoordEcranX(TILE_WIDTH* SPAWN_PLAYERS[i][0]);

		if(i <= 1)
			p->setDimCoordEcranY(20);
		else
			p->setDimCoordEcranY( TILE_HEIGHT*SPAWN_PLAYERS[i][1] - ( p->getDimCoordSpriteH() - TILE_HEIGHT ) - 3 );
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
	// Tableau des contrôles des joueurs
	SDLKey tabkey[4][5] =
		{
			{SDLK_y, SDLK_h, SDLK_g, SDLK_j, SDLK_t},
			{SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT, SDLK_RSHIFT},
			{SDLK_w,SDLK_s,SDLK_a,SDLK_d, SDLK_q},
			{SDLK_KP8, SDLK_KP5, SDLK_KP4, SDLK_KP6, SDLK_KP7}
		};

	// Ecoute du clavier et Actions en conséquence
	for(int i=0; i<NB_PLAYERS; i++ )
	{
		// Récupération du joueur i
		Player *p = (Player*) mapPlayers->get(i);

		// Mouvement vers le haut :
		if( in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
			p->setYvel((p->getSpeed() / (FRAMES_PER_SECOND)));
            	p->MoveUp();

    			if(touchesTile(p->getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				p->setDimCoordEcranY(p->getDimCoordEcranY() + p->getYvel() );
    			}
		}

		// Mouvement vers le bas :
		if( !in.getKey(tabkey[i][0]) && in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
			p->setYvel((p->getSpeed() / (FRAMES_PER_SECOND)));
            	p->MoveDown();

            	if(touchesTile(p->getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				p->setDimCoordEcranY(p->getDimCoordEcranY() - p->getYvel() );
    			}
		}

		// Mouvement vers la gauche :
		if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
			p->setXvel((p->getSpeed() / (FRAMES_PER_SECOND)));
            	p->MoveLeft();

            	if(touchesTile(p->getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				p->setDimCoordEcranX(p->getDimCoordEcranX() + p->getXvel() );
    			}
		}

		// Mouvement vers la droite :
		if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && in.getKey(tabkey[i][3]))
		{
			p->setXvel((p->getSpeed() / (FRAMES_PER_SECOND)));
            	p->MoveRight();

            	if(touchesTile(p->getBox(), mapWalls, mapWalls->getNb() ) )
    			{
    				p->setDimCoordEcranX(p->getDimCoordEcranX() - p->getXvel() );
    			}
		}

		// Remise à 0 du sprite, dès qu'on relâche toutes les touches de déplacement
		if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
		{
            	p->resetSprite();
		}

		// Pose d'une bombe
		if( in.getKey(tabkey[i][4] ) )
		{
			// Remise à 0 de la touche, pour éviter la pose de bombe en restant appuyé :
			in.resetKey(tabkey[i][4]);

			// On vérifie que le joueur a au moins une bombe à poser
			if( p->getNbBomb() > 0 )
			{
				// Instanciation d'une nouvelle bombe
				Bomb *b = new Bomb();

				// Placement de la bombe aux coordonnées du joueur qui l'a posé
				int x = p->getDimCoordEcranX();
				int y = p->getDimCoordEcranY()+p->getDimCoordSpriteH();
				x = x - x%TILE_WIDTH;
				y = y - y%TILE_HEIGHT;


				b->setDimCoordEcranX(x);
				b->setDimCoordEcranY(y);
				// Décrémentation du nombre de bombes du joueur qui l'a posé
				p->dropBomb();

				// Ajout de la bombe au Map correspondant
				mapBombs->add( (void*) b );
			}
		}
	}

	// Mise à jour des bombes
	for(int i = 0; i < mapBombs->getNb() ; i++ )
	{
		Bomb *b = (Bomb*) mapBombs->get(i);

		b->nextSprite();
		if( ( b->getStep() == 1 ) && ( SDL_GetTicks() >= b->getDateOfExplosion() - b->getDelay() / 2 ) )
		{
			b->nextStep();
			b->resetSprite();
		}

		if( ( b->getStep() == 2 ) && ( SDL_GetTicks() >= b->getDateOfExplosion()) )
		{
			b->nextStep();
			b->resetSprite();
		}

		if( ( b->getStep() == 3 ) )
		{
			// Création d'une explosion à la place
			Explosion *e = new Explosion();

			// Placement de l'explosion
			int x = b->getDimCoordEcranX();
			int y = b->getDimCoordEcranY();

			e->setDimCoordEcranX(x);
			e->setDimCoordEcranY(y);

			// Ajout de l'explosion au Map correspondant
			mapExplosions->add( (void*) e);

			// Suppression de la bombe
			mapBombs->remove( (void*) b );

		}
	}

	// Mise à jour des explosions
	for(int i = 0; i < mapExplosions->getNb() ; i++ )
	{
		Explosion *e = (Explosion *) mapExplosions->get(i);

		if( SDL_GetTicks() >= e->getDateOfEnd() )
		{
			mapExplosions->remove( (void*) e );
		}
	}

}

void Game::render()
{
	// Réinitialisation de l'écran
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	// Affichage du calque 1 : Background
	mapBackground->draw(tileSet, ecran);

	// Affichage du calque 2 : Explosions
	mapExplosions->draw(ecran);

	// Affichage du calque 3 : Murs incassables
	mapWalls->draw(tileSet, ecran);

	// Affichage du calque 4 : Bombes
	mapBombs->draw(ecran);

	// Affichage du calque 5 : Joueurs
	mapPlayers->draw(ecran);

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
