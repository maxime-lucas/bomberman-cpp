
#include "Header.h"
Explosion::Explosion(int x, int y) : Shape()
{
    this->sprite = IMG_Load("img/sprites/explosion.png"); /*chargement de l'image du personnage*/
    this->nbSprites = 1; /*nb d'images pour l'animation du perso*/

    this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
    this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
    this->dimCoordSprite.x = 100; /*coordonnée x d'affichage à l'écran de départ*/
    this->dimCoordSprite.y = 100; /*coordonnée y de départ*/

    this->dimCoordScreen.x = x;
    this->dimCoordScreen.y = y;
 
    this->step = 1;
    this->strength = 3;
    this->duration = 1000;
    this->dateOfEnd = SDL_GetTicks() + duration;
    
    SDL_Rect box;
    box.x = x;
    box.y = y;
    box.w = TILE_WIDTH;
    box.h = TILE_HEIGHT;
    
    collisionBoxes.push_back(box);
}

Explosion::~Explosion()
{
}

void Explosion::show(SDL_Surface * dest)
{
    for(int i = 0; i < collisionBoxes.size() ; i++)
    {
        SDL_Rect box = collisionBoxes[i];
        
        if( DEBUG_MODE )
        {
            SDL_Surface *s;
            s = SDL_CreateRGBSurface(0,box.w , box.h , SCREEN_BPP, 0,255,255,0);
            apply_surface(box.x , box.y , s, dest, NULL );   
        }
                
        apply_surface(box.x , box.y , sprite, dest ,&dimCoordSprite);
        
    }
}

void Explosion::nextStep()
{
    this->step++;
}

void Explosion::nextSprite()
{
	switch(step)
	{
		case 1 :
			this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
			this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
			this->dimCoordSprite.x = 100; /*coordonnée x d'affichage à l'écran de départ*/
			this->dimCoordSprite.y = 100; /*coordonnée y de départ*/
			break;
			
		case 2 :
			this->dimCoordSprite.w = 50; /*largeur d'une image de l'animation*/
			this->dimCoordSprite.h = 50; /*hauteur d'une image de l'animation*/
			this->dimCoordSprite.x = 100; /*coordonnée x d'affichage à l'écran de départ*/
			this->dimCoordSprite.y = 100; /*coordonnée y de départ*/
			break;
		case 3 :
			break;
	}
}

void Explosion::resetSprite()
{
}

void Explosion::evolueUp()
{
	if( step != 1 )
	{
		SDL_Rect newBox;
		
		newBox.x = dimCoordScreen.x ;
		newBox.y = dimCoordScreen.y - ( step - 1 ) * TILE_HEIGHT ;
		newBox.w = TILE_WIDTH;
		newBox.h = TILE_HEIGHT;
                
                collisionBoxes.push_back(newBox);
	}
}

void Explosion::evolueDown()
{
	if( step != 1 )
	{
		SDL_Rect newBox;
		newBox.x = dimCoordScreen.x ;
		newBox.y = dimCoordScreen.y + ( step - 1 ) * TILE_HEIGHT ;
                newBox.w = TILE_WIDTH;
		newBox.h = TILE_HEIGHT;
                
                collisionBoxes.push_back(newBox);
	}
}

void Explosion::evolueLeft()
{
	if( step != 1 )
	{
		SDL_Rect newBox;
		newBox.x = dimCoordScreen.x - ( step - 1 ) * TILE_WIDTH ;
		newBox.y = dimCoordScreen.y ;
                newBox.w = TILE_WIDTH;
		newBox.h = TILE_HEIGHT;
                
                collisionBoxes.push_back(newBox);
	}
}

void Explosion::evolueRight()
{
	if( step != 1 )
	{
		SDL_Rect newBox;
		newBox.x = dimCoordScreen.x + ( step - 1 ) * TILE_WIDTH ;
		newBox.y = dimCoordScreen.y ;
                
                collisionBoxes.push_back(newBox);
	}
}


