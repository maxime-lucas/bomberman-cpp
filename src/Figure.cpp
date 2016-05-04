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