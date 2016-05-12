
#include "Header.h"

Bomb::Bomb() : Shape()
{
	this->sprite = IMG_Load("img/sprites/bomb.png"); /*chargement de l'image du personnage*/
	this->nbSprites = 2; /*nb d'images pour l'animation du perso*/

	this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
	this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
	this->dimCoordSprite.x = 0; /*coordonnée x d'affichage à l'écran de départ*/
	this->dimCoordSprite.y = 0; /*coordonnée y de départ*/

	this->step = 0;
	this->delay = 8000;
	this->dateOfExplosion = SDL_GetTicks() + delay;
}

Bomb::~Bomb()
{
}

void Bomb::show(SDL_Surface * dest)
{
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
}

void Bomb::nextStep()
{
    this->step++;
}

void Bomb::nextSprite()
{
    dimCoordSprite.y = 0;
    switch(step)
    {
        case 1:
            if ((dimCoordSprite.x += dimCoordSprite.w) >= (dimCoordSprite.w * nbSprites))
                dimCoordSprite.x = 0;
            break;
        case 2:
            if ((dimCoordSprite.x += dimCoordSprite.w) >= (50+dimCoordSprite.w * nbSprites))
                dimCoordSprite.x = 50;
            break;
        default:
            break;
    }
}

void Bomb::resetSprite()
{
    switch(step)
    {
        case 1:
            dimCoordSprite.x = 0;
            break;
        case 2:
            dimCoordSprite.x = 50;
            break;
        default:
            break;
    }
}


