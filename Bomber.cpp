#include "Header.h"

Bomber::Bomber() : Figure()
{
    this->sprite = IMG_Load("img/sprite-player/player1.png");
    this->nbSprites = 6;

    this->dimCoordSprite.w = 40;
    this->dimCoordSprite.h = 67;
    this->dimCoordSprite.x = 0;
    this->dimCoordSprite.y = this->direction * this->dimCoordSprite.h;
}

Bomber::~Bomber()
{
}

void Bomber::show(SDL_Surface * dest)
{
    Figure::show(dest);
}
