#include "Header.h"

void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &offset );
}
