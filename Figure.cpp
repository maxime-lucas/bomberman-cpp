#include "Header.h"

Figure::Figure() : Shape()
{
    this->direction = SOUTH;

    this->xVel = 0;
    this->yVel = 0;

    this->speed = DEFAULT_SPEED;
}

Figure::Figure(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb)
{}

Figure::~Figure()
{
}

void Figure::show(SDL_Surface *dest)
{
    //SDL_Surface *s;
    //s = SDL_CreateRGBSurface(0,box.w , box.h , SCREEN_BPP, 0,255,255,0);
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
    //apply_surface(box.x , box.y , s, dest, NULL );
}

void Figure::MoveUp()
{
    direction = NORTH;
    updateSprite();
    dimCoordEcran.y -= yVel;
    updateBox();
}

void Figure::MoveDown()
{
    direction = SOUTH;
    updateSprite();
    dimCoordEcran.y += yVel;
    updateBox();
}

void Figure::MoveLeft()
{
    direction = WEST;
    updateSprite();
    dimCoordEcran.x -= xVel;
    updateBox();
}

void Figure::MoveRight()
{
    direction = EAST;
    updateSprite();
    dimCoordEcran.x += xVel;
    updateBox();
}

void Figure::updateSprite()
{
    dimCoordSprite.y = direction * dimCoordSprite.h;
    if ((dimCoordSprite.x += dimCoordSprite.w) >= (dimCoordSprite.w * nbSprites))
        dimCoordSprite.x = 0;
}

void Figure::resetSprite()
{
    direction = SOUTH;
    dimCoordSprite.y = direction * dimCoordSprite.h;
    dimCoordSprite.x = 0;
}

void Figure::updateBox()
{
	this->box.x = this->dimCoordEcran.x;
	this->box.y = this->dimCoordEcran.y + TILE_HEIGHT - 10;
	this->box.w = this->dimCoordSprite.w;
	this->box.h = this->dimCoordSprite.h - TILE_HEIGHT + 10;
}


