#include "Header.h"

Shape::Shape()
{
    this->dimCoordEcran.x = 0;
    this->dimCoordEcran.y = 0;
    this->sprite = NULL;
    this->nbSprites = 1;
}

Shape::~Shape()
{
}

Shape::Shape(SDL_Surface* s, SDL_Rect r , int nb)
{
    this->sprite = s;
    this->dimCoordSprite = r;
    this->nbSprites = nb;

    this->dimCoordEcran.x = 0;
    this->dimCoordEcran.y = 0;
}
