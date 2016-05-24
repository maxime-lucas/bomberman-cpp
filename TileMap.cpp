#include "Header.h"

TileMap::TileMap() : Map()
{
}

TileMap::~TileMap()
{
}


void TileMap::draw(TileSet *ts, SDL_Surface *dest)
{
    for(int i = 0; i < tab.size() ; i++)
    {
        Tile *t = (Tile*) tab[i];
        t->show(ts, dest);
    }
}
