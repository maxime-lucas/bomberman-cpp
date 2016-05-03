#include "Header.h"
Shape::Shape()
{
	this->sprite = NULL;
	this->nbSprites = 1;
	
	this->dimCoordEcran.x = 0;
	this->dimCoordEcran.y = 0;
}

Shape::Shape(SDL_Surface* s,SDL_Rect r,int nb)
{
	this->sprite = s;
	this->dimCoordSprite = r;
	this->nbSprites = nb;
	
	this->dimCoordEcran.x = 0;
	this->dimCoordEcran.y = 0;
}

Shape::~Shape() {}

void Shape::setDimCoordEcranX(int x) { this->dimCoordEcran.x = x; }
void Shape::setDimCoordEcranY(int y){ this->dimCoordEcran.y = y; }
void Shape::setDimCoordEcranW(int w) { this->dimCoordEcran.w = w; }
void Shape::setDimCoordEcranH(int h){ this->dimCoordEcran.h = h; }
int Shape::getDimCoordEcranX() { return this->dimCoordEcran.x; }
int Shape::getDimCoordEcranY() { return this->dimCoordEcran.y; }
int Shape::getDimCoordEcranW() { return this->dimCoordEcran.w; }
int Shape::getDimCoordEcranH() { return this->dimCoordEcran.h; }

void Shape::setDimCoordSpriteX(int x) { this->dimCoordSprite.x = x; }
void Shape::setDimCoordSpriteY(int y){ this->dimCoordSprite.y = y; }
void Shape::setDimCoordSpriteW(int w) { this->dimCoordSprite.w = w; }
void Shape::setDimCoordSpriteH(int h){ this->dimCoordSprite.h = h; }
int Shape::getDimCoordSpriteX() { return this->dimCoordSprite.x; }
int Shape::getDimCoordSpriteY() { return this->dimCoordSprite.y; }
int Shape::getDimCoordSpriteW() { return this->dimCoordSprite.w; }
int Shape::getDimCoordSpriteH() { return this->dimCoordSprite.h; }

