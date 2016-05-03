#include "Header.h"

Shape::Shape()
{
}

Shape::Shape(SDL_Surface* s, SDL_rect r , int nb)
{
    this.sprite = s;
    this.dimCoordSprite = r;
    this.nbSprites = nb;
}
