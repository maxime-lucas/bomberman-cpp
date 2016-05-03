#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <fmodex/fmod.h>
#include <SDL_ttf.h>
#include "Classes.h"
#include "Functions.h"

const int SCREEN_WIDTH = 640; //constante largeur écran
const int SCREEN_HEIGHT = 480; //constante hauteur écran
const int SCREEN_BPP = 32; //constante profondeur couleur

const int NORTH = 0;
const int SOUTH = 1;
const int WEST = 2;
const int EAST = 3;

const int DEFAULT_SPEED = 100;


#endif // HEADER_H_INCLUDED
