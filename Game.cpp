#include "Header.h"

Game::Game(SDL_Surface *ecran, Player players[])
{
    this->ecran = ecran;

    tileSet = new TileSet();

    for(int i = 0; i < NB_PLAYERS; i++)
    {
        Player *p = &players[i];
        mapPlayers.push_back(p);
    }

    nbPlayersAlive = NB_PLAYERS;

    endOfGame = false;

}

void Game::setupGame()
{
	int i,j;

        vector<int> stage = parseStageFile("stages/stage-1.txt");

        for(int i = 0 , x = 0, y = 0 ; i < stage.size() ; i++)
        {
            if( stage[i] == - 38 )
            {
                x = 0;
                y++;
            }
            else
            {
                Tile *t = new Tile(x * TILE_WIDTH, y * TILE_HEIGHT, stage[i]);

                if(stage[i] == TILE_GRASS)
                    mapBackground.push_back(t);
                else
                    mapWalls.push_back(t);
                x++;
            }
        }

        // Placement des blocs aleatoires au centre
        srand(time(NULL));
        for(int i = 0; i < 30 ; i++)
        {
            int x = rand() % 13 + 2;
            int y = rand() % 9 + 2;

            Tile *t = new Tile(x * TILE_WIDTH, y * TILE_HEIGHT, TILE_WOOD);
            mapWalls.push_back(t);
        }

        // Placement des blocs aléatoires sur les quatres rangées

	for(int i = 0; i < 6 ; i++)
        {
            // Gauche
            int x = 1;
            int y = rand() % 7 + 3;

            Tile *t1 = new Tile(x * TILE_WIDTH, y * TILE_HEIGHT, TILE_WOOD);
            mapWalls.push_back(t1);

            // Droite
            x = 15;
            y = rand() % 7 + 3;

            Tile *t2 = new Tile(x * TILE_WIDTH, y * TILE_HEIGHT, TILE_WOOD);
            mapWalls.push_back(t2);

            // Haut
            x = rand() % 11 + 3;
            y = 1;

            Tile *t3 = new Tile(x * TILE_WIDTH, y * TILE_HEIGHT, TILE_WOOD);
            mapWalls.push_back(t3);

            // Bas
            x = rand() % 11 + 3;
            y = 11;

            Tile *t4 = new Tile(x * TILE_WIDTH, y * TILE_HEIGHT, TILE_WOOD);
            mapWalls.push_back(t4);
        }


	// Placement des personnages
	for(int i = 0; i < NB_PLAYERS; i++)
	{
            // Récupération du joueur i
            Player *p = mapPlayers[i];
            p->setDimCoordEcranX(TILE_WIDTH* SPAWN_PLAYERS[i][0]);

            if(i <= 1)
                p->setDimCoordEcranY(20);
            else
                p->setDimCoordEcranY( TILE_HEIGHT*SPAWN_PLAYERS[i][1] - ( p->getDimCoordSpriteH() - TILE_HEIGHT ) - 3 );

            // Pour pallier à un problème d'initialisation de collisionsBoxes, on les déplace manuellement, pour que les boxes se placent automatiquement
            p->MoveUp();
        }

	// Ajout des murs centraux
	for(i = 1; i < NB_TILES_WIDTH - 1; i++)
	{
            for(j = 1; j < NB_TILES_HEIGHT - 1; j++)
            {
                if( i % 2 == 0 && j % 2 == 0 )
                {
                    Tile *t = new Tile(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_BRICK);
                    mapWalls.push_back(t);
                }
            }
	}

}

void Game::evolue(Input& in)
{
    // Tableau des contrôles des joueurs
    SDLKey tabkey[4][5] =
		{
			{SDLK_w,SDLK_s,SDLK_a,SDLK_d, SDLK_q},
			{SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT, SDLK_RSHIFT},
		};

    // Ecoute du clavier et Actions en conséquence
    for(int i=0; i<NB_PLAYERS; i++ )
    {
        // Récupération du joueur i
        Player *p =  mapPlayers[i];

        if( p->isAlive() )
        {
            // Mouvement vers le haut :
            if( in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
            {
                p->setYvel((p->getSpeed() / (FRAMES_PER_SECOND)));
                p->MoveUp();

                if( touchesTile(p->getBox(), mapWalls) )
                {
                    p->setDimCoordEcranY(p->getDimCoordEcranY() + p->getYvel() );
                }
            }

            // Mouvement vers le bas :
            if( !in.getKey(tabkey[i][0]) && in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
            {
                p->setYvel((p->getSpeed() / (FRAMES_PER_SECOND)));
                p->MoveDown();

                if(touchesTile(p->getBox(), mapWalls) )
                {
                    p->setDimCoordEcranY(p->getDimCoordEcranY() - p->getYvel() );
                }
            }

            // Mouvement vers la gauche :
            if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && in.getKey(tabkey[i][2]) && !in.getKey(tabkey[i][3]))
            {
                p->setXvel((p->getSpeed() / (FRAMES_PER_SECOND)));
                p->MoveLeft();

                if(touchesTile(p->getBox(), mapWalls) )
                {
                    p->setDimCoordEcranX(p->getDimCoordEcranX() + p->getXvel() );
                }
            }

            // Mouvement vers la droite :
            if( !in.getKey(tabkey[i][0]) && !in.getKey(tabkey[i][1]) && !in.getKey(tabkey[i][2]) && in.getKey(tabkey[i][3]))
            {
                p->setXvel((p->getSpeed() / (FRAMES_PER_SECOND)));
                p->MoveRight();

                if(touchesTile(p->getBox(), mapWalls) )
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
                    int y = p->getDimCoordEcranY() + p->getDimCoordSpriteH();
                    x = x - x % TILE_WIDTH;
                    y = y - y % TILE_HEIGHT;

                    b->setDimCoordEcranX(x);
                    b->setDimCoordEcranY(y);

                    // Décrémentation du nombre de bombes du joueur qui l'a posé
                    p->dropBomb();

                    // Ajout de la bombe au Map correspondant
                    mapBombs.push_back(b);
                }
            }
        }
    }

    // Mise à jour des bombes
    for(int i = 0; i < mapBombs.size() ; i++ )
    {
        updateBomb(i);
    }

    // Mise à jour des explosions
    for(int i = 0; i < mapExplosions.size() ; i++ )
    {
        updateExplosion(i);
    }

    // Explosions et personnages
    for(int i = 0; i < mapExplosions.size() ; i++ )
    {
        Explosion *e = mapExplosions[i];

        for(int j = 0; j < e->getCollisionBoxes().size() ; j++ )
        {
            SDL_Rect box = e->getCollisionBoxes()[j];

            for(int k = 0; k < mapPlayers.size() ; k++)
            {
                Player *p = mapPlayers[k];
                if( p->isAlive() )
                {
                    if( checkCollision( box, p->getBox() ) )
                    {
                        killPlayer(k);
                    }
                }
            }
        }
    }

    // Test du gagnant
    if( nbPlayersAlive == 1 )
    {
        int indexWinner;
        bool win = false;
        for( int i = 0 ; i < mapPlayers.size() ;  i++)
        {
            if( mapPlayers[i]->isAlive() )
            {
                indexWinner = i;
                win =true;
            }

            if( win ) break;
        }
    }
}

void Game::render()
{
	// Réinitialisation de l'écran
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	// Affichage du calque 1 : Background
	for(int i = 0 ; i < mapBackground.size() ; i++)
            mapBackground[i]->show(tileSet,ecran);

	// Affichage du calque 2 : Explosions
	for(int i = 0 ; i < mapExplosions.size() ; i++)
            mapExplosions[i]->show(ecran);

	// Affichage du calque 3 : Murs
	for(int i = 0 ; i < mapWalls.size() ; i++)
            if( mapWalls[i]->isEnabled() )
                mapWalls[i]->show(tileSet,ecran);

	// Affichage du calque 4 : Bombes
	for(int i = 0 ; i < mapBombs.size() ; i++)
            mapBombs[i]->show(ecran);

	// Affichage du calque 5 : Joueurs
	for(int i = 0 ; i < mapPlayers.size() ; i++)
            if( mapPlayers[i]->isAlive() )
                mapPlayers[i]->show(ecran);
}

void Game::flip()
{
    while(SDL_Flip(ecran)!=0)
        SDL_Delay(1);

}

bool Game::touchesTile( SDL_Rect box, std::vector<Tile*> tm )
{
    for( int i = 0; i < tm.size() ; ++i )
    {
        Tile *t = tm[i];
        if( t->isEnabled() )
        {
            if( ( t->getType() >= TILE_BRICK ) && (  t->getType() <= TILE_WOOD ) )
            {
                if( checkCollision( box, t->getBox() ) )
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::touchesBomb( SDL_Rect box, std::vector<Bomb*> bm )
{
    for( int i = 0; i < bm.size() ; i++ )
    {
        Bomb *b = bm[i];
        if( checkCollision( box, b->getDimCoordEcran() ) )
        {
            return true;
        }
    }
    return false;
}

bool Game::explosionTouchesTile( SDL_Rect box, std::vector<Tile*> tm )
{
    for( int i = 0; i < tm.size() ; ++i )
    {
        Tile *t = tm[i];
        if( t->isEnabled() )
        {
            if( ( t->getType() >= TILE_BRICK ) && (  t->getType() <= TILE_WOOD ) )
            {
                if( checkCollision( box, t->getBox() ) )
                {
                    if( t->getType() == TILE_WOOD )
                    {
                        // Suppression de la caisse
                        t->setEnabled(false);
                    }

                    return true;
                }
            }
        }
    }
    return false;
}

void Game::evolueExplosion(int i)
{
    Explosion *e = mapExplosions[i];

    // Initialisation des compteurs de collisions
    int nbCollisionUp, nbCollisionLeft, nbCollisionRight, nbCollisionDown;
    nbCollisionUp = nbCollisionLeft = nbCollisionRight = nbCollisionDown = 0;

    // COLLISIONS
    //      Comment les gérer ?
    // - On parcourt toutes les boxes de collision de l'explosion
    // - On étudie la direction de chacune des boxes pour savoir sur quelle branche elle est (SOURCE, NORTH, SOUTH, EAST, WEST)
    // - En fonction de la branche, nous n'avons pas les mêmes collisions à checker (exemple : NORTH gère les collisions vers le haut seulement )
    for(int i = 0; i < e->getCollisionBoxes().size() ; i++)
    {
        int direction;
        SDL_Rect box = e->getCollisionBoxes()[i];

        if( box.x == e->getDimCoordEcranX() && box.y == e->getDimCoordEcranY() )
            direction = 4;
        else if( box.x > e->getDimCoordEcranX() )
            direction = EAST;
        else if( box.x < e->getDimCoordEcranX() )
            direction = WEST;
        else if( box.y > e->getDimCoordEcranY() )
            direction = SOUTH;
        else if( box.y <= e->getDimCoordEcranY() )
            direction = NORTH;

        SDL_Rect tempBoxUp, tempBoxLeft, tempBoxRight, tempBoxDown;

        switch(direction)
        {
            // BRANCHE HAUT
            case NORTH :
                // Collision en haut
                tempBoxUp.x = box.x;
                tempBoxUp.y = box.y - TILE_HEIGHT;
                tempBoxUp.w = box.w;
                tempBoxUp.h = box.h;

                if( explosionTouchesTile(tempBoxUp, mapWalls) )
                    nbCollisionUp++;

                break;

            // BRANCHE GAUCHE
            case WEST:
                 // Collision à gauche
                tempBoxLeft.x = box.x - TILE_WIDTH;
                tempBoxLeft.y = box.y;
                tempBoxLeft.w = box.w;
                tempBoxLeft.h = box.h;

                if( explosionTouchesTile(tempBoxLeft, mapWalls) )
                    nbCollisionLeft++;

                break;

            // BRANCHE DROITE
            case EAST:
                 // Collision à gauche
                tempBoxRight.x = box.x + TILE_WIDTH;
                tempBoxRight.y = box.y;
                tempBoxLeft.w = box.w;
                tempBoxLeft.h = box.h;

                if( explosionTouchesTile(tempBoxRight, mapWalls) )
                    nbCollisionRight++;

                break;

            // BRANCHE BAS
            case SOUTH:
                 // Collision en bas
                tempBoxDown.x = box.x;
                tempBoxDown.y = box.y + TILE_HEIGHT;
                tempBoxDown.w = box.w;
                tempBoxDown.h = box.h;

                if( explosionTouchesTile(tempBoxDown, mapWalls) )
                    nbCollisionDown++;
                break;

            // BRANCHE SOURCE
            case 4:
                // Collision en haut
                tempBoxUp.x = box.x;
                tempBoxUp.y = box.y - TILE_HEIGHT;
                tempBoxUp.w = box.w;
                tempBoxUp.h = box.h;

                 // Collision à gauche
                tempBoxLeft.x = box.x - TILE_WIDTH;
                tempBoxLeft.y = box.y;
                tempBoxLeft.w = box.w;
                tempBoxLeft.h = box.h;

                 // Collision à droite
                tempBoxRight.x = box.x + TILE_WIDTH;
                tempBoxRight.y = box.y;
                tempBoxRight.w = box.w;
                tempBoxRight.h = box.h;

                // Collision en bas
                tempBoxDown.x = box.x;
                tempBoxDown.y = box.y + TILE_HEIGHT;
                tempBoxDown.w = box.w;
                tempBoxDown.h = box.h;

                if( explosionTouchesTile(tempBoxDown, mapWalls) )
                    nbCollisionDown++;

                if( explosionTouchesTile(tempBoxRight, mapWalls) )
                    nbCollisionRight++;

                if( explosionTouchesTile(tempBoxUp, mapWalls) )
                    nbCollisionUp++;
                if( explosionTouchesTile(tempBoxLeft, mapWalls) )
                    nbCollisionLeft++;
                break;

            // CAS PAR DEFAUT
            default:
                break;
        }
    }

    if(nbCollisionUp == 0)
        e->evolueUp();

    if(nbCollisionLeft == 0)
        e->evolueLeft();

    if(nbCollisionRight == 0)
        e->evolueRight();

    if(nbCollisionDown == 0)
        e->evolueDown();
}

void Game::updateBomb( int i)
{
    Bomb *b = mapBombs[i];
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
        // Placement de l'explosion
        int x = b->getDimCoordEcranX();
        int y = b->getDimCoordEcranY();

        // Création d'une explosion à la place
        Explosion *e = new Explosion(x,y);

        // Ajout de l'explosion au Map correspondant
        mapExplosions.push_back(e);

        // Suppression de la bombe
        mapBombs.erase( mapBombs.begin() + i );
    }
}

void Game::updateExplosion(int i)
{
    Explosion *e = mapExplosions[i];

    if( e->getStep() == 1 && SDL_GetTicks() >= e->getDateOfEnd() - ( 5 * e->getDuration() ) / 6 )
    {
        e->nextStep();
        evolueExplosion(i);
    }

    if( e->getStep() == 2 && SDL_GetTicks() >= e->getDateOfEnd() - ( 4 * e->getDuration() ) / 6 )
    {
        e->nextStep();
        evolueExplosion(i);
    }

    if( e->getStep() == 3 && SDL_GetTicks() >= e->getDateOfEnd() - ( 2 * e->getDuration() ) / 6 )
    {
        e->nextStep();
    }

    if( e->getStep() == 4 && SDL_GetTicks() >= e->getDateOfEnd() - ( 1 * e->getDuration() ) / 6 )
    {
            e->nextStep();
    }

    if( e->getStep() == 5 && SDL_GetTicks() >= e->getDateOfEnd() )
    {
            mapExplosions.erase( mapExplosions.begin() + i );
    }
}

void Game::killPlayer(int i)
{
    printf("%d est mort\n",i);
    mapPlayers[i]->setAlive(false);

    nbPlayersAlive--;
    printf("Players encore en vie : %d\n",nbPlayersAlive);
}
