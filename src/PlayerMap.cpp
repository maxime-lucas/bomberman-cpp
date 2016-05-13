#include "Header.h"

PlayerMap::PlayerMap() {}
PlayerMap::~PlayerMap() {}

void PlayerMap::draw(SDL_Surface *dest)
{
    for(int i = 0; i < tab.size() ; i++)
    {
        Player *p = (Player*) tab[i];
        p->show(dest);
    }	
}