#include "Header.h"

Player::Player() : Shape()
{
    this->direction = SOUTH;

    this->xVel = 0;
    this->yVel = 0;

    this->speed = DEFAULT_SPEED;

    this->nbBomb = 5;
}

Player::Player(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb)
{}

Player::~Player()
{
}

void Player::show(SDL_Surface *dest)
{
    //SDL_Surface *s;
    //s = SDL_CreateRGBSurface(0,box.w , box.h , SCREEN_BPP, 0,255,255,0);
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
    //apply_surface(box.x , box.y , s, dest, NULL );
}

void Player::MoveUp()
{
    direction = NORTH;
    updateSprite();
    dimCoordEcran.y -= yVel;
    updateBox();
}

void Player::MoveDown()
{
    direction = SOUTH;
    updateSprite();
    dimCoordEcran.y += yVel;
    updateBox();
}

void Player::MoveLeft()
{
    direction = WEST;
    updateSprite();
    dimCoordEcran.x -= xVel;
    updateBox();
}

void Player::MoveRight()
{
    direction = EAST;
    updateSprite();
    dimCoordEcran.x += xVel;
    updateBox();
}

void Player::updateSprite()
{
    dimCoordSprite.y = direction * dimCoordSprite.h;
    if ((dimCoordSprite.x += dimCoordSprite.w) >= (dimCoordSprite.w * nbSprites))
        dimCoordSprite.x = 0;
}

void Player::resetSprite()
{
    direction = SOUTH;
    dimCoordSprite.y = direction * dimCoordSprite.h;
    dimCoordSprite.x = 0;
}

void Player::updateBox()
{
	this->box.x = this->dimCoordEcran.x;
	this->box.y = this->dimCoordEcran.y + TILE_HEIGHT - 10;
	this->box.w = this->dimCoordSprite.w;
	this->box.h = this->dimCoordSprite.h - TILE_HEIGHT + 10;
}

void Player::dropBomb()
{
    this->nbBomb--;
}

void Player::pickBomb()
{
    this->nbBomb++;
}


