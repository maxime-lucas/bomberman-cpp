
#include "Header.h"

Explosion::Explosion() : Shape()
{
	this->sprite = IMG_Load("../img/sprites/explosion.png"); /*chargement de l'image du personnage*/
	this->nbSprites = 1; /*nb d'images pour l'animation du perso*/

	this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
	this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
	this->dimCoordSprite.x = 100; /*coordonnée x d'affichage à l'écran de départ*/
	this->dimCoordSprite.y = 100; /*coordonnée y de départ*/

	this->step = 1;
	this->strength = 2;
	this->duration = 5000;
	this->dateOfDisparition = SDL_GetTicks() + duration;
}

Explosion::~Explosion()
{
}

void Explosion::show(SDL_Surface * dest)
{
	apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
}

void Explosion::nextStep()
{
    this->step++;
}

void Explosion::nextSprite()
{
	switch(step)
	{
		case 1 :
			this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
			this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
			this->dimCoordSprite.x = 100; /*coordonnée x d'affichage à l'écran de départ*/
			this->dimCoordSprite.y = 100; /*coordonnée y de départ*/
			break;
			
		case 2 :
			this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
			this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
			this->dimCoordSprite.x = 100; /*coordonnée x d'affichage à l'écran de départ*/
			this->dimCoordSprite.y = 100; /*coordonnée y de départ*/
			break;
		case 3 :
			break;
	}
}

void Explosion::resetSprite()
{
}


