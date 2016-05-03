#include "Header.h"
#include "Classes.h"
Figure::Figure() : Shape()
{
	this->direction = 1; // 1: SOUTH => Pour qu'il soit fasse à nous;
	
	this->xVel = 0;
	this->yVel = 0;
	
	this->speed = DEFAULT_SPEED;
}

Figure::Figure(SDL_Surface* s,SDL_Rect r,int nb) : Shape(s,r,nb) {}

Figure::~Figure() {}

void Figure::show(SDL_Surface *dest)
{
	apply_surface( dimCoordShape.x, dimCoordShape.y, sprite, dest, &dimCoordSprite );
	
	printf("dimCoordShape :\n");
	printf("x : %d\n", dimCoordShape.x);
	printf("y : %d\n", dimCoordShape.y);
	
	printf("dimCoordSprite :\n");
	printf("x : %d\n", dimCoordSprite.x);
	printf("y : %d\n", dimCoordSprite.y);
	printf("w : %d\n", dimCoordSprite.w);
	printf("h : %d\n", dimCoordSprite.h);
	
	printf("direction : %d\n", direction);
	printf("xVel : %d\n", xVel);
	printf("yVel : %d\n", yVel);
	printf("speed : %d\n", speed);
}
