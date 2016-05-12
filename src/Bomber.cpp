#include "Header.h"

Bomber::Bomber() : Figure()
{
	this->sprite = IMG_Load("img/sprites/player1.png"); /*chargement de l'image du personnage*/
	this->nbSprites = 6; /*nb d'images pour l'animation du perso*/

	this->dimCoordSprite.w = 40; /*largeur d'une image de l'animation*/
	this->dimCoordSprite.h = 67; /*hauteur d'une image de l'animation*/
	this->dimCoordSprite.x = 0; /*coordonnée x d'affichage à l'écran de départ*/
	this->dimCoordSprite.y = this->direction * this->dimCoordSprite.h; /*coordonnée y de départ*/
}

Bomber::~Bomber()
{
}

void Bomber::show(SDL_Surface * dest)
{
    Figure::show(dest);
}
