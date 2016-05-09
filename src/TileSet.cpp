#include "Header.h"

TileSet::TileSet()
{
	this->tileSet = IMG_Load("../img/textures/tileset.png");
	
	clips[ TILE_GRASS ].x = 0;
	clips[ TILE_GRASS ].y = 0;
	clips[ TILE_GRASS ].w = TILE_WIDTH;
	clips[ TILE_GRASS ].h = TILE_HEIGHT;
	
	clips[ TILE_WALL ].x = TILE_WIDTH;
	clips[ TILE_WALL ].y = 0;
	clips[ TILE_WALL ].w = TILE_WIDTH;
	clips[ TILE_WALL ].h = TILE_HEIGHT;
}
