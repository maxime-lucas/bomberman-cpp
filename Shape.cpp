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
