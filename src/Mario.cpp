#include "Header.h"
Mario::Mario() : Figure()
{
	this->sprite = IMG_Load("../img/sprite-player/sprite-mario.png");
	this->nbSprites = 7;
	this->dimCoordSprite.w = 44;
	this->dimCoordSprite.h = 70;
	this->dimCoordSprite.x = 0;
	this->dimCoordSprite.y = this->direction*this->dimCoordSprite.h;
}

Mario::~Mario() {}

void Mario::show(SDL_Surface *dest)
{
	printf("Mario\n");
	Figure::show(dest);
}
