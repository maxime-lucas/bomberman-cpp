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
AnimationPlayer::AnimationPlayer() : Animation()
{
}

AnimationPlayer::AnimationPlayer(char* str, int index, int nb) : Animation(str, nb)
{
    this->indexPlayer = index;
}

AnimationPlayer::~AnimationPlayer()
{
}

void AnimationPlayer::render(SDL_Surface* ecran)
{
    char filepath[64];
    sprintf(filepath, path.c_str() , indexPlayer, currentFrame);
    img = IMG_Load( filepath );
    apply_surface( 0, 0, img, ecran, NULL );
}
 