#include "Header.h"

Button::Button() : Shape() {}
Button::Button(SDL_Surface* s,SDL_Rect r,int nb) : Shape(s,r,nb)
{
	hovered = false;
}

Button::~Button() {}

void Button::show(SDL_Surface *dest)
{
	if(this->hovered)
		dimCoordSprite.x = dimCoordSprite.w;
	else
		dimCoordSprite.x = 0;
		
	apply_surface( dimCoordEcran.x, dimCoordEcran.y, sprite, dest, &dimCoordSprite );
}

void Button::toString()
{
	printf("x : %d\n", dimCoordEcran.x);
	printf("y : %d\n", dimCoordEcran.y);
	printf("sprite : %p\n", sprite);
}

void Button::setHovered() { this->hovered = true; }
void Button::unsetHovered() { this->hovered = false; }
bool Button::isHovered(int MouseX, int MouseY)
{
	if( ( MouseX > this->getDimCoordEcranX() ) && ( MouseX < (this->getDimCoordEcranX() + this->getDimCoordSpriteW()) ) && ( MouseY > this->getDimCoordEcranY() ) && ( MouseY < (this->getDimCoordEcranY() + this->getDimCoordSpriteH()) ) )
		return true;
	return false;	
}
