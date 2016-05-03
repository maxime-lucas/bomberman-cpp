#include "Header.h"
#include "Classes.h"
Bomber::Bomber() : Figure()
{
	this->sprite = IMG_Load("../img/sprite-player/sprite-bomber-1.png");
	this->nbSprites = 6;
	
	this->dimCoordSprite.w = 40;
	this->dimCoordSprite.h = 67;
	this->dimCoordSprite.x = 0;
	this->dimCoordSprite.y = this->direction*this->dimCoordSprite.h;
}

Bomber::~Bomber() {} 

void Bomber::show(SDL_Surface *dest)
{
	Figure::show(dest);
}	
