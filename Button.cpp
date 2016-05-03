#include "Header.h"

Button::Button() : Shape()
{
}

Button::Button(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb)
{
}

Button::~Button()
{
}

void Button::show(SDL_Surface *dest)
{
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
}
