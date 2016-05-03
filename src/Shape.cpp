#include "Header.h"
Shape::Shape()
{
	this->sprite = NULL;
	this->nbSprites = 1;
	
	this->dimCoordShape.x = 0;
	this->dimCoordShape.y = 0;
}

Shape::Shape(SDL_Surface* s,SDL_Rect r,int nb)
{
	this->sprite = s;
	this->dimCoordSprite = r;
	this->nbSprites = nb;
	
	this->dimCoordShape.x = 0;
	this->dimCoordShape.y = 0;
}

Shape::~Shape() {}
