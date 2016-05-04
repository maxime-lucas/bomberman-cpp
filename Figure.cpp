#include "Header.h"

Figure::Figure() : Shape() /*constructeur pour les personnages*/
{
    this->direction = SOUTH; /*orientation de départ des personnages*/

    this->xVel = 0; /*vitesse de déplacement en X*/
    this->yVel = 0; /*vitesse de déplacement en Y*/

    this->speed = DEFAULT_SPEED; /*vitesse de déplacement ici celle par défaut*/
}

Figure::Figure(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb) /*constructeur paramétré*/
{
}

Figure::~Figure() /*destructeur*/
{
}

void Figure::show(SDL_Surface *dest) /*méthode d'affichage*/
{
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
}

void Figure::MoveUp()
{
    direction = NORTH;
    updateSprite();
    dimCoordEcran.y -= yVel;
}

void Figure::MoveDown()
{
    direction = SOUTH;
    updateSprite();
    dimCoordEcran.y += yVel;
}

void Figure::MoveLeft()
{
    direction = WEST;
    updateSprite();
    dimCoordEcran.x -= xVel;
}

void Figure::MoveRight()
{
    direction = EAST;
    updateSprite();
    dimCoordEcran.x += xVel;
}

void Figure::updateSprite()
{
    dimCoordSprite.y = direction * dimCoordSprite.h;
    if ((dimCoordSprite.x += dimCoordSprite.w) >= (dimCoordSprite.w * nbSprites))
        dimCoordSprite.x = 0;
}

void Figure::resetSprite()
{
    direction = SOUTH;
    dimCoordSprite.y = direction * dimCoordSprite.h;
    dimCoordSprite.x = 0;
}
