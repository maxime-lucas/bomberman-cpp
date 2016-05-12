#include "Header.h"

Map::Map()
{
	nb = 0;
	tab =  NULL;
}

Map::~Map()
{
	delete(tab);
}

Map& Map::operator=(const Map& t)
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

void Map::add(void* elt)
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

void Map::remove(void *elt)
{
	void **dtab;
	int i,j;
	
	dtab = new void*[nb];
	for(i = 0, j = 0; i < nb; i++)
	{
		if( tab[i] != elt )
		{
			dtab[j] = tab[i];
			j++;
		}
		else
		{
			delete (Bomb *) tab[i];
		}
	}
	tab =dtab;
	nb--;
}
