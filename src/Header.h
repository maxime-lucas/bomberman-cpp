#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

// Bibliothèques standards
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Bibliothèques SDL
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

// Inclusions diverses
#include "Functions.h"
#include "Classes.h"

// Constantes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

const int NORTH = 0;
const int SOUTH = 1;
const int WEST = 2;
const int EAST = 3;

const int DEFAULT_SPEED = 600;

const int FRAMES_PER_SECOND = 30;

#endif
