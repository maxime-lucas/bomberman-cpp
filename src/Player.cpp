#include "Header.h"

Player::Player() : Shape()
{
    cout << "Constructeur Player" << endl;
    
    this->direction = SOUTH;

    this->xVel = 0;
    this->yVel = 0;

    this->speed = DEFAULT_SPEED;

    this->nbBomb = 100;
    if( DEBUG_MODE )
        this->nbBomb += 100;

    this->sprite = IMG_Load("img/sprites/player1.png"); 
    this->nbSprites = 6; 

    this->dimCoordSprite.w = 40;
    this->dimCoordSprite.h = 67;
    this->dimCoordSprite.x = 0;
    this->dimCoordSprite.y = this->direction * this->dimCoordSprite.h;

    this->alive = true;
}

Player::Player(SDL_Surface* s, SDL_Rect r , int nb) : Shape(s,r,nb)
{}

Player::~Player()
{
    cout << "Destructeur Player" << endl;
}

Player& Player::operator=( const Player& p )
{
    if ( this != &p )
    {
        SDL_FreeSurface(sprite);
        sprite = p.sprite;
        
        xVel = p.xVel;
        yVel = p.yVel;
	speed = p.speed;
	direction = p.direction;
	box.x = p.box.x;
        box.y = p.box.y;
        box.w = p.box.w;
        box.h = p.box.h;
	nbBomb = p.nbBomb;
        alive = p.alive;
        dimCoordSprite.x = p.dimCoordSprite.x;
        dimCoordSprite.y = p.dimCoordSprite.y;
        dimCoordSprite.w = p.dimCoordSprite.w;
        dimCoordSprite.h = p.dimCoordSprite.h;
	dimCoordEcran.x = p.dimCoordEcran.x;
        dimCoordEcran.y = p.dimCoordEcran.y;
        dimCoordEcran.w = p.dimCoordEcran.w;
        dimCoordEcran.h = p.dimCoordEcran.h;
        nbSprites = p.nbSprites;
        
    }
    return (* this ) ;
}

void Player::show(SDL_Surface *dest)
{	
    if( DEBUG_MODE )
    {
        SDL_Surface *s;
        s = SDL_CreateRGBSurface(0,box.w , box.h , SCREEN_BPP, 0,255,255,0);
        apply_surface(box.x , box.y , s, dest, NULL );   
    }
    
    apply_surface(dimCoordEcran.x , dimCoordEcran.y , sprite, dest ,&dimCoordSprite);
    
    
    
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


