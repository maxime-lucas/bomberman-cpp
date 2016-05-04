#include "Header.h"

Figure::Figure() : Shape() /*constructeur pour les personnages*/
{
    this->direction = SOUTH; /*orientation de d�part des personnages*/

    this->xVel = 0; /*vitesse de d�placement en X*/
    this->yVel = 0; /*vitesse de d�placement en Y*/

    this->speed = DEFAULT_SPEED; /*vitesse de d�placement ici celle par d�faut*/
}

Figure::Figure(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb) /*constructeur param�tr�*/
{
}

Figure::~Figure() /*destructeur*/
{
}

void Figure::show(SDL_Surface *dest) /*m�thode d'affichage*/
{
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
}

void Figure::MoveUp()
{
    direction = NORTH;
    updateSprite();
}

void Figure::MoveDown()
{
    direction = SOUTH;
    updateSprite();
}

void Figure::MoveLeft()
{
    direction = WEST;
    updateSprite();
}

void Figure::MoveRight()
{
    direction = EAST;
    updateSprite();
}

void Figure::updateSprite()
{
    dimCoordSprite.y = direction * dimCoordSprite.h;
    if ((dimCoordSprite.x += dimCoordSprite.w) >= (dimCoordSprite.w * nbSprites))
        dimCoordSprite.x = 0;
}
