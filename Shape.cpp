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
