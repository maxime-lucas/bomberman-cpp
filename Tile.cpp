#include "Header.h"

Tile::Tile( int x, int y, int tileType )
{
	box.x = x;
	box.y = y;
	
	box.w = TILE_WIDTH;
	box.h = TILE_HEIGHT;
	
	type = tileType;
}

void Tile::show(TileSet *ts,SDL_Surface *dest)
{
	SDL_Rect tmp = ts->getClip(type);
	SDL_Rect *ptr = &tmp;
	apply_surface(box.x, box.y, ts->getTileSet(), dest, ptr);
}

int Tile::getType()
{
	return type;
}

SDL_Rect Tile::getBox()
{
	return box;
} 
