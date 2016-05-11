#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

	#include <stdio.h>
	#include <stdlib.h>

	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <SDL/SDL_ttf.h>
	#include <SDL/SDL_getenv.h>

	// Attributs de l'�cran : Largeur, Hauteur, Profondeur de couleur
	const int SCREEN_WIDTH = 850;
	const int SCREEN_HEIGHT = 650;
	const int SCREEN_BPP = 32;

	// Constantes pour l'orientation du personnage
	const int NORTH = 0;
	const int SOUTH = 1;
	const int WEST = 2;
	const int EAST = 3; 

	// Vitesse de d�placement, par d�faut, du personnage ( en px / sec )
	const int DEFAULT_SPEED = 300;

	// Nombre d'images devant s'afficher par seconde
	const int FRAMES_PER_SECOND = 30;

	// Constantes pour les tuiles
	const int TILE_WIDTH = 50;
	const int TILE_HEIGHT = 50;
	const int TOTAL_TILES = 221;
	const int NB_TILES_WIDTH = 17;
	const int NB_TILES_HEIGHT = 13;
	const int TILE_GRASS = 0;
	const int TILE_WALL = 2;
	const int TILE_BRICK = 1;
	const int TILE_WOOD = 3;
	
	// Constantes pour le jeu
	const int NB_PLAYERS = 2;
	
	const int MS_PER_UPDATE = 50;
	
	#include "Classes.h"
	#include "Functions.h"
#endif // HEADER_H_INCLUDED
