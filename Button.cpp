#include "Header.h"

Button::Button() : Shape() /*constructeur par défaut appelle celui de Shape*/
{
}

Button::Button(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb) /*constructeur paramétré appelle celui de Shape*/
{
}

Button::~Button() /*destructeur*/
{
}

void Button::show(SDL_Surface *dest) /*méthode d'affichage, appelle la fonction apply_surface*/
{
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
}
