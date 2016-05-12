#include "Header.h"

Bomber::Bomber() : Figure()
{
	this->sprite = IMG_Load("img/sprites/player1.png"); /*chargement de l'image du personnage*/
	this->nbSprites = 6; /*nb d'images pour l'animation du perso*/

	this->dimCoordSprite.w = 40; /*largeur d'une image de l'animation*/
	this->dimCoordSprite.h = 67; /*hauteur d'une image de l'animation*/
	this->dimCoordSprite.x = 0; /*coordonn�e x d'affichage � l'�cran de d�part*/
	this->dimCoordSprite.y = this->direction * this->dimCoordSprite.h; /*coordonn�e y de d�part*/
}

Bomber::~Bomber()
{
}

void Bomber::show(SDL_Surface * dest)
{
    Figure::show(dest);
}
