#include "Header.h"
Figure::Figure() : Shape()
{
	this->direction = EAST; // Pour qu'il soit face à nous;
	
	this->xVel = 0;
	this->yVel = 0;
	
	this->speed = DEFAULT_SPEED;
}

Figure::Figure(SDL_Surface* s,SDL_Rect r,int nb) : Shape(s,r,nb) {}

Figure::~Figure() {}

void Figure::show(SDL_Surface *dest)
{
	apply_surface( dimCoordEcran.x, dimCoordEcran.y, sprite, dest, &dimCoordSprite );
}

void Figure::MoveUp()
{
    direction = NORTH;
    updateSprite();
    dimCoordEcran.y -= yVel;
}

void Figure::MoveDown()
{
    direction = SOUTH;
    updateSprite();
    dimCoordEcran.y += yVel;
}

void Figure::MoveLeft()
{
    direction = WEST;
    updateSprite();
    dimCoordEcran.x -= xVel;
}

void Figure::MoveRight()
{
    direction = EAST;
    updateSprite();
    dimCoordEcran.x += xVel;
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
