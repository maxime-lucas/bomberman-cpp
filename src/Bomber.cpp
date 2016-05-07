#include "Header.h"
Bomber::Bomber() : Figure()
{
	this->sprite = IMG_Load("../img/sprite-player/sprite-yoshi.png");
	this->nbSprites = 10;
	this->dimCoordSprite.w = 40;
	this->dimCoordSprite.h = 53;
	this->dimCoordSprite.x = 0;
	this->dimCoordSprite.y = this->direction*this->dimCoordSprite.h;
}

Bomber::~Bomber() {}

void Bomber::show(SDL_Surface *dest)
{
	Figure::show(dest);
}
