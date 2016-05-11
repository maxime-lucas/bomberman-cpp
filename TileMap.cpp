#include "Header.h"

TileMap::TileMap()
{
	nb = 0;
	tab =  NULL;
}

TileMap::~TileMap()
{
	delete(tab);
}

TileMap& TileMap::operator=(const TileMap& t)
{
	if(this != &t)
	{
		delete tab;
		nb = t.nb;
		tab = new void*[nb + 1];
		for(int i = 0; i < nb; i++)
			tab[i] = t.tab[i];
	}
	return *this;
}

void TileMap::add(void* elt)
{
	void **dtab;
	int i;
	
	dtab = new void*[nb + 1];
	for(i = 0; i < nb; i++)
		dtab[i] = tab[i];
	dtab[i] = elt;
	if( tab != NULL )
		delete tab;
	tab = dtab;
	nb++;
}

void TileMap::draw(TileSet *ts, SDL_Surface *dest)
{
	for(int i = 0; i < nb; i++)
	{
		Tile *t = (Tile*) tab[i];
		t->show(ts, dest);
	}	
}
