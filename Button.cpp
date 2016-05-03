#include "Header.h"

Button::Button() : Shape() /*constructeur par d�faut appelle celui de Shape*/
{
}

Button::Button(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb) /*constructeur param�tr� appelle celui de Shape*/
{
}

Button::~Button() /*destructeur*/
{
}

void Button::show(SDL_Surface *dest) /*m�thode d'affichage, appelle la fonction apply_surface*/
{
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
}
