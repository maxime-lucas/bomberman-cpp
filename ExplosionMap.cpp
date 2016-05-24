#include "Header.h"

ExplosionMap::ExplosionMap() : Map()
{
}

ExplosionMap::~ExplosionMap()
{
}


void ExplosionMap::draw(SDL_Surface *dest)
{
	for(int i = 0; i < tab.size() ; i++)
	{
		Explosion *e= (Explosion *) tab[i];
		e->show(dest);
	}
}
