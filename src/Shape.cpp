#include "Header.h"

Shape::Shape() /*constructeur par d�faut*/
{
    this->dimCoordEcran.x = 0; /*position d'affichage X dans �cran*/
    this->dimCoordEcran.y = 0; /*position d'affichage Y dans �cran*/
    this->sprite = NULL; /*image de la Shape, ici NULL*/
    this->nbSprites = 1; /*nb d'images pour animation , ici 1 seule*/
}

Shape::~Shape() /*destructeur*/
{
}

Shape::Shape(SDL_Surface* s, SDL_Rect r , int nb) /*constructeur param�tr�*/
{
    this->sprite = s; /*image pass�e en param�tre*/
    this->dimCoordSprite = r; /*coordonn�es et taille image dans sprite, pass� en param�tres*/
    this->nbSprites = nb; /*nb d'iamges pour l'animation dans le sprite*/

    this->dimCoordEcran.x = 0; /*coordonn�es d'affichage dans l'�cran*/
    this->dimCoordEcran.y = 0;
}

void Shape::setDimCoordEcranX(int x) { this->dimCoordEcran.x = x; }
void Shape::setDimCoordEcranY(int y){ this->dimCoordEcran.y = y; }
void Shape::setDimCoordEcranW(int w) { this->dimCoordEcran.w = w; }
void Shape::setDimCoordEcranH(int h){ this->dimCoordEcran.h = h; }
int Shape::getDimCoordEcranX() { return this->dimCoordEcran.x; }
int Shape::getDimCoordEcranY() { return this->dimCoordEcran.y; }
int Shape::getDimCoordEcranW() { return this->dimCoordEcran.w; }
int Shape::getDimCoordEcranH() { return this->dimCoordEcran.h; }

void Shape::setDimCoordSpriteX(int x) { this->dimCoordSprite.x = x; }
void Shape::setDimCoordSpriteY(int y){ this->dimCoordSprite.y = y; }
void Shape::setDimCoordSpriteW(int w) { this->dimCoordSprite.w = w; }
void Shape::setDimCoordSpriteH(int h){ this->dimCoordSprite.h = h; }
int Shape::getDimCoordSpriteX() { return this->dimCoordSprite.x; }
int Shape::getDimCoordSpriteY() { return this->dimCoordSprite.y; }
int Shape::getDimCoordSpriteW() { return this->dimCoordSprite.w; }
int Shape::getDimCoordSpriteH() { return this->dimCoordSprite.h; }

void Shape::setSprite(SDL_Surface* sprite) { this->sprite = sprite; }
