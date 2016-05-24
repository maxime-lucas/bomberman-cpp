#include "Header.h"

BombMap::BombMap() : Map()
{
}

BombMap::~BombMap()
{
}


void BombMap::draw(SDL_Surface *dest)
{
    for(int i = 0; i < tab.size() ; i++)
    {
        Bomb *b = (Bomb*) tab[i];
            b->show(dest);
    }
}
