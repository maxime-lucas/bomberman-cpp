#include "Header.h"

BombMap::BombMap() : Map()
{
}

BombMap::~BombMap()
{
}


void BombMap::draw(SDL_Surface *dest)
{
	for(int i = 0; i < nb; i++)
	{
		Bomb *b = (Bomb*) tab[i];
		//if( b->getStep() != 3)
			b->show(dest);
	}	
}
