#include "Header.h"

Shape::Shape() /*constructeur par d�faut*/
{
    this->dimCoordScreen.x = 0; /*position d'affichage X dans �cran*/
    this->dimCoordScreen.y = 0; /*position d'affichage Y dans �cran*/
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

    this->dimCoordScreen.x = 0; /*coordonn�es d'affichage dans l'�cran*/
    this->dimCoordScreen.y = 0;
}

void Shape::setDimCoordScreenX(int x) { this->dimCoordScreen.x = x; }
void Shape::setDimCoordScreenY(int y){ this->dimCoordScreen.y = y; }
void Shape::setDimCoordScreenW(int w) { this->dimCoordScreen.w = w; }
void Shape::setDimCoordScreenH(int h){ this->dimCoordScreen.h = h; }
int Shape::getDimCoordScreenX() { return this->dimCoordScreen.x; }
int Shape::getDimCoordScreenY() { return this->dimCoordScreen.y; }
int Shape::getDimCoordScreenW() { return this->dimCoordScreen.w; }
int Shape::getDimCoordScreenH() { return this->dimCoordScreen.h; }

void Shape::setDimCoordSpriteX(int x) { this->dimCoordSprite.x = x; }
void Shape::setDimCoordSpriteY(int y){ this->dimCoordSprite.y = y; }
void Shape::setDimCoordSpriteW(int w) { this->dimCoordSprite.w = w; }
void Shape::setDimCoordSpriteH(int h){ this->dimCoordSprite.h = h; }
int Shape::getDimCoordSpriteX() { return this->dimCoordSprite.x; }
int Shape::getDimCoordSpriteY() { return this->dimCoordSprite.y; }
int Shape::getDimCoordSpriteW() { return this->dimCoordSprite.w; }
int Shape::getDimCoordSpriteH() { return this->dimCoordSprite.h; }

void Shape::setSprite(SDL_Surface* sprite) { this->sprite = sprite; }
