#include "Header.h"

Shape::Shape() /*constructeur par défaut*/
{
    this->dimCoordEcran.x = 0; /*position d'affichage X dans écran*/
    this->dimCoordEcran.y = 0; /*position d'affichage Y dans écran*/
    this->sprite = NULL; /*image de la Shape, ici NULL*/
    this->nbSprites = 1; /*nb d'images pour animation , ici 1 seule*/
}

Shape::~Shape() /*destructeur*/
{
}

Shape::Shape(SDL_Surface* s, SDL_Rect r , int nb) /*constructeur paramétré*/
{
    this->sprite = s; /*image passée en paramètre*/
    this->dimCoordSprite = r; /*coordonnées et taille image dans sprite, passé en paramètres*/
    this->nbSprites = nb; /*nb d'iamges pour l'animation dans le sprite*/

    this->dimCoordEcran.x = 0; /*coordonnées d'affichage dans l'écran*/
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
