
#include "Header.h"

Bomb::Bomb() : Shape()
{
	this->sprite = IMG_Load("img/sprites/bomb.png"); /*chargement de l'image du personnage*/
	this->nbSprites = 2; /*nb d'images pour l'animation du perso*/

	this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
	this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
	this->dimCoordSprite.x = 0; /*coordonn�e x d'affichage � l'�cran de d�part*/
	this->dimCoordSprite.y = 0; /*coordonn�e y de d�part*/

        this->dimCoordEcran.w = dimCoordSprite.w;
        this->dimCoordEcran.h = dimCoordSprite.h;
        
	this->step = 1;
	this->delay = 4000;
	this->dateOfExplosion = SDL_GetTicks() + delay;
}

Bomb::~Bomb()
{
}

void Bomb::show(SDL_Surface * dest)
{
    if( DEBUG_MODE )
    {
        SDL_Surface *s;
        s = SDL_CreateRGBSurface(0,dimCoordEcran.w , dimCoordEcran.h , SCREEN_BPP, 0,255,255,0);
        apply_surface(dimCoordEcran.x , dimCoordEcran.y , s, dest, NULL );   
    }
    
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


