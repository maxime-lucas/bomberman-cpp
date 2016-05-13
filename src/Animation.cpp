/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animation.cpp
 * Author: maxime
 * 
 * Created on 13 mai 2016, 12:47
 */

#include "Header.h"
Animation::Animation()
{
    this->currentFrame = 0;
}

Animation::Animation(char* str, int nb)
{
    this->nbFrames = nb;
    this->path = str;
    this->currentFrame = 0;
}

Animation::~Animation()
{
    SDL_FreeSurface(img);
}

void Animation::render(SDL_Surface* ecran)
{
    char filepath[64];
    sprintf(filepath, path.c_str() , currentFrame);
    img = IMG_Load( filepath );
    apply_surface( 0, 0, img, ecran, NULL );
}

void Animation::nextFrame()
{
    currentFrame++;
}

void Animation::resetFrames()
{
    currentFrame = 0;
}



