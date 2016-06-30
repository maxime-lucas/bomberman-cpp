/* 
 * File:   Animation.cpp
 * Author: maxime
 * 
 * Composition :
 * - Forme canonique (Constructeur, Destructeur, Recopie, Surcharge=)
 * 
 * Created on 13 mai 2016, 12:47
 */

#include "Header.h"

/**
 * Constructeur par défaut
 * - Place l'image actuelle au début (0)
 */
Animation::Animation()
{
    this->path = "";
    this->nbFrames = 0;
    this->currentFrame = 0;
}

/**
 * Constructeur paramétré
 * @param str   Chemin vers l'image
 * @param nb    Nombre d'images de l'animation
 */
Animation::Animation(string str, int nb)
{
    this->nbFrames = nb;
    this->path = str;
    this->currentFrame = 0;
}

Animation::Animation( const Animation &a )
{
    this->nbFrames = a.nbFrames;
    this->path = a.path;
    this->currentFrame = 0;       
}

/**
 * Destructeur
 * - Vide l'image stockée dans'img'
 */
Animation::~Animation()
{
    SDL_FreeSurface(img);
}

/**
 * Rendu de la frame actuelle
 * @param ecran Ecran de destination, dans lequel on doit faire le rendu de l'image
 */
void Animation::render(SDL_Surface* ecran)
{
    // Désallocation de l'image précédente
    SDL_FreeSurface(img);
    
    // Préparation du chemin de l'image
    char filepath[64];
    sprintf(filepath, path.c_str() , currentFrame);
    
    // Chargement de l'image
    img = IMG_Load( filepath );
    
    // Collage de l'image dans l'écran de destination
    apply_surface( 0, 0, img, ecran, NULL );
}

/**
 * Passer à la frame suivante
 */
void Animation::nextFrame()
{
    currentFrame++;
}

/**
 * Remise à 0 de la frame actuelle
 */
void Animation::resetFrames()
{
    currentFrame = 0;
}



